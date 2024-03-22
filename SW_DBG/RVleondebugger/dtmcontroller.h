#ifndef DTMCONTROLLER_H
#define DTMCONTROLLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QThread>
enum DTMSTATES {
    IDLE,WAIT_DMACTIVE,WAIT_DMINACTIVE,WAIT_HALTREQ,WAIT_RESREQ,CONFIRM_RESET,CLEAR_ERROR,
    CHECK_ERROR,START_READ_GPR,START_READ_PIPELINE,WAIT_READ_DCSR,WAIT_READ_CYCLE,WAIT_READ_CYCLEH,
    WAIT_READ_INSTRET,WAIT_READ_INSTRETH,WAIT_READ_OTHER,NEXT_READ_GPR,NEXT_READ_PIPELINE,
    NEXT_READ_OTHER,READ_DATA0
};

enum DMCOMMAND {
    DATA0rd = 0x04, DMCONTROLrd = 0x10, DMSTATUSrd = 0x11, ABSTRACTCSrd = 0x16, COMMANDrd = 0x17, AUTOEXECrd = 0x18,
    DATA0wr = 0x84, DMCONTROLwr = 0x90, DMSTATUSwr = 0x91, ABSTRACTCSwr = 0x96, COMMANDwr = 0x97, AUTOEXECwr = 0x98
};

struct DMState {
    bool DMActive  = false; // 1: DM está listo para usarse;  0: DM en reset
    bool halted    = false; // 1: CPU en estado Debug;        0: CPU en estado Running
    bool resumeack = false; // 1: resumereq resultó efectivo; 0: No se ha hecho resumereq ó hubo un problema al realizarlo.
    bool ndmreset  = false; // 1: reset del CPU en ejecución; 0: El CPU no está en reset
    bool haverst   = false; // 1: Se realizó un ndmreset;     0: No ha ocurrido nada.
    bool cmderr    = false; // 1: Error al ejecutar command;  0: No ha ocurrido ningún error
    bool autoexec  = false; // 1: Autoejecución de command;   0: command no se ejecuta al interactuar con DATA0
    bool onestep   = false; // 1: onestep readed              0: No se aplica el onestep
};

struct RCVREGS {
    quint8 RDcmmd;
    DTMSTATES ope;
};

class DTMController : public QObject
{
    Q_OBJECT
public:
    explicit DTMController(QObject *parent = nullptr);

    bool connectPort();
    void disconnectPort();
    bool ActivarDM();
    bool DesactivarDM();
    bool HaltCore();
    bool ResumeCore();
    bool RstCore(bool InstantDeActRst=false,bool haltAfterRst=false);
    bool SendClrError();
    bool Autoexec(bool act);
    bool ReadRegs(quint16 regno, bool fromInit = true, bool postinc = false);
    bool ActiveOneStep(bool Activate);
    bool RDData0(bool forReadRegs=false,quint16 regno=0x0000);
    ~DTMController();

    static QByteArray WRDmcontrol(bool on = true, bool haltreq = false,
                                  bool resreq = false, bool ndmrst = false,
                                  bool haltOnRst = false, bool DeactHaltOnRst = false);
    static QByteArray WRData0(uint32_t data);
    static QByteArray WRCommand(uint16_t regno, bool write, bool transfer, bool postincrement);
    static QByteArray WRAbstractauto(bool autoexec);
    static QByteArray WRClrCmdError();

    void ActEstadoDM();

    inline bool isDMActive(){ return DbgEstado.DMActive;}
    inline static bool isDMActive(QByteArray dmcontrol){
        return ((dmcontrol[0] & 0x01) == (char) 0x01);
    }

    inline bool isHalted() { return DbgEstado.halted;}
    inline static bool isHalted(QByteArray dmstatus){
        return (dmstatus[1] == (char) 0x03);
    }

    inline bool isRunning(){ return !DbgEstado.halted;}
    inline static bool isRunning(QByteArray dmstatus){
        return (dmstatus[1] == (char) 0x0C);
    }

    inline bool isOnRst(){ return DbgEstado.ndmreset;}
    inline static bool isOnRst(QByteArray dmstatus){
        return ((dmstatus[1] & 0xf0) == (char) 0x30);
    }
    inline bool ErrOnComm(){ return DbgEstado.cmderr;}
    inline static bool noErrComm(QByteArray abstractcs){
        return ((abstractcs[1] & 0x07) == (char) 0x00); // No debe haber error.
    }
    inline static bool unsuppErrComm(QByteArray abstractcs){
        return ((abstractcs[1] & 0x07) == (char)  0x02); // Error por comando no soportado
    }
    inline static bool unavalErrComm(QByteArray abstractcs){
        return ((abstractcs[1] & 0x07) == (char) 0x04); // Error por CPU en Estado de ejecución o de reset
    }
    inline bool isAutoExecComm(){ return DbgEstado.autoexec;}
    inline bool isOneStepActive() { return DbgEstado.onestep;}

    inline void RstState(){_Operation = IDLE;}
    bool waitForReadComm();

signals:
    void DMConnected(bool y); // Avisa si el DM está conectado(true) o desconectado (false).
    void dataReceived(QByteArray b,quint8 c,qint16 s);
    void DMRunning(bool y);
    void dataIsDATA0(QByteArray b, qint16 s);
    void DMActiveChanged(bool y);
    void haltedChanged(bool y);
    void ndmresetChanged(bool y);

public slots:

private slots:
    void dataReady();
    void ChangeState(QByteArray b, quint8 c, quint16 context);
    //void

private:
    // Estado
    bool FTDI_Disponible;
    DMState DbgEstado;
    DTMSTATES _Operation = IDLE;

    QSerialPort *_serialPort; // puerto serial
    QByteArray comando; // comando actual
    QByteArray ReceiveData; // Datos recibidos...
    qint64 write(QByteArray data, DTMSTATES ope=IDLE);
    // Pila de comandos escritos
    QList<RCVREGS> CmmdToRead;
    quint32 data0;


    // Identificadores de mi dispositivo FTDI
    static const quint16 VendorID  = 0x0403;
    static const quint16 ProductID = 0x6001;

};


#endif // DTMCONTROLLER_H
