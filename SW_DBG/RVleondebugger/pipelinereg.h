#ifndef PIPELINEREG_H
#define PIPELINEREG_H

#include <QWidget>

struct ControlPipe{
    bool stall = false,
         flush = false,
         nop   = false;
    quint8 funct3, rs1, rs2, rd;
    bool MemRead  = false,
         MemWrite = false,
         RegWrite = false;
};

namespace Ui {
class PipelineReg;
}

class PipelineReg : public QWidget
{
    Q_OBJECT

public:
    static QString ColorUNO() { return QString("background-color: rgb(128,255,128);"); }
    static QString ColorZERO(){ return QString("background-color: rgb(255,128,128);"); }

    explicit PipelineReg(QWidget *parent = 0);
    explicit PipelineReg(bool StallEn, bool NOPEn, bool FlushEn, QWidget *parent = 0);
    ~PipelineReg();
    void setPIPE(ControlPipe * cntrl);

    //void setInstr();
    //void

//public slots:
    //void ChangeToHex(bool h);

private slots:


private:
    Ui::PipelineReg *ui;

    // bool NOP,STALL,
};

#endif // PIPELINEREG_H
