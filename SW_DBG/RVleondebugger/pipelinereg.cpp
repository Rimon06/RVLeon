#include "pipelinereg.h"
#include "ui_pipelinereg.h"
PipelineReg::PipelineReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PipelineReg)
{
    ui->setupUi(this);
}

PipelineReg::PipelineReg(bool StallEn, bool NOPEn, bool FlushEn, QWidget *parent) :
    QWidget(parent), ui(new Ui::PipelineReg)
{
    ui->setupUi(this);
    ui->FlushFrame->setVisible(FlushEn);
    ui->StallFrame->setVisible(StallEn);
    ui->NOPFrame->setVisible(NOPEn);
    ui->Funct3->setVisible(NOPEn);
    ui->MemRead->setVisible(NOPEn);
    ui->MemWrite->setVisible(NOPEn);
    ui->RegWrite->setVisible(NOPEn);

}

PipelineReg::~PipelineReg()
{
    delete ui;
}

void PipelineReg::setPIPE(ControlPipe *cntrl)
{
    ui->NOPFrame->setStyleSheet(  cntrl->nop   ? ColorUNO() : ColorZERO());
    ui->StallFrame->setStyleSheet(cntrl->stall ? ColorUNO() : "");
    ui->FlushFrame->setStyleSheet(cntrl->flush ? ColorUNO() : "");
    ui->MemRead->setStyleSheet( cntrl->MemRead ? ColorUNO() : ColorZERO());
    ui->MemWrite->setStyleSheet(cntrl->MemWrite ? ColorUNO() : ColorZERO());
    ui->RegWrite->setStyleSheet(cntrl->RegWrite ? ColorUNO() : ColorZERO());
    ui->Funct3Val->setText(QString("%1").arg(cntrl->funct3));
}

