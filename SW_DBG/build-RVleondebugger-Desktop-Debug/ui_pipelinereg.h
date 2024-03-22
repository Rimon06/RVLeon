/********************************************************************************
** Form generated from reading UI file 'pipelinereg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIPELINEREG_H
#define UI_PIPELINEREG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PipelineReg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *StallFrame;
    QGridLayout *gridLayout;
    QLabel *StallLabel;
    QLabel *StallArrow;
    QFrame *FlushFrame;
    QGridLayout *gridLayout_2;
    QLabel *FlushArrow;
    QLabel *FlushLabel;
    QSpacerItem *verticalSpacer;
    QFrame *Funct3;
    QGridLayout *gridLayout_7;
    QLabel *Funct3Label;
    QLabel *Funct3Val;
    QFrame *MemRead;
    QGridLayout *gridLayout_6;
    QLabel *MemReadLabel;
    QFrame *MemWrite;
    QGridLayout *gridLayout_5;
    QLabel *MemWriteLabel;
    QFrame *RegWrite;
    QGridLayout *gridLayout_4;
    QLabel *RegWriteLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QFrame *NOPFrame;
    QGridLayout *gridLayout_3;
    QLabel *NOPLabel;

    void setupUi(QWidget *PipelineReg)
    {
        if (PipelineReg->objectName().isEmpty())
            PipelineReg->setObjectName(QStringLiteral("PipelineReg"));
        PipelineReg->resize(44, 332);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PipelineReg->sizePolicy().hasHeightForWidth());
        PipelineReg->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(PipelineReg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        StallFrame = new QFrame(PipelineReg);
        StallFrame->setObjectName(QStringLiteral("StallFrame"));
        StallFrame->setFrameShape(QFrame::Panel);
        StallFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(StallFrame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        StallLabel = new QLabel(StallFrame);
        StallLabel->setObjectName(QStringLiteral("StallLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(StallLabel->sizePolicy().hasHeightForWidth());
        StallLabel->setSizePolicy(sizePolicy1);
        StallLabel->setMinimumSize(QSize(35, 0));
        StallLabel->setMaximumSize(QSize(30, 16777215));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        StallLabel->setFont(font);
        StallLabel->setAutoFillBackground(false);
        StallLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(StallLabel, 1, 0, 1, 1);

        StallArrow = new QLabel(StallFrame);
        StallArrow->setObjectName(QStringLiteral("StallArrow"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(StallArrow->sizePolicy().hasHeightForWidth());
        StallArrow->setSizePolicy(sizePolicy2);
        StallArrow->setMinimumSize(QSize(35, 0));
        StallArrow->setFont(font);
        StallArrow->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(StallArrow, 0, 0, 1, 1);


        verticalLayout->addWidget(StallFrame);

        FlushFrame = new QFrame(PipelineReg);
        FlushFrame->setObjectName(QStringLiteral("FlushFrame"));
        FlushFrame->setFrameShape(QFrame::Panel);
        FlushFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(FlushFrame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        FlushArrow = new QLabel(FlushFrame);
        FlushArrow->setObjectName(QStringLiteral("FlushArrow"));
        sizePolicy2.setHeightForWidth(FlushArrow->sizePolicy().hasHeightForWidth());
        FlushArrow->setSizePolicy(sizePolicy2);
        FlushArrow->setMinimumSize(QSize(35, 0));
        FlushArrow->setFont(font);
        FlushArrow->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(FlushArrow, 0, 0, 1, 1);

        FlushLabel = new QLabel(FlushFrame);
        FlushLabel->setObjectName(QStringLiteral("FlushLabel"));
        sizePolicy1.setHeightForWidth(FlushLabel->sizePolicy().hasHeightForWidth());
        FlushLabel->setSizePolicy(sizePolicy1);
        FlushLabel->setMinimumSize(QSize(35, 0));
        FlushLabel->setMaximumSize(QSize(30, 16777215));
        FlushLabel->setFont(font);
        FlushLabel->setAutoFillBackground(false);
        FlushLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(FlushLabel, 1, 0, 1, 1);


        verticalLayout->addWidget(FlushFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Funct3 = new QFrame(PipelineReg);
        Funct3->setObjectName(QStringLiteral("Funct3"));
        Funct3->setFrameShape(QFrame::Panel);
        Funct3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(Funct3);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        Funct3Label = new QLabel(Funct3);
        Funct3Label->setObjectName(QStringLiteral("Funct3Label"));
        sizePolicy1.setHeightForWidth(Funct3Label->sizePolicy().hasHeightForWidth());
        Funct3Label->setSizePolicy(sizePolicy1);
        Funct3Label->setMinimumSize(QSize(35, 0));
        Funct3Label->setMaximumSize(QSize(30, 16777215));
        Funct3Label->setFont(font);
        Funct3Label->setAutoFillBackground(false);
        Funct3Label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Funct3Label, 0, 0, 1, 1);

        Funct3Val = new QLabel(Funct3);
        Funct3Val->setObjectName(QStringLiteral("Funct3Val"));
        sizePolicy1.setHeightForWidth(Funct3Val->sizePolicy().hasHeightForWidth());
        Funct3Val->setSizePolicy(sizePolicy1);
        Funct3Val->setMinimumSize(QSize(40, 0));
        Funct3Val->setMaximumSize(QSize(30, 16777215));
        Funct3Val->setFont(font);
        Funct3Val->setAutoFillBackground(false);
        Funct3Val->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Funct3Val, 1, 0, 1, 1);


        verticalLayout->addWidget(Funct3);

        MemRead = new QFrame(PipelineReg);
        MemRead->setObjectName(QStringLiteral("MemRead"));
        MemRead->setFrameShape(QFrame::Panel);
        MemRead->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(MemRead);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        MemReadLabel = new QLabel(MemRead);
        MemReadLabel->setObjectName(QStringLiteral("MemReadLabel"));
        sizePolicy1.setHeightForWidth(MemReadLabel->sizePolicy().hasHeightForWidth());
        MemReadLabel->setSizePolicy(sizePolicy1);
        MemReadLabel->setMinimumSize(QSize(35, 0));
        MemReadLabel->setMaximumSize(QSize(30, 16777215));
        MemReadLabel->setFont(font);
        MemReadLabel->setAutoFillBackground(false);
        MemReadLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(MemReadLabel, 0, 0, 1, 1);


        verticalLayout->addWidget(MemRead);

        MemWrite = new QFrame(PipelineReg);
        MemWrite->setObjectName(QStringLiteral("MemWrite"));
        MemWrite->setFrameShape(QFrame::Panel);
        MemWrite->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(MemWrite);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        MemWriteLabel = new QLabel(MemWrite);
        MemWriteLabel->setObjectName(QStringLiteral("MemWriteLabel"));
        sizePolicy1.setHeightForWidth(MemWriteLabel->sizePolicy().hasHeightForWidth());
        MemWriteLabel->setSizePolicy(sizePolicy1);
        MemWriteLabel->setMinimumSize(QSize(35, 0));
        MemWriteLabel->setMaximumSize(QSize(30, 16777215));
        MemWriteLabel->setFont(font);
        MemWriteLabel->setAutoFillBackground(false);
        MemWriteLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(MemWriteLabel, 0, 0, 1, 1);


        verticalLayout->addWidget(MemWrite);

        RegWrite = new QFrame(PipelineReg);
        RegWrite->setObjectName(QStringLiteral("RegWrite"));
        RegWrite->setFrameShape(QFrame::Panel);
        RegWrite->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(RegWrite);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        RegWriteLabel = new QLabel(RegWrite);
        RegWriteLabel->setObjectName(QStringLiteral("RegWriteLabel"));
        sizePolicy1.setHeightForWidth(RegWriteLabel->sizePolicy().hasHeightForWidth());
        RegWriteLabel->setSizePolicy(sizePolicy1);
        RegWriteLabel->setMinimumSize(QSize(35, 0));
        RegWriteLabel->setMaximumSize(QSize(30, 16777215));
        RegWriteLabel->setFont(font);
        RegWriteLabel->setAutoFillBackground(false);
        RegWriteLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(RegWriteLabel, 0, 0, 1, 1);


        verticalLayout->addWidget(RegWrite);

        widget = new QWidget(PipelineReg);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget);

        NOPFrame = new QFrame(PipelineReg);
        NOPFrame->setObjectName(QStringLiteral("NOPFrame"));
        NOPFrame->setFrameShape(QFrame::Panel);
        NOPFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(NOPFrame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        NOPLabel = new QLabel(NOPFrame);
        NOPLabel->setObjectName(QStringLiteral("NOPLabel"));
        sizePolicy1.setHeightForWidth(NOPLabel->sizePolicy().hasHeightForWidth());
        NOPLabel->setSizePolicy(sizePolicy1);
        NOPLabel->setMinimumSize(QSize(35, 0));
        NOPLabel->setMaximumSize(QSize(30, 16777215));
        NOPLabel->setFont(font);
        NOPLabel->setAutoFillBackground(false);
        NOPLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NOPLabel, 1, 0, 1, 1);


        verticalLayout->addWidget(NOPFrame);


        retranslateUi(PipelineReg);

        QMetaObject::connectSlotsByName(PipelineReg);
    } // setupUi

    void retranslateUi(QWidget *PipelineReg)
    {
        PipelineReg->setWindowTitle(QApplication::translate("PipelineReg", "Form", 0));
        StallLabel->setText(QApplication::translate("PipelineReg", "Stall", 0));
        StallArrow->setText(QApplication::translate("PipelineReg", "------>", 0));
        FlushArrow->setText(QApplication::translate("PipelineReg", "------>", 0));
        FlushLabel->setText(QApplication::translate("PipelineReg", "Flush", 0));
        Funct3Label->setText(QApplication::translate("PipelineReg", "funct3", 0));
        Funct3Val->setText(QApplication::translate("PipelineReg", "-", 0));
        MemReadLabel->setText(QApplication::translate("PipelineReg", "memR", 0));
        MemWriteLabel->setText(QApplication::translate("PipelineReg", "memW", 0));
        RegWriteLabel->setText(QApplication::translate("PipelineReg", "regW", 0));
        NOPLabel->setText(QApplication::translate("PipelineReg", "NOP", 0));
    } // retranslateUi

};

namespace Ui {
    class PipelineReg: public Ui_PipelineReg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIPELINEREG_H
