#include "dtmcontroller.h"

//-- Constructor
DTMController::DTMController(QObject *parent) :
    QObject(parent), FTDI_Disponible(false)
{
    _serialPort = new QSerialPort(this);
    //_serialPort->setPortName("/dev/tnt1");
}

bool DTMController::connectPort()
{
    // Identificar puertos disponibles. Si alguno coincide con el VendorID y el ProductID, usar como puerto.
    for (auto port : QSerialPortInfo::availablePorts()){
        auto pname = port.portName();
        auto pPID  = port.hasProductIdentifier() ? port.productIdentifier() : 0;
        auto pVID  = port.hasVendorIdentifier()  ? port.vendorIdentifier()  : 0;
        qDebug() << "DTMController::connect--------------";
        qDebug() << port.systemLocation() << "-"<< pname << pPID << pVID << port.isBusy();
        if ( (pVID == VendorID) && (pPID == ProductID) ) {
            // Si el puerto es distinto: cerrarlo, si está abierto, y cambiarlo de puerto.
            if (pname != _serialPort->portName()) {
                if (_serialPort->isOpen()){
                    _serialPort->close();
                }
                _serialPort->setPortName(port.systemLocation()); // Establece puerto
            }
            FTDI_Disponible = true;
            break;
        }
    }
    qDebug() << "FTDI: " << FTDI_Disponible;
    // Si FTDI_Disponible y puerto serial abre...
    if (FTDI_Disponible && (_serialPort->isOpen() ||
                            _serialPort->open(QIODevice::ReadWrite)))
    {
        _serialPort->setBaudRate(QSerialPort::Baud115200);
        _serialPort->setDataBits(QSerialPort::Data8);
        _serialPort->setParity(QSerialPort::NoParity);
        _serialPort->setStopBits(QSerialPort::OneStop);

        QObject::connect(_serialPort, &QSerialPort::readyRead,
                         this, &DTMController::dataReady,Qt::UniqueConnection);
        emit DMConnected(true);
        ActEstadoDM(); // Actualiza estados!
        if (isDMActive()) {
            qDebug() << "El DM ya está activo. Listo para usarse";
            //emit DMActive(true);
        }
    }
    return _serialPort->isOpen();
}
void DTMController::disconnectPort() {
    if (_serialPort->isOpen())  {
        _serialPort->close();
        QObject::disconnect(_serialPort, &QSerialPort::readyRead,
                            this, &DTMController::dataReady);
    }
}

//-- Resolución de Escrituras y lectura
qint64 DTMController::write(QByteArray data, DTMSTATES ope)
{
    if(_serialPort->isOpen()) { //Si no está abierto
        for (int i = 0; i < data.size(); i++) {
            quint8 byte = data[i];
            if ((byte & 0x80) == 0x80){ // Operacion de escritura
                i += 4; // Nos saltamos tres espacios.
            } else {
                RCVREGS p = {byte,ope};
                CmmdToRead.append(p); // Guardamos comando a leer
            }
        }
        _serialPort->write(data);
        if (_serialPort->waitForBytesWritten(200)){
            return data.size(); // Si escribió
        }
        return -1;
    }
    emit DMConnected(false); // mandar señal de que DM está desconectado
    return -1;
}

bool DTMController::waitForReadComm()
{
    if(_serialPort->isOpen()) {
        if (_serialPort->waitForReadyRead(100)) {
            qDebug() << "Bytes recien recibidos:" << ReceiveData.size();
            if (ReceiveData.size() < 4) {
                _serialPort->waitForReadyRead(100);
                qDebug() << "Ahora hay" << ReceiveData.size() << "bytes recibidos";
            }
            while (ReceiveData.size() >= 4) {
                QByteArray rcvd = QByteArray(ReceiveData.data(),4); // Lee de 4 bytes en 4
                ReceiveData.remove(0,4); // Removemos los primeros 4 bytes...

                quint32 data = 0; // inicializa a cero
                memcpy(reinterpret_cast <char*>(&data), rcvd.data(), rcvd.size()); // totalmente opcional, solo para qDebug ahorita.
                RCVREGS readed = CmmdToRead[0];
                CmmdToRead.pop_front(); // Se elimina el comando de lectura más reciente
                qDebug() << "DTMController::dataReady----------";
                qDebug() << "Estado:" << readed.ope;
                qDebug() << QString("comando: 0x%1").arg(readed.RDcmmd, 2, 16, QLatin1Char('0'))
                         << QString("data: 0x%1").arg(data, 8, 16, QLatin1Char('0'));
                qDebug() << "Bytes faltantes:" << ReceiveData.size();
                qDebug() << "Comandos que faltan: " << CmmdToRead.size();

                ChangeState(rcvd,readed.RDcmmd,readed.ope);
            }
             _Operation = IDLE;
             return true;
        }
    }
    emit DMConnected(false);
    return false;
}

void DTMController::dataReady() // SLOT para la señal del QSerialPort
{
    if(_serialPort->isOpen()) {
        if (_serialPort->bytesAvailable() > 0) {
            ReceiveData.append(_serialPort->readAll());
        }
    }
}

void DTMController::ActEstadoDM() // TODO cambiar nombre
{
    if (_serialPort->isOpen()) {
        write(QByteArray(1,DMCONTROLrd));
        waitForReadComm();
        write(QByteArray(1,DMSTATUSrd));
        waitForReadComm();
        write(QByteArray(1,ABSTRACTCSrd));
        waitForReadComm();
        write(QByteArray(1,AUTOEXECrd));
        waitForReadComm();
        return;
    }

    emit DMConnected(false);
    return;
}



void DTMController::ChangeState(QByteArray b,quint8 comm,quint16 context) {
    // La información recibida:
    DMState Previo = DbgEstado;
    switch(comm){
    case DMCONTROLrd: {
        DbgEstado.DMActive = isDMActive(b);
        DbgEstado.ndmreset = ((b[0] & 0x02) == 0x02);
        break;
    }
    case DMSTATUSrd: {
        DbgEstado.halted = !isRunning(b);
        DbgEstado.haverst = ((b[2] & 0x0C) == 0x0c);
        DbgEstado.resumeack = ((b[2] & 0x02) == 0x02);
        DbgEstado.ndmreset = isOnRst(b);
        break;
    }
    case ABSTRACTCSrd: {
        DbgEstado.cmderr = !noErrComm(b);
        break;
    }
    case AUTOEXECrd: {
        DbgEstado.autoexec = ((b[0] & 0x01) == 0x01);
        break;
    }
    case DATA0rd: {
        if (context == WAIT_READ_DCSR) {
            DbgEstado.onestep = ((b[0] & 0x04) == 0x04);
        }
        emit dataIsDATA0(b, context);
        break;
    }
    }
    if (Previo.DMActive != DbgEstado.DMActive) {
        emit DMActiveChanged(DbgEstado.DMActive);
    }
    if (Previo.halted != DbgEstado.halted) {
        emit haltedChanged(DbgEstado.halted);
    }
    if (Previo.ndmreset != DbgEstado.ndmreset) {
        emit ndmresetChanged(DbgEstado.ndmreset);
    }

}

// Envia comando para activar el DM. (No activa el debug Mode)
// Devuelve True si la operación se efectúa y recibe DMActive
bool DTMController::ActivarDM()
{
    if (_serialPort->isOpen()) {
        comando = WRDmcontrol(); // 0x90
        comando.append(DMCONTROLrd); // Revisar estado del DMActive
        _Operation = WAIT_DMACTIVE;
        write(comando,_Operation);
        if (waitForReadComm()){
            return isDMActive();
        }
    }
    emit DMConnected(false);
    return false;
}
// Devuelve True si lee del puerto serial y si DMActive se desactiva
bool DTMController::DesactivarDM()
{
    if (_serialPort->isOpen()) {
        // Mandamos un NDMRST que se activará por un ciclo, cuando dmactive sea 0,
        comando = WRDmcontrol(false,false,false,true);
        comando.append(DMSTATUSrd);   // (char) 0x10 //
        _Operation = WAIT_DMINACTIVE;
        write(comando,_Operation);
        if (waitForReadComm()){
            ActEstadoDM();
        }
        emit DMConnected(false);
        return !isDMActive();

    }
    emit DMConnected(false);
    return false;
}

// Envía comando que detiene el procesador
bool DTMController::HaltCore()
{
    if (_serialPort->isOpen()) {
        comando = WRDmcontrol(true,true);
        _Operation = WAIT_HALTREQ;
        write(comando, _Operation);

        comando.clear();
        QThread::msleep(10); // Esperamos lo mínimo posible para que cargue la memoria
        comando.append(DMSTATUSrd); // Leer estado
        _Operation = WAIT_HALTREQ;
        write(comando, _Operation);
        if (waitForReadComm()){
            return isHalted();
        }
    }

    emit DMConnected(false);
    return false;
}

// Envía comando que despausa al procesador
bool DTMController::ResumeCore()
{
    if (_serialPort->isOpen()) {
        comando = WRDmcontrol(true,false,true);
        _Operation = WAIT_RESREQ;
        write(comando, _Operation);

        comando.clear();
        QThread::msleep(10); // Esperamos lo mínimo posible para que cargue
        comando.append(DMSTATUSrd); // leer estado
        _Operation = WAIT_RESREQ;
        write(comando, _Operation);
        if (waitForReadComm()){
            if (isOneStepActive()) {
                return isHalted();
            }
           return isRunning();
        }
    }
    emit DMConnected(false);
    return false;
}

// Envía comando para activar señal de reinicio del procesador.
// si InstantDeActRst==true, la señal de reinicio se apaga instantaneamente.
// Si InstantDeActRst y haltAferRst son ambos true, apenas el reinicio termine, genera un haltreq
bool DTMController::RstCore(bool InstantDeActRst, bool haltAfterRst)
{
    if (_serialPort->isOpen()) {
        comando = WRDmcontrol(true,false,false,true,true,haltAfterRst); // ndmrst = 1
        if (InstantDeActRst){ // Si se quiere reiniciar instantaneamente.
            comando.append(WRDmcontrol(true)); // Desactiva ndmrst
        }
        write(comando,_Operation); // Mandar comando de reset, sin confirmar valores de DMSTATUS
        if (InstantDeActRst && haltAfterRst) { // S
            QThread::msleep(20); // Esperamos 20 mseg para confirmar lectura
        } // else
        comando.clear();
        if (haltAfterRst) { // Desactivamos haltAfterRst si fue activado
            comando.append(WRDmcontrol(true,false,false,false,true,false));
        }
        comando.append(DMSTATUSrd); // Esperamos a confirmar
        write(comando,CONFIRM_RESET);

        if (waitForReadComm()) { // Esperamos a recibir la informacion
            if (InstantDeActRst){
                qDebug() << "UHHHHH: " << isHalted() << !isOnRst();
                if (haltAfterRst)  return isHalted() && !isOnRst(); // y si se generó un halt
                else               return !isOnRst();
            } else {
                return isOnRst(); // o, si no se desactiva el reset, revisar que esté en rst.
            }
        }

    }
    emit DMConnected(false);
    return false;
}

// Manda señal para limpiar señal de error.
bool DTMController::SendClrError()
{
    if (_serialPort->isOpen()) {
        comando = WRClrCmdError(); // Clear error ...
        comando.append(ABSTRACTCSrd); // Leer...
        _Operation = CLEAR_ERROR;
        write(comando,_Operation);
        if (waitForReadComm()){
            return !ErrOnComm();
        }
    }
    emit DMConnected(false);
    return false;
}

bool DTMController::Autoexec(bool act) {
    if (_serialPort->isOpen()) {
        comando = WRAbstractauto(act);
        comando.append(AUTOEXECrd); // Verificamos
        write(comando,CHECK_ERROR);
        // confirmado que actualizará autoexec;
        if (waitForReadComm()){
            return (act == isAutoExecComm());
        }
    }
    emit DMConnected(false);
    return false;
}


// Lee los registros del procesador, mediante comando abstracto.
bool DTMController::ReadRegs(quint16 regno, bool fromInit, bool postinc)
{
    if (_serialPort->isOpen()) { // Comprobación del puerto
        if (ErrOnComm()){ // Si hay un error, lo corregimos
            if (!SendClrError()){
                return false;
            }
        }
        if (fromInit && !isAutoExecComm()) { // Activamos si es necesario.
            if (!Autoexec(true)) {
                return false;
            }
        }
        // Enviar comando de lectura:
        quint16 mask = fromInit ? 0x001f : 0x0000;
        comando = WRCommand(regno & ~mask,false,true,postinc);
        comando.append(DATA0rd); // lectura de DATA0, donde el valor del registro se guarda
        // Generar contexto a la lectura de registro DATA0...
        if (fromInit){ // Eliminar esto (?)
            switch (regno & 0xf000) {
                case 0x1000: {_Operation = START_READ_GPR; break;}
                case 0xC000: {_Operation = START_READ_PIPELINE; break;}
                default:     {_Operation = WAIT_READ_OTHER; break;}
            }
        } else {
            switch (regno) {
                case 0x07b0: {_Operation = WAIT_READ_DCSR; break;}
                case 0x0c00: case 0x0c01: {_Operation = WAIT_READ_CYCLE;  break;}
                case 0x0c02: {_Operation = WAIT_READ_INSTRET; break;}
                case 0x0c80: case 0x0c81: {_Operation = WAIT_READ_CYCLEH; break;}
                case 0x0c82: {_Operation = WAIT_READ_INSTRETH; break;}
                default: {_Operation = WAIT_READ_OTHER; break;}
            }
        }
        // Comprobar si el comando se escribió y respondió correctamente...
        write(comando,_Operation);
        if (waitForReadComm()){
            comando = QByteArray(1, ABSTRACTCSrd);
            _Operation = CHECK_ERROR;
            write(comando,_Operation);
            if (waitForReadComm()) {
                return true;
            }
        }
    }
    emit DMConnected(false);
    return false;;
}

// Activa el modo paso por paso. Mediante comando abstracto. El procesador debe estar detenido
bool DTMController::ActiveOneStep(bool Activate)
{
    if (_serialPort->isOpen()) { // Comprobación del puerto
        if (ErrOnComm()){ // Si hay un error, lo corregimos
            if (!SendClrError()) {
                return false; // Error de espera
            }
        }
        if (isAutoExecComm()) // desactivamos autoexecdata0
        {
            if (!Autoexec(false)) {
                return false;
            }
        }
         // Escribimos data0
        comando = WRData0(Activate ? 0x000004 : 0x000000);
        // Activamos escritura a dcsr
        comando.append(WRCommand(0x07b0,true,true,false));
        comando.append(ABSTRACTCSrd);

        _Operation = CHECK_ERROR;
        write(comando,_Operation);
        if (waitForReadComm()) // Esperar escritura/lectura
        {
            if (!ErrOnComm() && ReadRegs(0x7b0,false)) { // Verificamos si no hay errores
                return (DbgEstado.onestep == Activate);
            }
        }
    }
    emit DMConnected(false);
    return false;
}

// Lee DATA0.
bool DTMController::RDData0(bool forReadRegs,quint16 regno){
    if (_serialPort->isOpen()) { // Comprobación del puerto
        // Lectura del registro DATA0

        if (forReadRegs){ // Contexto de la lectura de data0
            if (ErrOnComm()) {
                if (!SendClrError()) {
                    return false;
                }
            }
            switch (regno & 0xf000) {
                case 0x1000: {_Operation = NEXT_READ_GPR; break;}
                case 0xC000: {_Operation = NEXT_READ_PIPELINE; break;}
                default:     {_Operation = WAIT_READ_OTHER; break;}
            }
        } else {
            _Operation = READ_DATA0;
        }
        comando = QByteArray(1, DATA0rd);
        write(comando,_Operation);
        // Esperar lectura/escritura
        if (waitForReadComm()){
            return true;
        }
    }
    emit DMConnected(false);
    return false;
}


DTMController::~DTMController()
{
    disconnectPort();
    delete _serialPort;
}

// ---------------*   Métodos estáticos para obtener el comando a escribir *-----------------------------
QByteArray DTMController::WRDmcontrol(bool on, bool haltreq, bool resreq,
                                      bool ndmrst, bool haltOnRst, bool DeactHaltOnRst)
{
    bool trueResreq = !haltreq && resreq;
    quint8 Hrst = 0x00;
    if (haltOnRst) {
        Hrst = (DeactHaltOnRst ? 0x08 : 0x04 );
    }
    QByteArray comm(5, (char) 0x00);
    comm[0] = (char) DMCONTROLwr; // 0x90
    comm[1] = (char) (on | (ndmrst << 1) | Hrst);
    comm[4] = (char) ((haltreq << 7) | (trueResreq << 6));
    return comm;
}

QByteArray DTMController::WRData0(uint32_t data)
{
    QByteArray comm;
    comm.append((char) DATA0wr);
    for(int i=0;i<32;i+=8) {
        comm.append((char) ((data >> i) & 0xFF));
    }
    return comm;
}

QByteArray DTMController::WRCommand(uint16_t regno, bool write,
                                    bool  transfer, bool postincrement)
{
    QByteArray comm(5, (char) 0x00);
    comm[0] = (char) COMMANDwr; // write command 0x17
    comm[1] = (char) (regno        & 0xFF);
    comm[2] = (char) ((regno >> 8) & 0xFF);
    comm[3] = (char) (0x20 | write | (transfer << 1) | (postincrement << 3));
    return comm;
}

QByteArray DTMController::WRAbstractauto(bool autoexec)
{
    QByteArray comm(5 ,(char) 0x00);
    comm[0] = (char) AUTOEXECwr;
    comm[1] = (char) 0x00 | autoexec;
    return comm;
}

QByteArray DTMController::WRClrCmdError()
{
    QByteArray comm(5,(char) 0x00);
    comm[0] = (char) ABSTRACTCSwr;
    comm[2] = (char) 0x07;
    return comm;
}



