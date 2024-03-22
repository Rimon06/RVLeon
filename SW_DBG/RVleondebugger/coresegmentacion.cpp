#include "coresegmentacion.h"

CoreSegmentacion::CoreSegmentacion(QObject *parent) : QObject(parent)
{
    for (int i = 0; i < 16; i++){ // inicializamos valores
        PIPEregs.append(0);
    }
}

QString CoreSegmentacion::M_Tambyte()
{
    QString txt = "--- ";
    if (Mpipe.MemRead || Mpipe.MemWrite) {
        switch (Mpipe.funct3) {
            case 4:  if (Mpipe.MemRead) txt = "Unsig ";
            case 0:  txt += "Byte"; break;
            case 5:  if (Mpipe.MemRead) txt = "Unsig ";
            case 1:  txt += "Half-Word"; break;
            case 2:  txt += "Word"; break;
            default: txt += ""; break;
        }
    }

    return txt;
}

void CoreSegmentacion::setPIPEregs(qint32 val, int pos) {

    PIPEregs[pos] = val;
    switch (pos){
    case 0: {

        Dpipe.nop = (val >> 1) & 0x01;
        Epipe.nop = (val >> 2) & 0x01;
        Mpipe.nop = (val >> 3) & 0x01;
        Wpipe.nop = (val >> 4) & 0x01;

        Dpipe.flush = (val >> 6) & 0x01;
        Epipe.flush = (val >> 7) & 0x01;
        Mpipe.flush = (val >> 8) & 0x01;
        Wpipe.flush = (val >> 9) & 0x01;

        Fpipe.stall = (val >> 10)  & 0x01;
        Dpipe.stall = (val >> 11) & 0x01;
        Epipe.stall = (val >> 12) & 0x01;
        Mpipe.stall = (val >> 13) & 0x01;
        Wpipe.stall = (val >> 14) & 0x01;

        M_fwdrs1 = (val >> 16) & 0x01;
        M_fwdrs2 = (val >> 17) & 0x01;
        W_fwdrs1 = (val >> 18) & 0x01;
        W_fwdrs2 = (val >> 19) & 0x01;

        loadHazard = (val >> 20) & 0x01;
        rs2Hazard = (val >> 21) & 0x01;
        rs1Hazard = (val >> 22) & 0x01;
        E_JumpOrBranch = (val >> 24) & 0x01;
        break;
    }
    case 3: {
        quint8 OP_instr = (val & 0x7f);
        Dpipe.MemWrite = (OP_instr == 0x23); // store
        Dpipe.MemRead  = (OP_instr == 0x03); // load
        Dpipe.funct3   = (val >> 12) & 0x07;

        Dpipe.rd       = (val >> 7) & 0x1f;
        Dpipe.rs1      = (val >> 15) & 0x1f;
        Dpipe.rs2      = (val >> 20) & 0x1f;
        Dpipe.RegWrite = (Dpipe.rd != 0) && (OP_instr != 0x23) && (OP_instr != 0x63);
    }
    case 4: {
        Epipe.MemWrite = val & 0x01;
        Epipe.MemRead  = (val >> 1) & 0x01;
        Epipe.RegWrite = (val >> 2) & 0x01;
        Epipe.funct3   = (val >> 3) & 0x07;
        Epipe.rd       = (val >> 6) & 0x1f;
        Epipe.rs2      = (val >> 21) & 0x1f;
        Epipe.rs1      = (val >> 26) & 0x1f;
    }
    case 9: {
        Mpipe.MemWrite = val & 0x01;
        Mpipe.MemRead  = (val >> 1) & 0x01;
        Mpipe.RegWrite = (val >> 2) & 0x01;
        Mpipe.funct3   = (val >> 3) & 0x07;
        Mpipe.rd       = (val >> 6) & 0x1f;
        //Mpipe.rs2      = (val >> 21) & 0x1f;
        //Mpipe.rs1      = (val >> 26) & 0x1f;
    }
    case 12: {
        Wpipe.MemWrite = val & 0x01;
        Wpipe.MemRead  = (val >> 1) & 0x01;
        Wpipe.RegWrite = (val >> 2) & 0x01;
        Wpipe.funct3   = (val >> 3) & 0x07;
        Wpipe.rd       = (val >> 6) & 0x1f;
//        Wpipe.rs2      = (val >> 21) & 0x1f;
//        Wpipe.rs1      = (val >> 26) & 0x1f;
    }
    }
}

