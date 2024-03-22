#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Iniciar UI
    _port = new DTMController(this); // crear nuevo puerto.
    // Inicializar lista de registros (32 GPR y 16 PIPE)
    for (int i = 0; i < 32; i++){
        GPregs.append(0);
        if (i < 16) PIPEregs.append(0);
    }
    _Core = new CoreSegmentacion(this);

    // Crea los items del QTable donde irán los valores de los GPR
    CreateRegs(); // Coloca enla segunda pestaña
    // señal proveniente del puerto: guarda los valores.
    QObject::connect(_port, &DTMController::dataIsDATA0,
                     this,  &MainWindow::receptor);// Conectar con slot a crear, para recibir datos (Maquina de estados)
    // QObject::connect(_port,&DTMController::DMActiveChanged,
       //              );
    // Crea el dialogo con algunos botones de control del DTM y del DM
    CreateDialogDTM(); // DialogDTM definicion y conexiones

    CreatePiperegs();

    ui->BtnPlay->setIcon(this->style()->standardIcon(QStyle::SP_MediaPlay));
    ui->BtnPause->setIcon(this->style()->standardIcon(QStyle::SP_MediaPause));
    ui->BtnNext->setIcon(this->style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->BtnRestart->setIcon(this->style()->standardIcon(QStyle::SP_BrowserReload));

    QObject::connect(_port,&DTMController::DMConnected,
                     ui->PipeCoreGbox,&QWidget::setEnabled);
    QObject::connect(_port,&DTMController::DMConnected,
                     ui->InstrDumpWidget,&QWidget::setEnabled);
    QObject::connect(_port,&DTMController::DMConnected,
                     ui->REGSwidget,&QWidget::setEnabled);

    // Mostrar Vertical Header and Horizontal Header
    ui->InstrViewTable->horizontalHeader()->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//--- Seccion de funciones que inicializan valores.

void MainWindow::CreateDialogDTM()
{
    DTMBtnGroup = new DialogDTM(this);
    auto layout = new QVBoxLayout();
    layout->addWidget(DTMBtnGroup);
    layout->setContentsMargins(0,0,0,0);
    ui->Fr_connDTM->setLayout(layout);
    QObject::connect(DTMBtnGroup, &DialogDTM::DTMcnnctd, // DTMcnnctd a ConnectPort
                     this, &MainWindow::ConnectPort);
    QObject::connect(_port, &DTMController::DMConnected, //
                     DTMBtnGroup, &DialogDTM::ConfirmConnection);

    QObject::connect(_port, &DTMController::haltedChanged,
                     DTMBtnGroup, &DialogDTM::ConfirmDBGModeActive);
    // Conectar ConfirmDMActivation con una señal o usarlo al detectar que problemas
}

void MainWindow::CreateRegs() // Crea e inicializa los valores de los registros.
{
    for (int i = 0; i < ui->RegsTable->rowCount(); i ++) {
        QTableWidgetItem *pReg = ui->RegsTable->item(i,0);
        ui->RegsTable->verticalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
        if (!pReg) {
            pReg = new QTableWidgetItem;
            pReg->setTextAlignment(Qt::AlignHCenter);
            pReg->setText("0"); // Inicializamos a cero
            ui->RegsTable->setItem(i,0,pReg); // incluímos en la tabla
        }
    }
}

void MainWindow::CreatePiperegs() {
    F_widget = new PipelineReg(true,false,false,ui->F_frm);
    FD_widget = new PipelineReg(ui->FD_frm);
    DE_widget = new PipelineReg(ui->DE_frm);
    EM_widget = new PipelineReg(ui->EM_frm);
    MW_widget = new PipelineReg(true,true,false,ui->MW_frm);

    CreatePipeLayout(ui->F_frm,  F_widget);
    CreatePipeLayout(ui->FD_frm, FD_widget);
    CreatePipeLayout(ui->DE_frm, DE_widget);
    CreatePipeLayout(ui->EM_frm, EM_widget);
    CreatePipeLayout(ui->MW_frm, MW_widget);
    // Cambiandole el color a las paletas...
    QPalette pal = ui->F_Label->palette();
    pal.setColor(QPalette::Background,F_color);

    ui->F_Label->setPalette(pal);
    ui->F_INSTR_txt->setPalette(pal);

    pal = ui->D_Label->palette();
    pal.setColor(QPalette::Background,D_color);
    ui->D_Label->setPalette(pal);
    ui->FD_INSTR_txt->setPalette(pal);

    pal = ui->E_Label->palette();
    pal.setColor(QPalette::Background,E_color);
    ui->E_Label->setPalette(pal);
    ui->DE_INSTR_txt->setPalette(pal);

    pal = ui->M_Label->palette();
    pal.setColor(QPalette::Background,M_color);
    ui->M_Label->setPalette(pal);
    ui->EM_INSTR_txt->setPalette(pal);

    pal = ui->W_Label->palette();
    pal.setColor(QPalette::Background,W_color);
    ui->W_Label->setPalette(pal);
    ui->MW_INSTR_txt->setPalette(pal);
}

void MainWindow::CreatePipeLayout(QFrame * fr,PipelineReg * pipe) {
    auto layout = new QGridLayout();
    layout->addWidget(pipe);
    layout->setContentsMargins(0,0,0,0);
    layout->setAlignment(Qt::AlignTop);
    fr->setLayout(layout);
}

// Slot para conectar dispositivo al GUI
void MainWindow::ConnectPort(bool conn)
{
    if (conn) { // Si la señal recibida es true, se busca conectar
        if (_port->connectPort()) {
            ui->statusBar->showMessage(QString("Conectando..."),3000);
            qDebug() << "Se Mando a activar: "; // Manda comando
            if (_port->ActivarDM()) {
                ui->statusBar->showMessage("DM Activado!",4000);
                _port->ActEstadoDM();
                // HABILITAR OTRAS OPCIONES
                ui->RunControlBtns->setEnabled(true);
                if (_port->isHalted()) {
                    on_BtnPause_clicked();
                } else {
                    ui->BtnPlay->setEnabled(false);
                    ui->BtnNext->setEnabled(false);
                    ui->BtnPause->setEnabled(true);
                }
                ui->BtnRestart->setEnabled(true);
            } else {
                QMessageBox::critical(this,"ERROR","No se pudo conectar. Conecte el dispositivo FTDI a la placa");
                ui->statusBar->showMessage("Error de conexion!!",3200);
                DTMBtnGroup->ConfirmConnection(false);
                ui->RunControlBtns->setEnabled(false);
            }
        } else {
            QMessageBox::critical(this,"ERROR","No se pudo conectar. Intente conectar el dispositivo FTDI.");
            ui->statusBar->showMessage("Error de conexion!!",3200);
            DTMBtnGroup->ConfirmConnection(false);
        }
    } else {// Sino, se busca desconectar.
        if (!_port->DesactivarDM()) {
          QMessageBox::information(this,"AVISO","El dispositivo no se pudo desconectar correctamente.");
          _port->disconnectPort();
        }
        ui->RunControlBtns->setEnabled(false);
        ui->statusBar->showMessage(QString("Desconectando..."),3000);
    }
}


void MainWindow::on_BtnPlay_clicked()
{

    if (_port->ActiveOneStep(false)) // Desactivamos One Step
    {
        if (_port->ResumeCore()) { // Mandar Comando de ResumeReq
            ui->statusBar->showMessage("CPU: Modo Debug desactivado.",2000);

            qDebug() << "Play Button:" << !_port->isHalted();
            _port->ActEstadoDM(); // Actualizar estado del DM
            ui->PipeCoreGbox->setEnabled(false); // Desactivar información  del DM
            ui->InstrDumpWidget->setEnabled(false);
            ui->REGSwidget->setEnabled(false);

            ui->BtnPlay->setEnabled(false); // De
            ui->BtnRestart->setEnabled(true);
            ui->BtnNext->setEnabled(false);
            ui->BtnPause->setEnabled(true);
            return;
        }
        qDebug() << "Error: No se pudo hacer un resume!";
    }
    qDebug() << "Error: No se pudo Apagar el One Step Mode!";


}

void MainWindow::on_BtnPause_clicked()
{
    if (_port->HaltCore()) {
        ui->statusBar->showMessage("CPU: Modo Debug activado",3000);
        _port->ActiveOneStep(true); // Activar
        _port->ActEstadoDM();

        LeerCSRs();
        LeerGPRegs();
        LeerPIPEregs(); // Leo
        // Llenar GUI
        ui->MW_PC_val->setText("0x????????");
        ui->MW_INSTR_val->setText("0x????????");
        ui->EM_PC_val->setText("0x????????");
        ui->EM_INSTR_val->setText("0x????????");
        ui->DE_PC_val->setText(   ConvertToString((quint32) _Core->DE_pc(), true));
        ui->DE_INSTR_val->setText("0x????????");
        ui->FD_PC_val->setText(   ConvertToString((quint32) _Core->FD_pc(), true));
        ui->FD_INSTR_val->setText(ConvertToString((quint32) _Core->FD_instr(), true));
        ui->F_PC_val->setText(    ConvertToString((quint32) _Core->F_pc(), true));

        SetPipeline();

        ui->PipeCoreGbox->setEnabled(true);
        ui->REGSwidget->setEnabled(true);
        ui->InstrDumpWidget->setEnabled(true);

        ui->BtnPause->setEnabled(false);
        ui->BtnNext->setEnabled(true);
        ui->BtnPlay->setEnabled(true);
        ui->BtnRestart->setEnabled(true);
    }
}

void MainWindow::on_BtnRestart_clicked()
{
    if (_port->RstCore(true,true)) {
        if (_port->ActiveOneStep(true)) {
            ui->statusBar->showMessage("CPU: Reiniciado. Modo Debug activado.",2000);
            LeerCSRs();
            LeerGPRegs();
            LeerPIPEregs(); // Leemos todos los registros.
             // Todos los registros se leyeron para este punto...
            //LlenarGUI();
            // Primero los FLUSH y NOP...
            ui->MW_PC_val->setText("0x????????");
            ui->MW_INSTR_val->setText("0x????????");
            ui->EM_PC_val->setText("0x????????");
            ui->EM_INSTR_val->setText("0x????????");

            ui->DE_PC_val->setText(   ConvertToString((quint32) _Core->DE_pc(), true));
            ui->DE_INSTR_val->setText("0x????????");
            ui->FD_PC_val->setText(   ConvertToString((quint32) _Core->FD_pc(), true));
            ui->FD_INSTR_val->setText(ConvertToString((quint32) _Core->FD_instr(), true));
            ui->F_PC_val->setText(    ConvertToString((quint32) _Core->F_pc(), true));

            _port->ActEstadoDM();
            SetPipeline();

            ui->PipeCoreGbox->setEnabled(true);
            ui->REGSwidget->setEnabled(true);
            ui->InstrDumpWidget->setEnabled(true);

            ui->BtnPause->setEnabled(false);
            ui->BtnNext->setEnabled(true);
            ui->BtnPlay->setEnabled(true);
            ui->BtnRestart->setEnabled(true);
            return;
        }
    }
}

void MainWindow::on_BtnNext_clicked()
{
    ui->BtnNext->setEnabled(false);
    if (_port->ResumeCore()) { // Mandar Comando de ResumeReq
        qDebug() << "Next Button:" << !_port->isHalted();
        quint64 prevCycle = cycle;
        _port->ActEstadoDM(); // Actualizar estado del DM
        LeerCSRs();
        LeerGPRegs();
        LeerPIPEregs(); // Leo
        ui->statusBar->showMessage(QString("CPU: Nuevo ciclo: 0x%1. Ciclo previo: 0x%2.")
                                   .arg(cycle,16,16,QLatin1Char('0'))
                                   .arg(prevCycle,16,16,QLatin1Char('0')) , 7000);
        // Llenar GUI
        ui->MW_PC_val->setText(ui->EM_PC_val->text());
        ui->MW_INSTR_val->setText(ui->EM_INSTR_val->text());
        ui->EM_PC_val->setText(ui->DE_PC_val->text());
        ui->EM_INSTR_val->setText(ui->DE_INSTR_val->text());
        ui->DE_PC_val->setText(   ConvertToString((quint32) _Core->DE_pc(), true));
        ui->DE_INSTR_val->setText(ui->FD_INSTR_val->text());
        ui->FD_PC_val->setText(   ConvertToString((quint32) _Core->FD_pc(), true));
        ui->FD_INSTR_val->setText(ConvertToString((quint32) _Core->FD_instr(), true));
        ui->F_PC_val->setText(    ConvertToString((quint32) _Core->F_pc(), true));

        SetPipeline();

        ui->BtnNext->setEnabled(true);
        return;

    }
    ui->BtnNext->setEnabled(true);
    qDebug() << "Error: OneStep está desconectado o no se ejecutó correctamente!";

}

void MainWindow::receptor(QByteArray data, qint16 DTMState)
{
    data0 = 0; // inicializa a cero
    memcpy(reinterpret_cast <char*>(&data0), data.data(), data.size());
    qDebug() << "DATA0:" << ConvertToString(data0,true) << "with state:" << DTMState;

    bool hex = (ui->HexCheckBox->checkState() == Qt::Checked);

    switch(DTMState) {
    case WAIT_READ_DCSR: {
        dcsr = data0;
        break;
    }
    case WAIT_READ_CYCLE: {
        cycle = cycle & 0xffffffff00000000;
        cycle = cycle | data0;
        break;
    }
    case WAIT_READ_CYCLEH: {
        cycle = cycle & 0xffffffff;
        cycle = cycle | ((quint64) data0 << 32);
    }
    case WAIT_READ_INSTRET: {
        instret = instret & 0xffffffff00000000;
        instret = instret | data0;
        break;
    }
    case WAIT_READ_INSTRETH: {
        instret = instret & 0xffffffff;
        instret = instret | ((quint64) data0 << 32);
        break;
    }
    case START_READ_GPR: {
        GPregs[0] = data0;
        qDebug().noquote() << QString("x%1 = 0x%2").arg(0).arg(GPregs[0],8,16,QLatin1Char('0'));
        count = 1;
        break;
    }
    case NEXT_READ_GPR: {
        GPregs[count] = data0;
        qDebug().noquote() << QString("x%1 = 0x%2").arg(count).arg(GPregs[count],8,16,QLatin1Char('0'));
        count++;
        if (count == 32) { // Llamar a actualizar registros
            ActualizarRegsTable(hex);
            count = 0;
        }
        break;
    }
    case START_READ_PIPELINE: {
        _Core->setPIPEregs(data0, 0);
        qDebug().noquote() << QString("PIPE%1 = 0x%2").arg(0).arg(data0,8,16,QLatin1Char('0'));
        count = 1;
        break;
    }
    case NEXT_READ_PIPELINE: {
        _Core->setPIPEregs(data0, count);
        qDebug().noquote() << QString("PIPE%1 = 0x%2").arg(count).arg(data0,8,16,QLatin1Char('0'));
        count++;
        if (count == 16) { // Llamar a actualizar registros
            // Cambiar valores
            // _Core
            count = 0;
        }
    }
    }
}

// Leer Registros de Proposito General (GPR)
void MainWindow::LeerGPRegs()
{
    if (_port->ReadRegs(0x1000,true,true)){
        // Si la operacion se concretó correctamente:
        for(int i = 0; i < 31; i++) {
            if (!_port->RDData0(true,0x1000)) {
                qDebug() << "Uh-Oh! ¿Como llegamos aqui?";
                break; // Error, no seguimos leyendo!
            }
        }
    }
}
// Leer Registros de Segmentacion
void MainWindow::LeerPIPEregs()
{
    if (_port->ReadRegs(0xC000,true,true)){
        // Si la operacion se concretó correctamente:
        for(int i = 0; i < 15; i++) {
            if (!_port->RDData0(true,0xC000)) {
                qDebug() << "Uh-Oh! ¿Como llegamos aqui?";
                break; // Error, no seguimos leyendo!
            }
        }
    }
}
// Leer y actualizar registros de Control y Estado... CSR
void MainWindow::LeerCSRs()
{
    if (_port->ReadRegs(0x0C00,false) && _port->ReadRegs(0x0C80,false) &&
        _port->ReadRegs(0x0C02,false) && _port->ReadRegs(0x0C82,false) &&
        _port->ReadRegs(0x07B0,false))
    {
        bool hex = (ui->HexCheckBox->checkState() == Qt::Checked);
        ActualizarValInstret(hex);
        ActualizarValCycle(hex);
        ActualizarValdcsr(hex);
        return;
    }
    qDebug() << "Uh-Oh! ¿Como llegamos aqui?";
}

void MainWindow::on_HexCheckBox_stateChanged(int arg1)
{
//    SetRegs((arg1 == Qt::Checked));
    HexActivated = (arg1 == Qt::Checked);
    ActualizarRegsTable(HexActivated);
    ActualizarValCycle(HexActivated);
    ActualizarValInstret(HexActivated);
    ActualizarValdcsr(HexActivated);
    if (_Core->Writeback()->RegWrite) {
        ui->RegsTable->setCurrentCell(_Core->Writeback()->rd,0);
        ui->RegsTable->currentItem()->setBackground(QColor(255,192,64));
    }
}
// --------- Actualizacion de valores mostrados -----------
void MainWindow::ActualizarRegsTable(bool hex) // Establece
{
    QString NumText;
    for (int i = 0; i < ui->RegsTable->rowCount(); i++) {
        NumText = ConvertToString((quint32) GPregs.at(i),hex);
        ui->RegsTable->setCurrentCell(i,0);
        auto item = ui->RegsTable->currentItem();
        if (item){
            item->setText(NumText);
            item->setBackground(QColor(0,0,0,0));
        }
    }

}
void MainWindow::ActualizarValCycle(bool hex) {
    ui->val_cycle->setText(ConvertToString(cycle,hex));
}
void MainWindow::ActualizarValInstret(bool hex) {
    ui->val_instret->setText(ConvertToString(instret,hex));
}
void MainWindow::ActualizarValdcsr(bool hex) {
    ui->val_dcsr->setText(ConvertToString(dcsr,hex));
}

void MainWindow::SetPipeline() {
    // Establecer las señales de control:
    auto Wpipe = _Core->Writeback(),
         Mpipe = _Core->Memory(),
         Epipe = _Core->Execute(),
         Dpipe = _Core->Decod();

    F_widget->setPIPE(_Core->Fetch());
    FD_widget->setPIPE(_Core->Decod());
    DE_widget->setPIPE(Epipe);
    EM_widget->setPIPE(_Core->Memory());
    MW_widget->setPIPE(Wpipe);


    // La Logica del forwarding
    quint32 true_rs1, true_rs2;
    auto M_rs1 = _Core->get_M_fwdrs1(),
         M_rs2 = _Core->get_M_fwdrs2(),
         W_rs1 = _Core->get_W_fwdrs1(),
         W_rs2 = _Core->get_W_fwdrs2();

    if (M_rs1) {
        true_rs1 = _Core->EM_resultado();// PIPEregs[10];
        ui->rs1_FWD_W->setStyleSheet(PipelineReg::ColorZERO());
        ui->rs1_FWD_M->setStyleSheet(PipelineReg::ColorUNO());
    } else if (W_rs1) {
        true_rs1 = Wpipe->MemRead ? _Core->MW_MemoryData()
                                  : _Core->MW_resultado(); // PIPEregs[13];
        ui->rs1_FWD_W->setStyleSheet(PipelineReg::ColorUNO());
        ui->rs1_FWD_M->setStyleSheet(PipelineReg::ColorZERO());
    } else {
        true_rs1 = _Core->DE_rs1Data();
        ui->rs1_FWD_W->setStyleSheet(PipelineReg::ColorZERO());
        ui->rs1_FWD_M->setStyleSheet(PipelineReg::ColorZERO());
    }
    ui->E_rs1_num->setText(QString("rs1: %1").arg(Epipe->rs1));
    ui->E_rs1_val->setText(ConvertToString(true_rs1,true));

    if (M_rs2) {
        true_rs2 = _Core->EM_resultado();
        ui->rs2_FWD_W->setStyleSheet(PipelineReg::ColorZERO());
        ui->rs2_FWD_M->setStyleSheet(PipelineReg::ColorUNO());
    } else if (W_rs2) {
        true_rs2 = Wpipe->MemRead ? _Core->MW_MemoryData()
                                  : _Core->MW_resultado();
        ui->rs2_FWD_W->setStyleSheet(PipelineReg::ColorUNO());
        ui->rs2_FWD_M->setStyleSheet(PipelineReg::ColorZERO());
    } else {
        true_rs2 = _Core->DE_rs2Data();
        ui->rs2_FWD_W->setStyleSheet(PipelineReg::ColorZERO());
        ui->rs2_FWD_M->setStyleSheet(PipelineReg::ColorZERO());
    }
    ui->E_rs2_num->setText(QString("rs2: %1").arg(Epipe->rs2));
    ui->E_rs2_val->setText(ConvertToString(true_rs2,true));

    // PC next:
    quint32 realPCnext;
    if (_Core->Fetch()->stall) {
        realPCnext = _Core->F_pc();
    } else if (_Core->get_JumpOrBranch()) {
        if (_Core->get_DEControl(control_mask::mISJALR)) { // TODO cambiar DE_isJALR
            realPCnext = true_rs1 + _Core->DE_imm();
        } else {
            realPCnext = _Core->DE_pc() + _Core->DE_imm();
        }
    } else {
        realPCnext = _Core->F_pc() + 4;
    }
    ui->F_PCNEXT_val->setText(ConvertToString(realPCnext,true));

    // Load Hazard
    if (_Core->get_loadhazard()){
        ui->LoadHazard->setStyleSheet(PipelineReg::ColorUNO());
        ui->D_rs1_num->setStyleSheet(_Core->get_rs1hazard() ?
                                       PipelineReg::ColorUNO() :
                                       "");
        ui->D_rs2_num->setStyleSheet(_Core->get_rs2hazard() ?
                                       PipelineReg::ColorUNO() :
                                       "");
    } else {
        ui->LoadHazard->setStyleSheet("");
        ui->D_rs1_num->setStyleSheet("");
        ui->D_rs2_num->setStyleSheet("");
    }
    // Registros a acceder (etapa D)
    ui->D_rs1_num->setText(QString("rs1: %1").arg(Dpipe->rs1));
    ui->D_rs2_num->setText(QString("rs2: %1").arg(Dpipe->rs2));
    ui->D_rd_num->setText(QString("rd: %1").arg(Dpipe->rd));

    // (etapa E)
    ui->E_rs1_num->setText(QString("rs1: %1").arg(Epipe->rs1));
    ui->E_rs2_num->setText(QString("rs2: %1").arg(Epipe->rs2));
    ui->E_rd_num->setText(QString("rd: %1").arg(Epipe->rd));

    if (_Core->get_JumpOrBranch()) {
        if (_Core->get_DEControl(control_mask::mJUMP)) {
            if(_Core->get_DEControl(control_mask::mISJALR)){
                ui->J_JALR->setStyleSheet(PipelineReg::ColorUNO());
            } else {
                ui->J_JAL->setStyleSheet(PipelineReg::ColorUNO());
            }
        } else {
            ui->J_Branch->setStyleSheet(PipelineReg::ColorUNO());
        }
        ui->J_JumpOrBranch->setStyleSheet(PipelineReg::ColorUNO());
    } else {
        ui->J_JALR->setStyleSheet("");
        ui->J_JAL->setStyleSheet("");
        ui->J_Branch->setStyleSheet("");
        ui->J_JumpOrBranch->setStyleSheet("");
    }

    // Registros y Memoria (etapa M)
    quint32 EM_resultado = _Core->EM_resultado();
    quint32 EM_rs2Data   = _Core->EM_rs2Data();
    ui->M_rd_num->setText(QString("rd: %1").arg(Mpipe->rd));
    ui->Mem_tam_txt->setText(_Core->M_Tambyte());
    if (Mpipe->MemRead) {
        ui->Memory->setStyleSheet(PipelineReg::ColorUNO());
        ui->M_rd_mem->setText("0x????????");
        ui->Mem_addr_val->setText(ConvertToString(EM_resultado,true));
        ui->Mem_data_val->setText("0x????????");
    } else if (Mpipe->MemWrite){
        ui->Memory->setStyleSheet(PipelineReg::ColorUNO());
        ui->M_rd_mem->setText("0x????????");
        ui->Mem_addr_val->setText(ConvertToString(EM_resultado,true));
        ui->Mem_data_val->setText(ConvertToString(EM_rs2Data,true));
    } else {
        ui->Memory->setStyleSheet("");
        ui->M_rd_mem->setText(ConvertToString(_Core->get_isEMCSR() ?
                                                  _Core->EM_CSR() :
                                                  EM_resultado,
                                              true));
        ui->Mem_addr_val->setText("0x????????");
        ui->Mem_data_val->setText("0x????????");
    }

    // (etapa W)
    ui->W_rd_num->setText(QString("rd: %1").arg(Wpipe->rd));
    ui->W_rd_val->setText(ConvertToString(Wpipe->MemRead ?
                                              _Core->MW_MemoryData() :
                                              _Core->MW_resultado()));
    if (Wpipe->RegWrite) {
        ui->RegsTable->setCurrentCell(Wpipe->rd,0);
        ui->RegsTable->currentItem()->setBackground(QColor(255,192,64));
    }

    SetBackgroundByPipeline();
}

void MainWindow::on_OpenCodeBtn_clicked()
{
    ui->OpenCodeBtn->setEnabled(false);
    elfHexFile = QFileDialog::getOpenFileName(this,
                                              tr("Abrir Archivo .hex"),
                                              QDir::homePath(),
                                              tr("Elf Hex (*.dbg.hex)"));
    if (elfHexFile.isEmpty()){
        return;
    }
    ui->FilePathProg->setText(elfHexFile);
    QFile file(elfHexFile);


    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Aqui debo de eliminar esas vainas
        for(int i=0;i<4;i++) {
            HGRows[i] = -1;
        }
        QTextStream in(&file);
        quint8 state = 0;
        QStringList lista;
        auto instructions = ui->InstrViewTable;
        // Removemos valores anteriores....
        while (instructions->rowCount() != 0){
            instructions->removeRow(0);
        }
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (state == 0){
                if (line.contains(".text:")) {
                    state = 1;
                }
            } else if (state == 1){
                if (line.startsWith("Disassembly")) {
                    state = 2;
                } else if (line.contains(QRegExp("[0-9a-fA-F]+:"))) {
                    // Procesamos esta linea en especifico...
                    line.remove(" "); // Eliminando espacios
                    int n = line.lastIndexOf("#"); // comentarios
                    if (n != -1) line.truncate(n);
                    int m = line.lastIndexOf("<"); // direccion absoluta
                    if (m != -1) line.truncate(m);
                    line.replace(line.lastIndexOf(":"), 1,""); // y el ':'
                    lista = line.split("\t"); // separar debido al '\t'
                    if (lista.size() == 4) {
                        lista[2] += QString(" ").append(lista.at(3));
                        lista.removeLast();
                    }
                    // Agregamos nueva columna
                    auto actRow = instructions->rowCount();
                    instructions->insertRow(actRow); // ¡OJO! El valor interno de rowCount es ahora actRow + 1
                    // Agregamos nuevo Header y datos...
                    instructions->setItem(actRow, 0,
                                          new QTableWidgetItem(QString("0x%1")
                                                               .arg(lista[0],8,QLatin1Char('0'))));
                    instructions->setItem(actRow, 1,
                                          new QTableWidgetItem(QString("0x").append(lista[1])));
                    instructions->setItem(actRow, 2,
                                          new QTableWidgetItem(lista[2]));

                }
            }
        }
        TablaActualizada = true;
        SetBackgroundByPipeline();
        file.close();
    } else {
        QMessageBox::warning(this,"Error!",file.errorString());
        TablaActualizada = false;
    }

    ui->OpenCodeBtn->setEnabled(true);
}

void MainWindow::ChangeBackgroundItems(int InstrRow, QColor PipeColor) {
    auto instructions = ui->InstrViewTable;
    if (InstrRow != -1) {
        for(int i=0; i < instructions->columnCount(); i++) {
            instructions->item(InstrRow, i)->setBackground(PipeColor);
        }
    }
}

void MainWindow::SetBackgroundByPipeline() {
    if (ui->PipeCoreGbox->isEnabled() && _port->isHalted() && TablaActualizada) {
        for (int pipe = 0; pipe < 5; pipe++) { // limpiamos
            ChangeBackgroundItems(HGRows[pipe],QColor(0,0,0,0));
        }
        // Fetch...
        ResaltarInstruccion(0, F_color);
        // Decode
        ResaltarInstruccion(1, D_color);
        // execute
        ResaltarInstruccion(2, E_color);
        // Memory
        if (!ui->EM_PC_val->text().contains('?')) {
            ResaltarInstruccion(3, M_color);
        }
        // Writeback
        if (!ui->MW_PC_val->text().contains('?')) {
            ResaltarInstruccion(4, W_color);
        }
     ui->InstrViewTable->scrollToItem(ui->InstrViewTable->item(HGRows[0],0));
    }
}
void MainWindow::ResaltarInstruccion(int pipe, QColor color) {
    QLabel* pc_val, * instr_txt;
    int row;
    bool nop = 0;
    auto instructions = ui->InstrViewTable;
    if (pipe == 0) {
        nop = _Core->Fetch()->nop;
        pc_val = ui->F_PC_val;
        instr_txt = ui->F_INSTR_txt;
    } else if (pipe == 1) {
        nop = _Core->Decod()->nop;
        pc_val = ui->FD_PC_val;
        instr_txt = ui->FD_INSTR_txt;
    } else if (pipe == 2) {
        nop = _Core->Execute()->nop;
        pc_val = ui->DE_PC_val;
        instr_txt = ui->DE_INSTR_txt;
    } else if (pipe == 3) {
        nop = _Core->Memory()->nop;
        pc_val = ui->EM_PC_val;
        instr_txt = ui->EM_INSTR_txt;
    } else { //if (pipe == 4) {
        nop = _Core->Writeback()->nop;
        pc_val = ui->MW_PC_val;
        instr_txt = ui->MW_INSTR_txt;
    }
    auto seg_ = instructions->findItems(pc_val->text(),Qt::MatchContains);
    if (seg_.size() != 0) {
        row = seg_[0]->row();
        ChangeBackgroundItems(row, color); // damos color
        HGRows[pipe] = row;
        if (nop) {
            instr_txt->setText("- NOP -");
        } else {
            instr_txt->setText(instructions->item(row,2)->text());
        }

//        if (nop) {
//            ChangeBackgroundPalette(instr_txt,Qt::DiagCrossPattern);
//        } else {
//            ChangeBackgroundPalette(instr_txt,Qt::SolidPattern);
//        }
    }
}

void MainWindow::ChangeBackgroundPalette(QLabel * lbl, Qt::BrushStyle r) {
    QPalette palette = lbl->palette();
    QBrush brush = palette.brush(QPalette::Background);
    brush.setStyle(r);
    palette.setBrush(QPalette::Background,brush);
    lbl->setPalette(palette);
}
