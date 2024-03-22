#ifndef CORESEGMENTACION_H
#define CORESEGMENTACION_H

#include <QObject>
#include <pipelinereg.h>

enum control_mask {
    mMEMWRITE = 0x01, mMEMREAD = 0x02, mREGWRITE = 0x04, mFUNCT3 = 0x08,
    mRD = 0x40, mALUsrc = 0x800, mALUFUN = 0x1000, mFUNQUAL = 0x2000, mISJALR = 0x4000,
    mJUMP = 0x8000,mISBRANCH=0x10000,mISCSR=0x20000, mISBREAK=0x40000, mAUIPC=0x80000,
    mLUI = 0x100000
};

class CoreSegmentacion : public QObject
{
    Q_OBJECT
public:
    explicit CoreSegmentacion(QObject *parent = 0);

    inline qint32  F_pc()   { return (qint32) PIPEregs[1]; }
    inline qint32  FD_pc()    { return (quint32) PIPEregs[2]; }
    inline quint32 FD_instr() { return (qint32) PIPEregs[3]; }
    inline qint32  DE_pc()      { return (qint32) PIPEregs[5]; }
    inline qint32  DE_rs1Data() { return (qint32) PIPEregs[6];}
    inline qint32  DE_rs2Data() { return (qint32) PIPEregs[7];}
    inline qint32  DE_imm()     { return (qint32) PIPEregs[8]; }
    inline qint32  EM_resultado() { return (qint32) PIPEregs[10]; }
    inline qint32  EM_rs2Data()   { return (qint32) PIPEregs[11]; }
    inline qint32  MW_resultado()  { return (qint32) PIPEregs[13]; }
    inline qint32  MW_MemoryData() { return (qint32) PIPEregs[14]; }
    inline ControlPipe * Fetch()     { return &Fpipe; }
    inline ControlPipe * Decod()     { return &Dpipe; }
    inline ControlPipe * Execute()   { return &Epipe; }
    inline ControlPipe * Memory()    { return &Mpipe; }
    inline ControlPipe * Writeback() { return &Wpipe; }
    inline bool get_W_fwdrs1() { return W_fwdrs1; }
    inline bool get_W_fwdrs2() { return W_fwdrs2; }
    inline bool get_M_fwdrs1() { return M_fwdrs1; }
    inline bool get_M_fwdrs2() { return M_fwdrs2; }
    inline bool get_loadhazard() { return loadHazard;}
    inline bool get_rs1hazard() { return rs1Hazard;}
    inline bool get_rs2hazard() { return rs2Hazard;}
    inline bool get_JumpOrBranch() {return E_JumpOrBranch;}
    inline bool get_DEControl(control_mask m) {
        return ((PIPEregs[4] & m) != 0);
    }
    inline quint16 EM_CSR () {
        return ((PIPEregs[9] >> 12) & 0xfff);
    }
    inline bool get_isEMCSR() {
        return ((PIPEregs[9] & 0x800) != 0);
    }
    QString M_Tambyte();

    void setPIPEregs(qint32 val, int pos);

signals:

public slots:

private:
    QList <qint32> PIPEregs;
    ControlPipe Fpipe, Dpipe, Epipe, Mpipe, Wpipe;
    bool W_fwdrs1, W_fwdrs2, M_fwdrs1, M_fwdrs2;
    bool E_JumpOrBranch;
    qint32 PCnext;
    bool loadHazard, rs1Hazard, rs2Hazard;

};

#endif // CORESEGMENTACION_H
