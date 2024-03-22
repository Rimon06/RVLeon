/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *PipeCoreGbox;
    QGridLayout *gridLayout_7;
    QVBoxLayout *M_VLayout;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_52;
    QLabel *EM_PC_val;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_54;
    QLabel *EM_INSTR_val;
    QLabel *EM_INSTR_txt;
    QSpacerItem *verticalSpacer_4;
    QFrame *D_memFrame;
    QGridLayout *gridLayout_16;
    QLabel *Memory;
    QHBoxLayout *horizontalLayout_17;
    QLabel *Mem_addr_lbl;
    QLabel *Mem_addr_val;
    QHBoxLayout *horizontalLayout_18;
    QLabel *Mem_data_lbl;
    QLabel *Mem_data_val;
    QHBoxLayout *horizontalLayout_19;
    QLabel *Mem_tam_lbl;
    QLabel *Mem_tam_txt;
    QSpacerItem *verticalSpacer_9;
    QFrame *M_rd_frame;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    QLabel *M_rd_mem;
    QLabel *label_9;
    QLabel *M_rd_num;
    QFrame *MW_frm;
    QLabel *W_Label;
    QFrame *EM_frm;
    QLabel *M_Label;
    QVBoxLayout *F_VLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_40;
    QLabel *F_PC_val;
    QHBoxLayout *horizontalLayout;
    QLabel *label_33;
    QLabel *F_PCNEXT_val;
    QLabel *F_INSTR_txt;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *W_VLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_57;
    QLabel *MW_PC_val;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_59;
    QLabel *MW_INSTR_val;
    QLabel *MW_INSTR_txt;
    QSpacerItem *verticalSpacer_5;
    QFrame *W_rd_frame;
    QGridLayout *gridLayout_5;
    QLabel *W_rd_num;
    QLabel *label_10;
    QLabel *W_rd_val;
    QLabel *label_8;
    QVBoxLayout *E_VLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_47;
    QLabel *DE_PC_val;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_49;
    QLabel *DE_INSTR_val;
    QLabel *DE_INSTR_txt;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout_9;
    QLabel *J_JALR;
    QLabel *J_JumpOrBranch;
    QLabel *J_Branch;
    QLabel *J_JAL;
    QFrame *frame_5;
    QGridLayout *gridLayout_12;
    QFrame *rs1_frame;
    QGridLayout *gridLayout_13;
    QSpacerItem *horizontalSpacer_3;
    QLabel *E_rs1_val;
    QLabel *rs1_FWD_M;
    QLabel *rs1_FWD_W;
    QLabel *E_rs1_num;
    QLabel *label_22;
    QFrame *rs2_frame;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_4;
    QLabel *E_rs2_val;
    QLabel *rs2_FWD_M;
    QLabel *rs2_FWD_W;
    QLabel *E_rs2_num;
    QSpacerItem *verticalSpacer_8;
    QFrame *E_rd_frame;
    QGridLayout *gridLayout_8;
    QLabel *E_rd_num;
    QFrame *DE_frm;
    QLabel *E_Label;
    QFrame *FD_frm;
    QLabel *F_Label;
    QLabel *D_Label;
    QFrame *F_frm;
    QVBoxLayout *D_VLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_42;
    QLabel *FD_PC_val;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_44;
    QLabel *FD_INSTR_val;
    QLabel *FD_INSTR_txt;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *LoadHazard;
    QLabel *D_rs1_num;
    QLabel *D_rs2_num;
    QSpacerItem *horizontalSpacer_2;
    QFrame *D_rd_frame;
    QGridLayout *gridLayout_11;
    QLabel *D_rd_num;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QFrame *RunControlBtns;
    QGridLayout *gridLayout_4;
    QPushButton *BtnNext;
    QPushButton *BtnPause;
    QPushButton *BtnRestart;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *BtnPlay;
    QWidget *Fr_connDTM;
    QWidget *InstrDumpWidget;
    QGridLayout *gridLayout_17;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *FilePathProg;
    QPushButton *OpenCodeBtn;
    QTableWidget *InstrViewTable;
    QWidget *REGSwidget;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *HexCheckBox;
    QTableWidget *RegsTable;
    QGridLayout *gridLayout_3;
    QLabel *val_cycle;
    QLabel *label_66;
    QLabel *label_64;
    QLabel *val_dcsr;
    QLabel *label_68;
    QLabel *val_instret;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1188, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        PipeCoreGbox = new QFrame(centralWidget);
        PipeCoreGbox->setObjectName(QStringLiteral("PipeCoreGbox"));
        PipeCoreGbox->setEnabled(false);
        PipeCoreGbox->setFrameShape(QFrame::Box);
        PipeCoreGbox->setFrameShadow(QFrame::Plain);
        PipeCoreGbox->setLineWidth(2);
        PipeCoreGbox->setMidLineWidth(0);
        gridLayout_7 = new QGridLayout(PipeCoreGbox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(2);
        gridLayout_7->setVerticalSpacing(1);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        M_VLayout = new QVBoxLayout();
        M_VLayout->setSpacing(4);
        M_VLayout->setObjectName(QStringLiteral("M_VLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_52 = new QLabel(PipeCoreGbox);
        label_52->setObjectName(QStringLiteral("label_52"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_52->sizePolicy().hasHeightForWidth());
        label_52->setSizePolicy(sizePolicy);
        label_52->setMinimumSize(QSize(40, 0));
        label_52->setMaximumSize(QSize(40, 16777215));
        label_52->setAutoFillBackground(false);
        label_52->setFrameShape(QFrame::Box);
        label_52->setFrameShadow(QFrame::Sunken);
        label_52->setLineWidth(1);

        horizontalLayout_13->addWidget(label_52);

        EM_PC_val = new QLabel(PipeCoreGbox);
        EM_PC_val->setObjectName(QStringLiteral("EM_PC_val"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EM_PC_val->sizePolicy().hasHeightForWidth());
        EM_PC_val->setSizePolicy(sizePolicy1);
        EM_PC_val->setMinimumSize(QSize(60, 0));
        EM_PC_val->setMaximumSize(QSize(150, 16777215));
        EM_PC_val->setAutoFillBackground(false);
        EM_PC_val->setFrameShape(QFrame::Box);
        EM_PC_val->setFrameShadow(QFrame::Sunken);
        EM_PC_val->setLineWidth(1);

        horizontalLayout_13->addWidget(EM_PC_val);


        M_VLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_54 = new QLabel(PipeCoreGbox);
        label_54->setObjectName(QStringLiteral("label_54"));
        sizePolicy.setHeightForWidth(label_54->sizePolicy().hasHeightForWidth());
        label_54->setSizePolicy(sizePolicy);
        label_54->setMinimumSize(QSize(40, 0));
        label_54->setMaximumSize(QSize(40, 16777215));
        label_54->setAutoFillBackground(false);
        label_54->setFrameShape(QFrame::Box);
        label_54->setFrameShadow(QFrame::Sunken);
        label_54->setLineWidth(1);

        horizontalLayout_14->addWidget(label_54);

        EM_INSTR_val = new QLabel(PipeCoreGbox);
        EM_INSTR_val->setObjectName(QStringLiteral("EM_INSTR_val"));
        sizePolicy1.setHeightForWidth(EM_INSTR_val->sizePolicy().hasHeightForWidth());
        EM_INSTR_val->setSizePolicy(sizePolicy1);
        EM_INSTR_val->setMinimumSize(QSize(60, 0));
        EM_INSTR_val->setMaximumSize(QSize(150, 16777215));
        EM_INSTR_val->setAutoFillBackground(false);
        EM_INSTR_val->setFrameShape(QFrame::Box);
        EM_INSTR_val->setFrameShadow(QFrame::Sunken);
        EM_INSTR_val->setLineWidth(1);

        horizontalLayout_14->addWidget(EM_INSTR_val);


        M_VLayout->addLayout(horizontalLayout_14);

        EM_INSTR_txt = new QLabel(PipeCoreGbox);
        EM_INSTR_txt->setObjectName(QStringLiteral("EM_INSTR_txt"));
        EM_INSTR_txt->setLayoutDirection(Qt::LeftToRight);
        EM_INSTR_txt->setAutoFillBackground(true);
        EM_INSTR_txt->setFrameShape(QFrame::Box);
        EM_INSTR_txt->setFrameShadow(QFrame::Sunken);
        EM_INSTR_txt->setLineWidth(1);
        EM_INSTR_txt->setScaledContents(false);
        EM_INSTR_txt->setAlignment(Qt::AlignCenter);
        EM_INSTR_txt->setWordWrap(false);
        EM_INSTR_txt->setTextInteractionFlags(Qt::TextEditable);

        M_VLayout->addWidget(EM_INSTR_txt);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        M_VLayout->addItem(verticalSpacer_4);

        D_memFrame = new QFrame(PipeCoreGbox);
        D_memFrame->setObjectName(QStringLiteral("D_memFrame"));
        D_memFrame->setFrameShape(QFrame::Box);
        D_memFrame->setFrameShadow(QFrame::Sunken);
        gridLayout_16 = new QGridLayout(D_memFrame);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        Memory = new QLabel(D_memFrame);
        Memory->setObjectName(QStringLiteral("Memory"));
        sizePolicy1.setHeightForWidth(Memory->sizePolicy().hasHeightForWidth());
        Memory->setSizePolicy(sizePolicy1);
        Memory->setFrameShape(QFrame::Box);
        Memory->setFrameShadow(QFrame::Raised);
        Memory->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(Memory, 0, 0, 1, 2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        Mem_addr_lbl = new QLabel(D_memFrame);
        Mem_addr_lbl->setObjectName(QStringLiteral("Mem_addr_lbl"));
        sizePolicy.setHeightForWidth(Mem_addr_lbl->sizePolicy().hasHeightForWidth());
        Mem_addr_lbl->setSizePolicy(sizePolicy);
        Mem_addr_lbl->setMinimumSize(QSize(40, 0));
        Mem_addr_lbl->setMaximumSize(QSize(40, 16777215));
        Mem_addr_lbl->setAutoFillBackground(false);
        Mem_addr_lbl->setFrameShape(QFrame::Box);
        Mem_addr_lbl->setFrameShadow(QFrame::Sunken);
        Mem_addr_lbl->setLineWidth(1);

        horizontalLayout_17->addWidget(Mem_addr_lbl);

        Mem_addr_val = new QLabel(D_memFrame);
        Mem_addr_val->setObjectName(QStringLiteral("Mem_addr_val"));
        sizePolicy1.setHeightForWidth(Mem_addr_val->sizePolicy().hasHeightForWidth());
        Mem_addr_val->setSizePolicy(sizePolicy1);
        Mem_addr_val->setMinimumSize(QSize(60, 0));
        Mem_addr_val->setMaximumSize(QSize(150, 16777215));
        Mem_addr_val->setAutoFillBackground(false);
        Mem_addr_val->setFrameShape(QFrame::Box);
        Mem_addr_val->setFrameShadow(QFrame::Sunken);
        Mem_addr_val->setLineWidth(1);

        horizontalLayout_17->addWidget(Mem_addr_val);


        gridLayout_16->addLayout(horizontalLayout_17, 1, 0, 1, 2);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        Mem_data_lbl = new QLabel(D_memFrame);
        Mem_data_lbl->setObjectName(QStringLiteral("Mem_data_lbl"));
        sizePolicy.setHeightForWidth(Mem_data_lbl->sizePolicy().hasHeightForWidth());
        Mem_data_lbl->setSizePolicy(sizePolicy);
        Mem_data_lbl->setMinimumSize(QSize(40, 0));
        Mem_data_lbl->setMaximumSize(QSize(40, 16777215));
        Mem_data_lbl->setAutoFillBackground(false);
        Mem_data_lbl->setFrameShape(QFrame::Box);
        Mem_data_lbl->setFrameShadow(QFrame::Sunken);
        Mem_data_lbl->setLineWidth(1);

        horizontalLayout_18->addWidget(Mem_data_lbl);

        Mem_data_val = new QLabel(D_memFrame);
        Mem_data_val->setObjectName(QStringLiteral("Mem_data_val"));
        sizePolicy1.setHeightForWidth(Mem_data_val->sizePolicy().hasHeightForWidth());
        Mem_data_val->setSizePolicy(sizePolicy1);
        Mem_data_val->setMinimumSize(QSize(60, 0));
        Mem_data_val->setMaximumSize(QSize(150, 16777215));
        Mem_data_val->setAutoFillBackground(false);
        Mem_data_val->setFrameShape(QFrame::Box);
        Mem_data_val->setFrameShadow(QFrame::Sunken);
        Mem_data_val->setLineWidth(1);

        horizontalLayout_18->addWidget(Mem_data_val);


        gridLayout_16->addLayout(horizontalLayout_18, 2, 0, 1, 2);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        Mem_tam_lbl = new QLabel(D_memFrame);
        Mem_tam_lbl->setObjectName(QStringLiteral("Mem_tam_lbl"));
        sizePolicy.setHeightForWidth(Mem_tam_lbl->sizePolicy().hasHeightForWidth());
        Mem_tam_lbl->setSizePolicy(sizePolicy);
        Mem_tam_lbl->setMinimumSize(QSize(40, 0));
        Mem_tam_lbl->setMaximumSize(QSize(40, 16777215));
        Mem_tam_lbl->setAutoFillBackground(false);
        Mem_tam_lbl->setFrameShape(QFrame::Box);
        Mem_tam_lbl->setFrameShadow(QFrame::Sunken);
        Mem_tam_lbl->setLineWidth(1);

        horizontalLayout_19->addWidget(Mem_tam_lbl);

        Mem_tam_txt = new QLabel(D_memFrame);
        Mem_tam_txt->setObjectName(QStringLiteral("Mem_tam_txt"));
        sizePolicy1.setHeightForWidth(Mem_tam_txt->sizePolicy().hasHeightForWidth());
        Mem_tam_txt->setSizePolicy(sizePolicy1);
        Mem_tam_txt->setMinimumSize(QSize(60, 0));
        Mem_tam_txt->setMaximumSize(QSize(150, 16777215));
        Mem_tam_txt->setAutoFillBackground(false);
        Mem_tam_txt->setFrameShape(QFrame::Box);
        Mem_tam_txt->setFrameShadow(QFrame::Sunken);
        Mem_tam_txt->setLineWidth(1);

        horizontalLayout_19->addWidget(Mem_tam_txt);


        gridLayout_16->addLayout(horizontalLayout_19, 3, 0, 1, 1);


        M_VLayout->addWidget(D_memFrame);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        M_VLayout->addItem(verticalSpacer_9);

        M_rd_frame = new QFrame(PipeCoreGbox);
        M_rd_frame->setObjectName(QStringLiteral("M_rd_frame"));
        M_rd_frame->setFrameShape(QFrame::Box);
        M_rd_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_6 = new QGridLayout(M_rd_frame);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(M_rd_frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(label_12, 2, 1, 1, 1);

        M_rd_mem = new QLabel(M_rd_frame);
        M_rd_mem->setObjectName(QStringLiteral("M_rd_mem"));

        gridLayout_6->addWidget(M_rd_mem, 2, 2, 1, 1);

        label_9 = new QLabel(M_rd_frame);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 2, 3);

        M_rd_num = new QLabel(M_rd_frame);
        M_rd_num->setObjectName(QStringLiteral("M_rd_num"));
        sizePolicy.setHeightForWidth(M_rd_num->sizePolicy().hasHeightForWidth());
        M_rd_num->setSizePolicy(sizePolicy);
        M_rd_num->setMinimumSize(QSize(40, 0));

        gridLayout_6->addWidget(M_rd_num, 2, 0, 1, 1);


        M_VLayout->addWidget(M_rd_frame);


        gridLayout_7->addLayout(M_VLayout, 1, 7, 1, 1);

        MW_frm = new QFrame(PipeCoreGbox);
        MW_frm->setObjectName(QStringLiteral("MW_frm"));
        sizePolicy.setHeightForWidth(MW_frm->sizePolicy().hasHeightForWidth());
        MW_frm->setSizePolicy(sizePolicy);
        MW_frm->setMinimumSize(QSize(10, 0));
        MW_frm->setFrameShape(QFrame::StyledPanel);
        MW_frm->setFrameShadow(QFrame::Sunken);
        MW_frm->setLineWidth(2);

        gridLayout_7->addWidget(MW_frm, 1, 8, 1, 1);

        W_Label = new QLabel(PipeCoreGbox);
        W_Label->setObjectName(QStringLiteral("W_Label"));
        W_Label->setAutoFillBackground(true);
        W_Label->setFrameShape(QFrame::Box);
        W_Label->setFrameShadow(QFrame::Sunken);
        W_Label->setLineWidth(3);
        W_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(W_Label, 0, 8, 1, 2);

        EM_frm = new QFrame(PipeCoreGbox);
        EM_frm->setObjectName(QStringLiteral("EM_frm"));
        sizePolicy.setHeightForWidth(EM_frm->sizePolicy().hasHeightForWidth());
        EM_frm->setSizePolicy(sizePolicy);
        EM_frm->setMinimumSize(QSize(10, 0));
        EM_frm->setFrameShape(QFrame::StyledPanel);
        EM_frm->setFrameShadow(QFrame::Sunken);
        EM_frm->setLineWidth(2);

        gridLayout_7->addWidget(EM_frm, 1, 6, 1, 1);

        M_Label = new QLabel(PipeCoreGbox);
        M_Label->setObjectName(QStringLiteral("M_Label"));
        M_Label->setAutoFillBackground(true);
        M_Label->setFrameShape(QFrame::Box);
        M_Label->setFrameShadow(QFrame::Sunken);
        M_Label->setLineWidth(3);
        M_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(M_Label, 0, 6, 1, 2);

        F_VLayout = new QVBoxLayout();
        F_VLayout->setSpacing(4);
        F_VLayout->setObjectName(QStringLiteral("F_VLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_40 = new QLabel(PipeCoreGbox);
        label_40->setObjectName(QStringLiteral("label_40"));
        sizePolicy.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy);
        label_40->setMinimumSize(QSize(55, 0));
        label_40->setMaximumSize(QSize(55, 16777215));
        label_40->setAutoFillBackground(false);
        label_40->setFrameShape(QFrame::Box);
        label_40->setFrameShadow(QFrame::Sunken);
        label_40->setLineWidth(1);

        horizontalLayout_8->addWidget(label_40);

        F_PC_val = new QLabel(PipeCoreGbox);
        F_PC_val->setObjectName(QStringLiteral("F_PC_val"));
        sizePolicy1.setHeightForWidth(F_PC_val->sizePolicy().hasHeightForWidth());
        F_PC_val->setSizePolicy(sizePolicy1);
        F_PC_val->setMinimumSize(QSize(60, 0));
        F_PC_val->setMaximumSize(QSize(150, 16777215));
        F_PC_val->setAutoFillBackground(false);
        F_PC_val->setFrameShape(QFrame::Box);
        F_PC_val->setFrameShadow(QFrame::Sunken);
        F_PC_val->setLineWidth(1);

        horizontalLayout_8->addWidget(F_PC_val);


        F_VLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_33 = new QLabel(PipeCoreGbox);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMinimumSize(QSize(55, 0));
        label_33->setMaximumSize(QSize(55, 16777215));
        label_33->setLayoutDirection(Qt::LeftToRight);
        label_33->setAutoFillBackground(false);
        label_33->setFrameShape(QFrame::Box);
        label_33->setFrameShadow(QFrame::Sunken);
        label_33->setLineWidth(1);
        label_33->setScaledContents(false);
        label_33->setWordWrap(false);
        label_33->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout->addWidget(label_33);

        F_PCNEXT_val = new QLabel(PipeCoreGbox);
        F_PCNEXT_val->setObjectName(QStringLiteral("F_PCNEXT_val"));
        sizePolicy1.setHeightForWidth(F_PCNEXT_val->sizePolicy().hasHeightForWidth());
        F_PCNEXT_val->setSizePolicy(sizePolicy1);
        F_PCNEXT_val->setMinimumSize(QSize(60, 0));
        F_PCNEXT_val->setMaximumSize(QSize(150, 16777215));
        F_PCNEXT_val->setLayoutDirection(Qt::LeftToRight);
        F_PCNEXT_val->setAutoFillBackground(false);
        F_PCNEXT_val->setFrameShape(QFrame::Box);
        F_PCNEXT_val->setFrameShadow(QFrame::Sunken);
        F_PCNEXT_val->setLineWidth(1);
        F_PCNEXT_val->setScaledContents(false);
        F_PCNEXT_val->setWordWrap(false);
        F_PCNEXT_val->setTextInteractionFlags(Qt::TextEditable);

        horizontalLayout->addWidget(F_PCNEXT_val);


        F_VLayout->addLayout(horizontalLayout);

        F_INSTR_txt = new QLabel(PipeCoreGbox);
        F_INSTR_txt->setObjectName(QStringLiteral("F_INSTR_txt"));
        F_INSTR_txt->setLayoutDirection(Qt::LeftToRight);
        F_INSTR_txt->setAutoFillBackground(true);
        F_INSTR_txt->setFrameShape(QFrame::Box);
        F_INSTR_txt->setFrameShadow(QFrame::Sunken);
        F_INSTR_txt->setLineWidth(1);
        F_INSTR_txt->setScaledContents(false);
        F_INSTR_txt->setAlignment(Qt::AlignCenter);
        F_INSTR_txt->setWordWrap(false);
        F_INSTR_txt->setTextInteractionFlags(Qt::TextEditable);

        F_VLayout->addWidget(F_INSTR_txt);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        F_VLayout->addItem(verticalSpacer_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        F_VLayout->addItem(verticalSpacer);


        gridLayout_7->addLayout(F_VLayout, 1, 1, 1, 1);

        W_VLayout = new QVBoxLayout();
        W_VLayout->setSpacing(4);
        W_VLayout->setObjectName(QStringLiteral("W_VLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_57 = new QLabel(PipeCoreGbox);
        label_57->setObjectName(QStringLiteral("label_57"));
        sizePolicy.setHeightForWidth(label_57->sizePolicy().hasHeightForWidth());
        label_57->setSizePolicy(sizePolicy);
        label_57->setMinimumSize(QSize(40, 0));
        label_57->setMaximumSize(QSize(40, 16777215));
        label_57->setAutoFillBackground(false);
        label_57->setFrameShape(QFrame::Box);
        label_57->setFrameShadow(QFrame::Sunken);
        label_57->setLineWidth(1);

        horizontalLayout_15->addWidget(label_57);

        MW_PC_val = new QLabel(PipeCoreGbox);
        MW_PC_val->setObjectName(QStringLiteral("MW_PC_val"));
        sizePolicy1.setHeightForWidth(MW_PC_val->sizePolicy().hasHeightForWidth());
        MW_PC_val->setSizePolicy(sizePolicy1);
        MW_PC_val->setMinimumSize(QSize(60, 0));
        MW_PC_val->setMaximumSize(QSize(150, 16777215));
        MW_PC_val->setAutoFillBackground(false);
        MW_PC_val->setFrameShape(QFrame::Box);
        MW_PC_val->setFrameShadow(QFrame::Sunken);
        MW_PC_val->setLineWidth(1);

        horizontalLayout_15->addWidget(MW_PC_val);


        W_VLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_59 = new QLabel(PipeCoreGbox);
        label_59->setObjectName(QStringLiteral("label_59"));
        sizePolicy.setHeightForWidth(label_59->sizePolicy().hasHeightForWidth());
        label_59->setSizePolicy(sizePolicy);
        label_59->setMinimumSize(QSize(40, 0));
        label_59->setMaximumSize(QSize(40, 16777215));
        label_59->setAutoFillBackground(false);
        label_59->setFrameShape(QFrame::Box);
        label_59->setFrameShadow(QFrame::Sunken);
        label_59->setLineWidth(1);

        horizontalLayout_16->addWidget(label_59);

        MW_INSTR_val = new QLabel(PipeCoreGbox);
        MW_INSTR_val->setObjectName(QStringLiteral("MW_INSTR_val"));
        sizePolicy1.setHeightForWidth(MW_INSTR_val->sizePolicy().hasHeightForWidth());
        MW_INSTR_val->setSizePolicy(sizePolicy1);
        MW_INSTR_val->setMinimumSize(QSize(60, 0));
        MW_INSTR_val->setMaximumSize(QSize(150, 16777215));
        MW_INSTR_val->setAutoFillBackground(false);
        MW_INSTR_val->setFrameShape(QFrame::Box);
        MW_INSTR_val->setFrameShadow(QFrame::Sunken);
        MW_INSTR_val->setLineWidth(1);

        horizontalLayout_16->addWidget(MW_INSTR_val);


        W_VLayout->addLayout(horizontalLayout_16);

        MW_INSTR_txt = new QLabel(PipeCoreGbox);
        MW_INSTR_txt->setObjectName(QStringLiteral("MW_INSTR_txt"));
        MW_INSTR_txt->setLayoutDirection(Qt::LeftToRight);
        MW_INSTR_txt->setAutoFillBackground(true);
        MW_INSTR_txt->setFrameShape(QFrame::Box);
        MW_INSTR_txt->setFrameShadow(QFrame::Sunken);
        MW_INSTR_txt->setLineWidth(1);
        MW_INSTR_txt->setScaledContents(false);
        MW_INSTR_txt->setAlignment(Qt::AlignCenter);
        MW_INSTR_txt->setWordWrap(false);
        MW_INSTR_txt->setTextInteractionFlags(Qt::TextEditable);

        W_VLayout->addWidget(MW_INSTR_txt);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        W_VLayout->addItem(verticalSpacer_5);

        W_rd_frame = new QFrame(PipeCoreGbox);
        W_rd_frame->setObjectName(QStringLiteral("W_rd_frame"));
        W_rd_frame->setFrameShape(QFrame::Box);
        W_rd_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_5 = new QGridLayout(W_rd_frame);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        W_rd_num = new QLabel(W_rd_frame);
        W_rd_num->setObjectName(QStringLiteral("W_rd_num"));
        sizePolicy.setHeightForWidth(W_rd_num->sizePolicy().hasHeightForWidth());
        W_rd_num->setSizePolicy(sizePolicy);
        W_rd_num->setMinimumSize(QSize(40, 0));

        gridLayout_5->addWidget(W_rd_num, 2, 0, 1, 1);

        label_10 = new QLabel(W_rd_frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_10, 2, 1, 1, 1);

        W_rd_val = new QLabel(W_rd_frame);
        W_rd_val->setObjectName(QStringLiteral("W_rd_val"));

        gridLayout_5->addWidget(W_rd_val, 2, 2, 1, 1);

        label_8 = new QLabel(W_rd_frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 0, 0, 2, 3);


        W_VLayout->addWidget(W_rd_frame);


        gridLayout_7->addLayout(W_VLayout, 1, 9, 1, 1);

        E_VLayout = new QVBoxLayout();
        E_VLayout->setSpacing(4);
        E_VLayout->setObjectName(QStringLiteral("E_VLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_47 = new QLabel(PipeCoreGbox);
        label_47->setObjectName(QStringLiteral("label_47"));
        sizePolicy.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy);
        label_47->setMinimumSize(QSize(40, 0));
        label_47->setMaximumSize(QSize(40, 16777215));
        label_47->setAutoFillBackground(false);
        label_47->setFrameShape(QFrame::Box);
        label_47->setFrameShadow(QFrame::Sunken);
        label_47->setLineWidth(1);

        horizontalLayout_11->addWidget(label_47);

        DE_PC_val = new QLabel(PipeCoreGbox);
        DE_PC_val->setObjectName(QStringLiteral("DE_PC_val"));
        sizePolicy1.setHeightForWidth(DE_PC_val->sizePolicy().hasHeightForWidth());
        DE_PC_val->setSizePolicy(sizePolicy1);
        DE_PC_val->setMinimumSize(QSize(60, 0));
        DE_PC_val->setMaximumSize(QSize(150, 16777215));
        DE_PC_val->setAutoFillBackground(false);
        DE_PC_val->setFrameShape(QFrame::Box);
        DE_PC_val->setFrameShadow(QFrame::Sunken);
        DE_PC_val->setLineWidth(1);

        horizontalLayout_11->addWidget(DE_PC_val);


        E_VLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_49 = new QLabel(PipeCoreGbox);
        label_49->setObjectName(QStringLiteral("label_49"));
        sizePolicy.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy);
        label_49->setMinimumSize(QSize(40, 0));
        label_49->setMaximumSize(QSize(40, 16777215));
        label_49->setAutoFillBackground(false);
        label_49->setFrameShape(QFrame::Box);
        label_49->setFrameShadow(QFrame::Sunken);
        label_49->setLineWidth(1);

        horizontalLayout_12->addWidget(label_49);

        DE_INSTR_val = new QLabel(PipeCoreGbox);
        DE_INSTR_val->setObjectName(QStringLiteral("DE_INSTR_val"));
        sizePolicy1.setHeightForWidth(DE_INSTR_val->sizePolicy().hasHeightForWidth());
        DE_INSTR_val->setSizePolicy(sizePolicy1);
        DE_INSTR_val->setMinimumSize(QSize(60, 0));
        DE_INSTR_val->setMaximumSize(QSize(150, 16777215));
        DE_INSTR_val->setAutoFillBackground(false);
        DE_INSTR_val->setFrameShape(QFrame::Box);
        DE_INSTR_val->setFrameShadow(QFrame::Sunken);
        DE_INSTR_val->setLineWidth(1);

        horizontalLayout_12->addWidget(DE_INSTR_val);


        E_VLayout->addLayout(horizontalLayout_12);

        DE_INSTR_txt = new QLabel(PipeCoreGbox);
        DE_INSTR_txt->setObjectName(QStringLiteral("DE_INSTR_txt"));
        DE_INSTR_txt->setLayoutDirection(Qt::LeftToRight);
        DE_INSTR_txt->setAutoFillBackground(true);
        DE_INSTR_txt->setFrameShape(QFrame::Box);
        DE_INSTR_txt->setFrameShadow(QFrame::Sunken);
        DE_INSTR_txt->setLineWidth(1);
        DE_INSTR_txt->setScaledContents(false);
        DE_INSTR_txt->setAlignment(Qt::AlignCenter);
        DE_INSTR_txt->setWordWrap(false);
        DE_INSTR_txt->setTextInteractionFlags(Qt::TextEditable);

        E_VLayout->addWidget(DE_INSTR_txt);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        E_VLayout->addItem(verticalSpacer_6);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(1);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        J_JALR = new QLabel(PipeCoreGbox);
        J_JALR->setObjectName(QStringLiteral("J_JALR"));
        sizePolicy.setHeightForWidth(J_JALR->sizePolicy().hasHeightForWidth());
        J_JALR->setSizePolicy(sizePolicy);
        J_JALR->setMinimumSize(QSize(50, 0));
        J_JALR->setMaximumSize(QSize(50, 16777215));
        J_JALR->setLayoutDirection(Qt::LeftToRight);
        J_JALR->setAutoFillBackground(false);
        J_JALR->setFrameShape(QFrame::Box);
        J_JALR->setFrameShadow(QFrame::Sunken);
        J_JALR->setLineWidth(1);
        J_JALR->setScaledContents(false);
        J_JALR->setAlignment(Qt::AlignCenter);
        J_JALR->setWordWrap(false);
        J_JALR->setTextInteractionFlags(Qt::TextEditable);

        gridLayout_9->addWidget(J_JALR, 1, 1, 1, 1);

        J_JumpOrBranch = new QLabel(PipeCoreGbox);
        J_JumpOrBranch->setObjectName(QStringLiteral("J_JumpOrBranch"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(J_JumpOrBranch->sizePolicy().hasHeightForWidth());
        J_JumpOrBranch->setSizePolicy(sizePolicy3);
        J_JumpOrBranch->setFrameShape(QFrame::Box);
        J_JumpOrBranch->setFrameShadow(QFrame::Raised);
        J_JumpOrBranch->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(J_JumpOrBranch, 0, 0, 1, 3);

        J_Branch = new QLabel(PipeCoreGbox);
        J_Branch->setObjectName(QStringLiteral("J_Branch"));
        sizePolicy.setHeightForWidth(J_Branch->sizePolicy().hasHeightForWidth());
        J_Branch->setSizePolicy(sizePolicy);
        J_Branch->setMinimumSize(QSize(50, 0));
        J_Branch->setMaximumSize(QSize(50, 16777215));
        J_Branch->setLayoutDirection(Qt::LeftToRight);
        J_Branch->setAutoFillBackground(false);
        J_Branch->setFrameShape(QFrame::Box);
        J_Branch->setFrameShadow(QFrame::Sunken);
        J_Branch->setLineWidth(1);
        J_Branch->setScaledContents(false);
        J_Branch->setAlignment(Qt::AlignCenter);
        J_Branch->setWordWrap(false);
        J_Branch->setTextInteractionFlags(Qt::TextEditable);

        gridLayout_9->addWidget(J_Branch, 1, 0, 1, 1);

        J_JAL = new QLabel(PipeCoreGbox);
        J_JAL->setObjectName(QStringLiteral("J_JAL"));
        sizePolicy.setHeightForWidth(J_JAL->sizePolicy().hasHeightForWidth());
        J_JAL->setSizePolicy(sizePolicy);
        J_JAL->setMinimumSize(QSize(50, 0));
        J_JAL->setMaximumSize(QSize(50, 16777215));
        J_JAL->setLayoutDirection(Qt::LeftToRight);
        J_JAL->setAutoFillBackground(false);
        J_JAL->setFrameShape(QFrame::Box);
        J_JAL->setFrameShadow(QFrame::Sunken);
        J_JAL->setLineWidth(1);
        J_JAL->setScaledContents(false);
        J_JAL->setAlignment(Qt::AlignCenter);
        J_JAL->setWordWrap(false);
        J_JAL->setTextInteractionFlags(Qt::TextEditable);

        gridLayout_9->addWidget(J_JAL, 1, 2, 1, 1);


        E_VLayout->addLayout(gridLayout_9);

        frame_5 = new QFrame(PipeCoreGbox);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Sunken);
        gridLayout_12 = new QGridLayout(frame_5);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        rs1_frame = new QFrame(frame_5);
        rs1_frame->setObjectName(QStringLiteral("rs1_frame"));
        rs1_frame->setFrameShape(QFrame::Box);
        rs1_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_13 = new QGridLayout(rs1_frame);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        E_rs1_val = new QLabel(rs1_frame);
        E_rs1_val->setObjectName(QStringLiteral("E_rs1_val"));
        E_rs1_val->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(E_rs1_val, 2, 0, 1, 3);

        rs1_FWD_M = new QLabel(rs1_frame);
        rs1_FWD_M->setObjectName(QStringLiteral("rs1_FWD_M"));
        sizePolicy.setHeightForWidth(rs1_FWD_M->sizePolicy().hasHeightForWidth());
        rs1_FWD_M->setSizePolicy(sizePolicy);
        rs1_FWD_M->setFrameShape(QFrame::Box);
        rs1_FWD_M->setFrameShadow(QFrame::Raised);

        gridLayout_13->addWidget(rs1_FWD_M, 0, 0, 1, 1);

        rs1_FWD_W = new QLabel(rs1_frame);
        rs1_FWD_W->setObjectName(QStringLiteral("rs1_FWD_W"));
        sizePolicy.setHeightForWidth(rs1_FWD_W->sizePolicy().hasHeightForWidth());
        rs1_FWD_W->setSizePolicy(sizePolicy);
        rs1_FWD_W->setFrameShape(QFrame::Box);
        rs1_FWD_W->setFrameShadow(QFrame::Raised);

        gridLayout_13->addWidget(rs1_FWD_W, 0, 2, 1, 1);

        E_rs1_num = new QLabel(rs1_frame);
        E_rs1_num->setObjectName(QStringLiteral("E_rs1_num"));
        E_rs1_num->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(E_rs1_num, 1, 0, 1, 3);

        rs1_FWD_W->raise();
        rs1_FWD_M->raise();
        E_rs1_val->raise();
        E_rs1_num->raise();

        gridLayout_12->addWidget(rs1_frame, 1, 0, 1, 1);

        label_22 = new QLabel(frame_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);
        label_22->setFrameShape(QFrame::Box);
        label_22->setFrameShadow(QFrame::Raised);
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_22, 0, 0, 1, 2);

        rs2_frame = new QFrame(frame_5);
        rs2_frame->setObjectName(QStringLiteral("rs2_frame"));
        rs2_frame->setFrameShape(QFrame::Box);
        rs2_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_14 = new QGridLayout(rs2_frame);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        E_rs2_val = new QLabel(rs2_frame);
        E_rs2_val->setObjectName(QStringLiteral("E_rs2_val"));
        E_rs2_val->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(E_rs2_val, 2, 0, 1, 3);

        rs2_FWD_M = new QLabel(rs2_frame);
        rs2_FWD_M->setObjectName(QStringLiteral("rs2_FWD_M"));
        sizePolicy.setHeightForWidth(rs2_FWD_M->sizePolicy().hasHeightForWidth());
        rs2_FWD_M->setSizePolicy(sizePolicy);
        rs2_FWD_M->setFrameShape(QFrame::Box);
        rs2_FWD_M->setFrameShadow(QFrame::Raised);

        gridLayout_14->addWidget(rs2_FWD_M, 0, 0, 1, 1);

        rs2_FWD_W = new QLabel(rs2_frame);
        rs2_FWD_W->setObjectName(QStringLiteral("rs2_FWD_W"));
        sizePolicy.setHeightForWidth(rs2_FWD_W->sizePolicy().hasHeightForWidth());
        rs2_FWD_W->setSizePolicy(sizePolicy);
        rs2_FWD_W->setFrameShape(QFrame::Box);
        rs2_FWD_W->setFrameShadow(QFrame::Raised);

        gridLayout_14->addWidget(rs2_FWD_W, 0, 2, 1, 1);

        E_rs2_num = new QLabel(rs2_frame);
        E_rs2_num->setObjectName(QStringLiteral("E_rs2_num"));
        E_rs2_num->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(E_rs2_num, 1, 0, 1, 3);


        gridLayout_12->addWidget(rs2_frame, 1, 1, 1, 1);


        E_VLayout->addWidget(frame_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        E_VLayout->addItem(verticalSpacer_8);

        E_rd_frame = new QFrame(PipeCoreGbox);
        E_rd_frame->setObjectName(QStringLiteral("E_rd_frame"));
        E_rd_frame->setFrameShape(QFrame::Box);
        E_rd_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_8 = new QGridLayout(E_rd_frame);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        E_rd_num = new QLabel(E_rd_frame);
        E_rd_num->setObjectName(QStringLiteral("E_rd_num"));
        sizePolicy.setHeightForWidth(E_rd_num->sizePolicy().hasHeightForWidth());
        E_rd_num->setSizePolicy(sizePolicy);
        E_rd_num->setMinimumSize(QSize(40, 0));

        gridLayout_8->addWidget(E_rd_num, 0, 0, 1, 1);


        E_VLayout->addWidget(E_rd_frame);


        gridLayout_7->addLayout(E_VLayout, 1, 5, 1, 1);

        DE_frm = new QFrame(PipeCoreGbox);
        DE_frm->setObjectName(QStringLiteral("DE_frm"));
        sizePolicy.setHeightForWidth(DE_frm->sizePolicy().hasHeightForWidth());
        DE_frm->setSizePolicy(sizePolicy);
        DE_frm->setMinimumSize(QSize(10, 0));
        DE_frm->setFrameShape(QFrame::StyledPanel);
        DE_frm->setFrameShadow(QFrame::Sunken);
        DE_frm->setLineWidth(2);

        gridLayout_7->addWidget(DE_frm, 1, 4, 1, 1);

        E_Label = new QLabel(PipeCoreGbox);
        E_Label->setObjectName(QStringLiteral("E_Label"));
        E_Label->setAutoFillBackground(true);
        E_Label->setFrameShape(QFrame::Box);
        E_Label->setFrameShadow(QFrame::Sunken);
        E_Label->setLineWidth(3);
        E_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(E_Label, 0, 4, 1, 2);

        FD_frm = new QFrame(PipeCoreGbox);
        FD_frm->setObjectName(QStringLiteral("FD_frm"));
        sizePolicy.setHeightForWidth(FD_frm->sizePolicy().hasHeightForWidth());
        FD_frm->setSizePolicy(sizePolicy);
        FD_frm->setMinimumSize(QSize(10, 0));
        FD_frm->setFrameShape(QFrame::StyledPanel);
        FD_frm->setFrameShadow(QFrame::Sunken);
        FD_frm->setLineWidth(2);

        gridLayout_7->addWidget(FD_frm, 1, 2, 1, 1);

        F_Label = new QLabel(PipeCoreGbox);
        F_Label->setObjectName(QStringLiteral("F_Label"));
        F_Label->setAutoFillBackground(true);
        F_Label->setFrameShape(QFrame::Box);
        F_Label->setFrameShadow(QFrame::Sunken);
        F_Label->setLineWidth(3);
        F_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(F_Label, 0, 0, 1, 2);

        D_Label = new QLabel(PipeCoreGbox);
        D_Label->setObjectName(QStringLiteral("D_Label"));
        D_Label->setAutoFillBackground(true);
        D_Label->setFrameShape(QFrame::Box);
        D_Label->setFrameShadow(QFrame::Sunken);
        D_Label->setLineWidth(3);
        D_Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(D_Label, 0, 2, 1, 2);

        F_frm = new QFrame(PipeCoreGbox);
        F_frm->setObjectName(QStringLiteral("F_frm"));
        sizePolicy.setHeightForWidth(F_frm->sizePolicy().hasHeightForWidth());
        F_frm->setSizePolicy(sizePolicy);
        F_frm->setMinimumSize(QSize(10, 0));
        F_frm->setFrameShape(QFrame::StyledPanel);
        F_frm->setFrameShadow(QFrame::Sunken);
        F_frm->setLineWidth(2);

        gridLayout_7->addWidget(F_frm, 1, 0, 1, 1);

        D_VLayout = new QVBoxLayout();
        D_VLayout->setSpacing(4);
        D_VLayout->setObjectName(QStringLiteral("D_VLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_42 = new QLabel(PipeCoreGbox);
        label_42->setObjectName(QStringLiteral("label_42"));
        sizePolicy.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy);
        label_42->setMinimumSize(QSize(40, 0));
        label_42->setMaximumSize(QSize(40, 16777215));
        label_42->setAutoFillBackground(false);
        label_42->setFrameShape(QFrame::Box);
        label_42->setFrameShadow(QFrame::Sunken);
        label_42->setLineWidth(1);

        horizontalLayout_9->addWidget(label_42);

        FD_PC_val = new QLabel(PipeCoreGbox);
        FD_PC_val->setObjectName(QStringLiteral("FD_PC_val"));
        sizePolicy1.setHeightForWidth(FD_PC_val->sizePolicy().hasHeightForWidth());
        FD_PC_val->setSizePolicy(sizePolicy1);
        FD_PC_val->setMinimumSize(QSize(60, 0));
        FD_PC_val->setMaximumSize(QSize(150, 16777215));
        FD_PC_val->setAutoFillBackground(false);
        FD_PC_val->setFrameShape(QFrame::Box);
        FD_PC_val->setFrameShadow(QFrame::Sunken);
        FD_PC_val->setLineWidth(1);

        horizontalLayout_9->addWidget(FD_PC_val);


        D_VLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_44 = new QLabel(PipeCoreGbox);
        label_44->setObjectName(QStringLiteral("label_44"));
        sizePolicy.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy);
        label_44->setMinimumSize(QSize(40, 0));
        label_44->setMaximumSize(QSize(40, 16777215));
        label_44->setAutoFillBackground(false);
        label_44->setFrameShape(QFrame::Box);
        label_44->setFrameShadow(QFrame::Sunken);
        label_44->setLineWidth(1);

        horizontalLayout_10->addWidget(label_44);

        FD_INSTR_val = new QLabel(PipeCoreGbox);
        FD_INSTR_val->setObjectName(QStringLiteral("FD_INSTR_val"));
        sizePolicy1.setHeightForWidth(FD_INSTR_val->sizePolicy().hasHeightForWidth());
        FD_INSTR_val->setSizePolicy(sizePolicy1);
        FD_INSTR_val->setMinimumSize(QSize(60, 0));
        FD_INSTR_val->setMaximumSize(QSize(150, 16777215));
        FD_INSTR_val->setAutoFillBackground(false);
        FD_INSTR_val->setFrameShape(QFrame::Box);
        FD_INSTR_val->setFrameShadow(QFrame::Sunken);
        FD_INSTR_val->setLineWidth(1);

        horizontalLayout_10->addWidget(FD_INSTR_val);


        D_VLayout->addLayout(horizontalLayout_10);

        FD_INSTR_txt = new QLabel(PipeCoreGbox);
        FD_INSTR_txt->setObjectName(QStringLiteral("FD_INSTR_txt"));
        FD_INSTR_txt->setLayoutDirection(Qt::LeftToRight);
        FD_INSTR_txt->setAutoFillBackground(true);
        FD_INSTR_txt->setFrameShape(QFrame::Box);
        FD_INSTR_txt->setFrameShadow(QFrame::Sunken);
        FD_INSTR_txt->setLineWidth(1);
        FD_INSTR_txt->setScaledContents(false);
        FD_INSTR_txt->setAlignment(Qt::AlignCenter);
        FD_INSTR_txt->setWordWrap(false);
        FD_INSTR_txt->setTextInteractionFlags(Qt::TextEditable);

        D_VLayout->addWidget(FD_INSTR_txt);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        D_VLayout->addItem(verticalSpacer_2);

        frame = new QFrame(PipeCoreGbox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        LoadHazard = new QLabel(frame);
        LoadHazard->setObjectName(QStringLiteral("LoadHazard"));
        LoadHazard->setFrameShape(QFrame::Box);
        LoadHazard->setFrameShadow(QFrame::Sunken);
        LoadHazard->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LoadHazard, 0, 0, 1, 3);

        D_rs1_num = new QLabel(frame);
        D_rs1_num->setObjectName(QStringLiteral("D_rs1_num"));
        sizePolicy.setHeightForWidth(D_rs1_num->sizePolicy().hasHeightForWidth());
        D_rs1_num->setSizePolicy(sizePolicy);
        D_rs1_num->setFrameShape(QFrame::Box);
        D_rs1_num->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(D_rs1_num, 1, 0, 1, 1);

        D_rs2_num = new QLabel(frame);
        D_rs2_num->setObjectName(QStringLiteral("D_rs2_num"));
        sizePolicy.setHeightForWidth(D_rs2_num->sizePolicy().hasHeightForWidth());
        D_rs2_num->setSizePolicy(sizePolicy);
        D_rs2_num->setFrameShape(QFrame::Box);
        D_rs2_num->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(D_rs2_num, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);


        D_VLayout->addWidget(frame);

        D_rd_frame = new QFrame(PipeCoreGbox);
        D_rd_frame->setObjectName(QStringLiteral("D_rd_frame"));
        D_rd_frame->setFrameShape(QFrame::Box);
        D_rd_frame->setFrameShadow(QFrame::Sunken);
        gridLayout_11 = new QGridLayout(D_rd_frame);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        D_rd_num = new QLabel(D_rd_frame);
        D_rd_num->setObjectName(QStringLiteral("D_rd_num"));
        sizePolicy.setHeightForWidth(D_rd_num->sizePolicy().hasHeightForWidth());
        D_rd_num->setSizePolicy(sizePolicy);
        D_rd_num->setMinimumSize(QSize(40, 0));

        gridLayout_11->addWidget(D_rd_num, 0, 0, 1, 1);


        D_VLayout->addWidget(D_rd_frame);


        gridLayout_7->addLayout(D_VLayout, 1, 3, 1, 1);


        gridLayout->addWidget(PipeCoreGbox, 3, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        RunControlBtns = new QFrame(centralWidget);
        RunControlBtns->setObjectName(QStringLiteral("RunControlBtns"));
        RunControlBtns->setEnabled(false);
        RunControlBtns->setMaximumSize(QSize(16777215, 16777215));
        RunControlBtns->setFrameShape(QFrame::WinPanel);
        RunControlBtns->setFrameShadow(QFrame::Raised);
        RunControlBtns->setLineWidth(3);
        RunControlBtns->setMidLineWidth(2);
        gridLayout_4 = new QGridLayout(RunControlBtns);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        BtnNext = new QPushButton(RunControlBtns);
        BtnNext->setObjectName(QStringLiteral("BtnNext"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(BtnNext->sizePolicy().hasHeightForWidth());
        BtnNext->setSizePolicy(sizePolicy4);
        BtnNext->setMaximumSize(QSize(40, 16777215));
        BtnNext->setIconSize(QSize(15, 15));

        gridLayout_4->addWidget(BtnNext, 1, 3, 1, 1);

        BtnPause = new QPushButton(RunControlBtns);
        BtnPause->setObjectName(QStringLiteral("BtnPause"));
        sizePolicy4.setHeightForWidth(BtnPause->sizePolicy().hasHeightForWidth());
        BtnPause->setSizePolicy(sizePolicy4);
        BtnPause->setMaximumSize(QSize(40, 16777215));
        BtnPause->setIconSize(QSize(15, 15));

        gridLayout_4->addWidget(BtnPause, 1, 1, 1, 1);

        BtnRestart = new QPushButton(RunControlBtns);
        BtnRestart->setObjectName(QStringLiteral("BtnRestart"));
        sizePolicy4.setHeightForWidth(BtnRestart->sizePolicy().hasHeightForWidth());
        BtnRestart->setSizePolicy(sizePolicy4);
        BtnRestart->setMaximumSize(QSize(40, 16777215));
        BtnRestart->setIconSize(QSize(15, 15));

        gridLayout_4->addWidget(BtnRestart, 1, 2, 1, 1);

        label = new QLabel(RunControlBtns);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RunControlBtns);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(RunControlBtns);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(RunControlBtns);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setLineWidth(0);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 3, 1, 1);

        BtnPlay = new QPushButton(RunControlBtns);
        BtnPlay->setObjectName(QStringLiteral("BtnPlay"));
        sizePolicy4.setHeightForWidth(BtnPlay->sizePolicy().hasHeightForWidth());
        BtnPlay->setSizePolicy(sizePolicy4);
        BtnPlay->setMaximumSize(QSize(40, 16777215));
        BtnPlay->setIconSize(QSize(15, 15));

        gridLayout_4->addWidget(BtnPlay, 1, 0, 1, 1);


        gridLayout->addWidget(RunControlBtns, 0, 0, 1, 1);

        Fr_connDTM = new QWidget(centralWidget);
        Fr_connDTM->setObjectName(QStringLiteral("Fr_connDTM"));
        sizePolicy3.setHeightForWidth(Fr_connDTM->sizePolicy().hasHeightForWidth());
        Fr_connDTM->setSizePolicy(sizePolicy3);
        Fr_connDTM->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(Fr_connDTM, 0, 2, 1, 2);

        InstrDumpWidget = new QWidget(centralWidget);
        InstrDumpWidget->setObjectName(QStringLiteral("InstrDumpWidget"));
        InstrDumpWidget->setEnabled(false);
        gridLayout_17 = new QGridLayout(InstrDumpWidget);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        scrollArea = new QScrollArea(InstrDumpWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy5);
        scrollArea->setMaximumSize(QSize(16777215, 30));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 132, 28));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        FilePathProg = new QLabel(scrollAreaWidgetContents);
        FilePathProg->setObjectName(QStringLiteral("FilePathProg"));
        sizePolicy5.setHeightForWidth(FilePathProg->sizePolicy().hasHeightForWidth());
        FilePathProg->setSizePolicy(sizePolicy5);
        FilePathProg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        FilePathProg->setWordWrap(false);

        horizontalLayout_2->addWidget(FilePathProg);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_17->addWidget(scrollArea, 0, 0, 1, 1);

        OpenCodeBtn = new QPushButton(InstrDumpWidget);
        OpenCodeBtn->setObjectName(QStringLiteral("OpenCodeBtn"));

        gridLayout_17->addWidget(OpenCodeBtn, 0, 1, 1, 1);

        InstrViewTable = new QTableWidget(InstrDumpWidget);
        if (InstrViewTable->columnCount() < 3)
            InstrViewTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        InstrViewTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        InstrViewTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        InstrViewTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (InstrViewTable->rowCount() < 1)
            InstrViewTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        InstrViewTable->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        InstrViewTable->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        InstrViewTable->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        InstrViewTable->setItem(0, 2, __qtablewidgetitem6);
        InstrViewTable->setObjectName(QStringLiteral("InstrViewTable"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(InstrViewTable->sizePolicy().hasHeightForWidth());
        InstrViewTable->setSizePolicy(sizePolicy6);
        InstrViewTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        InstrViewTable->setProperty("showDropIndicator", QVariant(false));
        InstrViewTable->setDragDropOverwriteMode(false);
        InstrViewTable->setDragDropMode(QAbstractItemView::NoDragDrop);
        InstrViewTable->setAlternatingRowColors(true);
        InstrViewTable->setSelectionMode(QAbstractItemView::NoSelection);
        InstrViewTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        InstrViewTable->setGridStyle(Qt::DashDotDotLine);
        InstrViewTable->setCornerButtonEnabled(false);
        InstrViewTable->horizontalHeader()->setVisible(false);
        InstrViewTable->horizontalHeader()->setCascadingSectionResizes(true);
        InstrViewTable->horizontalHeader()->setMinimumSectionSize(12);
        InstrViewTable->horizontalHeader()->setStretchLastSection(false);
        InstrViewTable->verticalHeader()->setVisible(false);
        InstrViewTable->verticalHeader()->setCascadingSectionResizes(true);
        InstrViewTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        InstrViewTable->verticalHeader()->setStretchLastSection(false);

        gridLayout_17->addWidget(InstrViewTable, 1, 0, 1, 2);


        gridLayout->addWidget(InstrDumpWidget, 4, 3, 2, 1);

        REGSwidget = new QWidget(centralWidget);
        REGSwidget->setObjectName(QStringLiteral("REGSwidget"));
        REGSwidget->setEnabled(false);
        verticalLayout_6 = new QVBoxLayout(REGSwidget);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        HexCheckBox = new QCheckBox(REGSwidget);
        HexCheckBox->setObjectName(QStringLiteral("HexCheckBox"));

        verticalLayout_6->addWidget(HexCheckBox);

        RegsTable = new QTableWidget(REGSwidget);
        if (RegsTable->columnCount() < 1)
            RegsTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        RegsTable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        if (RegsTable->rowCount() < 32)
            RegsTable->setRowCount(32);
        QFont font;
        font.setFamily(QStringLiteral("Noto Mono"));
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font);
        RegsTable->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem9->setFont(font);
        RegsTable->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        RegsTable->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        RegsTable->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        RegsTable->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        RegsTable->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        RegsTable->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        RegsTable->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        RegsTable->setVerticalHeaderItem(8, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        RegsTable->setVerticalHeaderItem(9, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        RegsTable->setVerticalHeaderItem(10, __qtablewidgetitem18);
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Mono"));
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        RegsTable->setVerticalHeaderItem(11, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        RegsTable->setVerticalHeaderItem(12, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        RegsTable->setVerticalHeaderItem(13, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font);
        RegsTable->setVerticalHeaderItem(14, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        RegsTable->setVerticalHeaderItem(15, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        RegsTable->setVerticalHeaderItem(16, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font);
        RegsTable->setVerticalHeaderItem(17, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font);
        RegsTable->setVerticalHeaderItem(18, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font);
        RegsTable->setVerticalHeaderItem(19, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font);
        RegsTable->setVerticalHeaderItem(20, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font);
        RegsTable->setVerticalHeaderItem(21, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font);
        RegsTable->setVerticalHeaderItem(22, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font);
        RegsTable->setVerticalHeaderItem(23, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font);
        RegsTable->setVerticalHeaderItem(24, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font);
        RegsTable->setVerticalHeaderItem(25, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font);
        RegsTable->setVerticalHeaderItem(26, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font);
        RegsTable->setVerticalHeaderItem(27, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font);
        RegsTable->setVerticalHeaderItem(28, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font);
        RegsTable->setVerticalHeaderItem(29, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font);
        RegsTable->setVerticalHeaderItem(30, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font);
        RegsTable->setVerticalHeaderItem(31, __qtablewidgetitem39);
        RegsTable->setObjectName(QStringLiteral("RegsTable"));
        sizePolicy3.setHeightForWidth(RegsTable->sizePolicy().hasHeightForWidth());
        RegsTable->setSizePolicy(sizePolicy3);
        RegsTable->setMinimumSize(QSize(0, 0));
        RegsTable->setMouseTracking(false);
        RegsTable->setFocusPolicy(Qt::NoFocus);
        RegsTable->setFrameShape(QFrame::Box);
        RegsTable->setFrameShadow(QFrame::Sunken);
        RegsTable->setLineWidth(1);
        RegsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        RegsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        RegsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RegsTable->setProperty("showDropIndicator", QVariant(false));
        RegsTable->setDragDropOverwriteMode(false);
        RegsTable->setAlternatingRowColors(true);
        RegsTable->setSelectionMode(QAbstractItemView::NoSelection);
        RegsTable->setGridStyle(Qt::DashLine);
        RegsTable->setWordWrap(false);
        RegsTable->setCornerButtonEnabled(false);
        RegsTable->horizontalHeader()->setVisible(false);
        RegsTable->horizontalHeader()->setCascadingSectionResizes(true);
        RegsTable->horizontalHeader()->setHighlightSections(true);
        RegsTable->horizontalHeader()->setMinimumSectionSize(12);
        RegsTable->horizontalHeader()->setStretchLastSection(true);
        RegsTable->verticalHeader()->setCascadingSectionResizes(false);
        RegsTable->verticalHeader()->setDefaultSectionSize(25);
        RegsTable->verticalHeader()->setHighlightSections(true);
        RegsTable->verticalHeader()->setMinimumSectionSize(25);
        RegsTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        RegsTable->verticalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(RegsTable);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setVerticalSpacing(1);
        val_cycle = new QLabel(REGSwidget);
        val_cycle->setObjectName(QStringLiteral("val_cycle"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(val_cycle->sizePolicy().hasHeightForWidth());
        val_cycle->setSizePolicy(sizePolicy7);
        val_cycle->setMaximumSize(QSize(128, 16777215));
        val_cycle->setAutoFillBackground(false);
        val_cycle->setFrameShape(QFrame::Box);
        val_cycle->setFrameShadow(QFrame::Sunken);
        val_cycle->setLineWidth(1);
        val_cycle->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(val_cycle, 0, 1, 1, 1);

        label_66 = new QLabel(REGSwidget);
        label_66->setObjectName(QStringLiteral("label_66"));
        sizePolicy4.setHeightForWidth(label_66->sizePolicy().hasHeightForWidth());
        label_66->setSizePolicy(sizePolicy4);
        label_66->setMaximumSize(QSize(60, 16777215));
        label_66->setAutoFillBackground(false);
        label_66->setFrameShape(QFrame::Box);
        label_66->setFrameShadow(QFrame::Sunken);
        label_66->setLineWidth(1);

        gridLayout_3->addWidget(label_66, 1, 0, 1, 1);

        label_64 = new QLabel(REGSwidget);
        label_64->setObjectName(QStringLiteral("label_64"));
        sizePolicy4.setHeightForWidth(label_64->sizePolicy().hasHeightForWidth());
        label_64->setSizePolicy(sizePolicy4);
        label_64->setMaximumSize(QSize(60, 16777215));
        label_64->setAutoFillBackground(false);
        label_64->setFrameShape(QFrame::Box);
        label_64->setFrameShadow(QFrame::Sunken);
        label_64->setLineWidth(1);

        gridLayout_3->addWidget(label_64, 0, 0, 1, 1);

        val_dcsr = new QLabel(REGSwidget);
        val_dcsr->setObjectName(QStringLiteral("val_dcsr"));
        sizePolicy7.setHeightForWidth(val_dcsr->sizePolicy().hasHeightForWidth());
        val_dcsr->setSizePolicy(sizePolicy7);
        val_dcsr->setMaximumSize(QSize(128, 16777215));
        val_dcsr->setAutoFillBackground(false);
        val_dcsr->setFrameShape(QFrame::Box);
        val_dcsr->setFrameShadow(QFrame::Sunken);
        val_dcsr->setLineWidth(1);
        val_dcsr->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(val_dcsr, 2, 1, 1, 1);

        label_68 = new QLabel(REGSwidget);
        label_68->setObjectName(QStringLiteral("label_68"));
        sizePolicy4.setHeightForWidth(label_68->sizePolicy().hasHeightForWidth());
        label_68->setSizePolicy(sizePolicy4);
        label_68->setMaximumSize(QSize(60, 16777215));
        label_68->setAutoFillBackground(false);
        label_68->setFrameShape(QFrame::Box);
        label_68->setFrameShadow(QFrame::Sunken);
        label_68->setLineWidth(1);

        gridLayout_3->addWidget(label_68, 2, 0, 1, 1);

        val_instret = new QLabel(REGSwidget);
        val_instret->setObjectName(QStringLiteral("val_instret"));
        sizePolicy7.setHeightForWidth(val_instret->sizePolicy().hasHeightForWidth());
        val_instret->setSizePolicy(sizePolicy7);
        val_instret->setMaximumSize(QSize(128, 16777215));
        val_instret->setAutoFillBackground(false);
        val_instret->setFrameShape(QFrame::Box);
        val_instret->setFrameShadow(QFrame::Sunken);
        val_instret->setLineWidth(1);
        val_instret->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(val_instret, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);


        gridLayout->addWidget(REGSwidget, 4, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(BtnPlay, BtnPause);
        QWidget::setTabOrder(BtnPause, BtnRestart);
        QWidget::setTabOrder(BtnRestart, BtnNext);
        QWidget::setTabOrder(BtnNext, HexCheckBox);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Reiniciar Procesador</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_52->setText(QApplication::translate("MainWindow", "PC", 0));
        EM_PC_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_54->setText(QApplication::translate("MainWindow", "instr", 0));
        EM_INSTR_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        EM_INSTR_txt->setText(QApplication::translate("MainWindow", "instr", 0));
        Memory->setText(QApplication::translate("MainWindow", "Memory", 0));
        Mem_addr_lbl->setText(QApplication::translate("MainWindow", "Addr", 0));
        Mem_addr_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        Mem_data_lbl->setText(QApplication::translate("MainWindow", "Data", 0));
        Mem_data_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        Mem_tam_lbl->setText(QApplication::translate("MainWindow", "Tam", 0));
        Mem_tam_txt->setText(QApplication::translate("MainWindow", "--", 0));
        label_12->setText(QApplication::translate("MainWindow", " = ", 0));
        M_rd_mem->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_9->setText(QApplication::translate("MainWindow", "Registro a escribir:", 0));
        M_rd_num->setText(QApplication::translate("MainWindow", "rd: --", 0));
        W_Label->setText(QApplication::translate("MainWindow", "WriteBack", 0));
        M_Label->setText(QApplication::translate("MainWindow", "Memory", 0));
        label_40->setText(QApplication::translate("MainWindow", "PC", 0));
        F_PC_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_33->setText(QApplication::translate("MainWindow", "PC Next", 0));
        F_PCNEXT_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        F_INSTR_txt->setText(QApplication::translate("MainWindow", "instr", 0));
        label_57->setText(QApplication::translate("MainWindow", "PC", 0));
        MW_PC_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_59->setText(QApplication::translate("MainWindow", "instr", 0));
        MW_INSTR_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        MW_INSTR_txt->setText(QApplication::translate("MainWindow", "instr", 0));
        W_rd_num->setText(QApplication::translate("MainWindow", "rd: --", 0));
        label_10->setText(QApplication::translate("MainWindow", " = ", 0));
        W_rd_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_8->setText(QApplication::translate("MainWindow", "Registro escrito:", 0));
        label_47->setText(QApplication::translate("MainWindow", "PC", 0));
        DE_PC_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_49->setText(QApplication::translate("MainWindow", "instr", 0));
        DE_INSTR_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        DE_INSTR_txt->setText(QApplication::translate("MainWindow", "instr", 0));
        J_JALR->setText(QApplication::translate("MainWindow", "JALR", 0));
        J_JumpOrBranch->setText(QApplication::translate("MainWindow", "Salto debido a", 0));
        J_Branch->setText(QApplication::translate("MainWindow", "Branch", 0));
        J_JAL->setText(QApplication::translate("MainWindow", "JAL", 0));
        E_rs1_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        rs1_FWD_M->setText(QApplication::translate("MainWindow", "M", 0));
        rs1_FWD_W->setText(QApplication::translate("MainWindow", "W", 0));
        E_rs1_num->setText(QApplication::translate("MainWindow", "rs1: --", 0));
        label_22->setText(QApplication::translate("MainWindow", "Forwarding", 0));
        E_rs2_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        rs2_FWD_M->setText(QApplication::translate("MainWindow", "M", 0));
        rs2_FWD_W->setText(QApplication::translate("MainWindow", "W", 0));
        E_rs2_num->setText(QApplication::translate("MainWindow", "rs2: --", 0));
        E_rd_num->setText(QApplication::translate("MainWindow", "rd: --", 0));
        E_Label->setText(QApplication::translate("MainWindow", "Execute", 0));
        F_Label->setText(QApplication::translate("MainWindow", "Fetch", 0));
        D_Label->setText(QApplication::translate("MainWindow", "Decode", 0));
        label_42->setText(QApplication::translate("MainWindow", "PC", 0));
        FD_PC_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_44->setText(QApplication::translate("MainWindow", "instr", 0));
        FD_INSTR_val->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        FD_INSTR_txt->setText(QApplication::translate("MainWindow", "instr", 0));
        LoadHazard->setText(QApplication::translate("MainWindow", "Hazard", 0));
        D_rs1_num->setText(QApplication::translate("MainWindow", "rs1: --", 0));
        D_rs2_num->setText(QApplication::translate("MainWindow", "rs2: --", 0));
        D_rd_num->setText(QApplication::translate("MainWindow", "rd: --", 0));
#ifndef QT_NO_WHATSTHIS
        BtnNext->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Siguiente Ciclo...</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        BtnNext->setText(QString());
#ifndef QT_NO_WHATSTHIS
        BtnPause->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>pausar procesador</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        BtnPause->setText(QString());
        BtnRestart->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Play", 0));
        label_2->setText(QApplication::translate("MainWindow", "Pause", 0));
        label_3->setText(QApplication::translate("MainWindow", "restart", 0));
        label_4->setText(QApplication::translate("MainWindow", "Next", 0));
#ifndef QT_NO_WHATSTHIS
        BtnPlay->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Continuar</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        BtnPlay->setText(QString());
        FilePathProg->setText(QApplication::translate("MainWindow", "nombre del archivo", 0));
        OpenCodeBtn->setText(QApplication::translate("MainWindow", "Abrir Hexdump", 0));
        QTableWidgetItem *___qtablewidgetitem = InstrViewTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Direccion", 0));
        QTableWidgetItem *___qtablewidgetitem1 = InstrViewTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Instruccion (Hex)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = InstrViewTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Instruccion", 0));

        const bool __sortingEnabled = InstrViewTable->isSortingEnabled();
        InstrViewTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = InstrViewTable->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        QTableWidgetItem *___qtablewidgetitem4 = InstrViewTable->item(0, 1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        QTableWidgetItem *___qtablewidgetitem5 = InstrViewTable->item(0, 2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "----", 0));
        InstrViewTable->setSortingEnabled(__sortingEnabled);

        HexCheckBox->setText(QApplication::translate("MainWindow", "Hexadecimal Value", 0));
        QTableWidgetItem *___qtablewidgetitem6 = RegsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Valor", 0));
        QTableWidgetItem *___qtablewidgetitem7 = RegsTable->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "x0  / Zero", 0));
        QTableWidgetItem *___qtablewidgetitem8 = RegsTable->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "x1  / ra", 0));
        QTableWidgetItem *___qtablewidgetitem9 = RegsTable->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "x2  / sp", 0));
        QTableWidgetItem *___qtablewidgetitem10 = RegsTable->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "x3  / gp", 0));
        QTableWidgetItem *___qtablewidgetitem11 = RegsTable->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "x4  / tp", 0));
        QTableWidgetItem *___qtablewidgetitem12 = RegsTable->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "x5  / t0", 0));
        QTableWidgetItem *___qtablewidgetitem13 = RegsTable->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "x6  / t1", 0));
        QTableWidgetItem *___qtablewidgetitem14 = RegsTable->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "x7  / t2", 0));
        QTableWidgetItem *___qtablewidgetitem15 = RegsTable->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "x8  / s0", 0));
        QTableWidgetItem *___qtablewidgetitem16 = RegsTable->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "x9  / s1", 0));
        QTableWidgetItem *___qtablewidgetitem17 = RegsTable->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "x10 / a0", 0));
        QTableWidgetItem *___qtablewidgetitem18 = RegsTable->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "x11 / a1", 0));
        QTableWidgetItem *___qtablewidgetitem19 = RegsTable->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "x12 / a2", 0));
        QTableWidgetItem *___qtablewidgetitem20 = RegsTable->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "x13 / a3", 0));
        QTableWidgetItem *___qtablewidgetitem21 = RegsTable->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "x14 / a4", 0));
        QTableWidgetItem *___qtablewidgetitem22 = RegsTable->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "x15 / a5", 0));
        QTableWidgetItem *___qtablewidgetitem23 = RegsTable->verticalHeaderItem(16);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "x16 / a6", 0));
        QTableWidgetItem *___qtablewidgetitem24 = RegsTable->verticalHeaderItem(17);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "x17 / a7", 0));
        QTableWidgetItem *___qtablewidgetitem25 = RegsTable->verticalHeaderItem(18);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "x18 / s2", 0));
        QTableWidgetItem *___qtablewidgetitem26 = RegsTable->verticalHeaderItem(19);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "x19 / s3", 0));
        QTableWidgetItem *___qtablewidgetitem27 = RegsTable->verticalHeaderItem(20);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "x20 / s4", 0));
        QTableWidgetItem *___qtablewidgetitem28 = RegsTable->verticalHeaderItem(21);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "x21 / s5", 0));
        QTableWidgetItem *___qtablewidgetitem29 = RegsTable->verticalHeaderItem(22);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "x22 / s6", 0));
        QTableWidgetItem *___qtablewidgetitem30 = RegsTable->verticalHeaderItem(23);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "x23 / s7", 0));
        QTableWidgetItem *___qtablewidgetitem31 = RegsTable->verticalHeaderItem(24);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "x24 / s8", 0));
        QTableWidgetItem *___qtablewidgetitem32 = RegsTable->verticalHeaderItem(25);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "x25 / s9", 0));
        QTableWidgetItem *___qtablewidgetitem33 = RegsTable->verticalHeaderItem(26);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "x26 / s10", 0));
        QTableWidgetItem *___qtablewidgetitem34 = RegsTable->verticalHeaderItem(27);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "x27 / s11", 0));
        QTableWidgetItem *___qtablewidgetitem35 = RegsTable->verticalHeaderItem(28);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "x28 / t3", 0));
        QTableWidgetItem *___qtablewidgetitem36 = RegsTable->verticalHeaderItem(29);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "x29 / t4", 0));
        QTableWidgetItem *___qtablewidgetitem37 = RegsTable->verticalHeaderItem(30);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "x30 / t5", 0));
        QTableWidgetItem *___qtablewidgetitem38 = RegsTable->verticalHeaderItem(31);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "x31 / t6", 0));
        val_cycle->setText(QApplication::translate("MainWindow", "-", 0));
        label_66->setText(QApplication::translate("MainWindow", "INSTRET", 0));
        label_64->setText(QApplication::translate("MainWindow", "CYCLE", 0));
        val_dcsr->setText(QApplication::translate("MainWindow", "0x00000000", 0));
        label_68->setText(QApplication::translate("MainWindow", "DCSR", 0));
        val_instret->setText(QApplication::translate("MainWindow", "0x0000000000000000", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
