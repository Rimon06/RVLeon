#include "DialogDTM.h"
#include "ui_DialogDTM.h"

DialogDTM::DialogDTM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDTM)
{
    ui->setupUi(this);

}

DialogDTM::~DialogDTM()
{
    delete ui;
}

void DialogDTM::on_BtnCnnctDTM_clicked()
{
    // Llamar _port.connect();
    ui->BtnCnnctDTM->setEnabled(false);
    emit DTMcnnctd(true);
}
void DialogDTM::on_BtnDiscnntDTM_clicked()
{
    ui->BtnDiscnntDTM->setEnabled(false);
    ui->BtnCnnctDTM->setEnabled(true);
    emit DTMcnnctd(false);
}

void DialogDTM::ConfirmConnection(bool connected)
{
    ui->BtnDiscnntDTM->setEnabled(connected);
    ui->BtnCnnctDTM->setEnabled(!connected); // Volver a activar el botón
    if (connected) {
        ui->Lbl_DTMState->setText("Conectado!");
        ui->Lbl_DBGState->setText("DM Listo a usar");
    } else {
        ui->Lbl_DTMState->setText("No Conectado!");
        ui->Lbl_DBGState->setText("----------------");
    }

}

void DialogDTM::ConfirmDBGModeActive(bool connected) {
    if (connected) {
        ui->Lbl_DBGState->setText("Activado");
    } else {
        ui->Lbl_DBGState->setText("Desactivado");
    }
}
