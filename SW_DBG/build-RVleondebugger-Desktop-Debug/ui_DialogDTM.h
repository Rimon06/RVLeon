/********************************************************************************
** Form generated from reading UI file 'DialogDTM.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDTM_H
#define UI_DIALOGDTM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogDTM
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BtnCnnctDTM;
    QPushButton *BtnDiscnntDTM;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Lbl_DTMState;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *Lbl_DBGState;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DialogDTM)
    {
        if (DialogDTM->objectName().isEmpty())
            DialogDTM->setObjectName(QStringLiteral("DialogDTM"));
        DialogDTM->setEnabled(true);
        DialogDTM->resize(1126, 31);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogDTM->sizePolicy().hasHeightForWidth());
        DialogDTM->setSizePolicy(sizePolicy);
        DialogDTM->setWindowTitle(QStringLiteral("Conectar Depurador"));
        horizontalLayout_5 = new QHBoxLayout(DialogDTM);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        BtnCnnctDTM = new QPushButton(DialogDTM);
        BtnCnnctDTM->setObjectName(QStringLiteral("BtnCnnctDTM"));
        BtnCnnctDTM->setMinimumSize(QSize(100, 0));
        BtnCnnctDTM->setMaximumSize(QSize(135, 16777215));

        horizontalLayout_2->addWidget(BtnCnnctDTM);

        BtnDiscnntDTM = new QPushButton(DialogDTM);
        BtnDiscnntDTM->setObjectName(QStringLiteral("BtnDiscnntDTM"));
        BtnDiscnntDTM->setEnabled(false);
        sizePolicy.setHeightForWidth(BtnDiscnntDTM->sizePolicy().hasHeightForWidth());
        BtnDiscnntDTM->setSizePolicy(sizePolicy);
        BtnDiscnntDTM->setMinimumSize(QSize(100, 0));
        BtnDiscnntDTM->setMaximumSize(QSize(135, 16777215));

        horizontalLayout_2->addWidget(BtnDiscnntDTM);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogDTM);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(90, 0));
        label->setMaximumSize(QSize(90, 16777215));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setLineWidth(2);
        label->setMidLineWidth(0);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        Lbl_DTMState = new QLabel(DialogDTM);
        Lbl_DTMState->setObjectName(QStringLiteral("Lbl_DTMState"));
        Lbl_DTMState->setEnabled(true);
        sizePolicy1.setHeightForWidth(Lbl_DTMState->sizePolicy().hasHeightForWidth());
        Lbl_DTMState->setSizePolicy(sizePolicy1);
        Lbl_DTMState->setMinimumSize(QSize(110, 0));
        Lbl_DTMState->setMaximumSize(QSize(110, 16777215));
        Lbl_DTMState->setFrameShape(QFrame::Panel);
        Lbl_DTMState->setFrameShadow(QFrame::Raised);
        Lbl_DTMState->setLineWidth(2);

        horizontalLayout->addWidget(Lbl_DTMState);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(DialogDTM);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(90, 0));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setLineWidth(2);
        label_3->setMidLineWidth(0);

        horizontalLayout_3->addWidget(label_3);

        Lbl_DBGState = new QLabel(DialogDTM);
        Lbl_DBGState->setObjectName(QStringLiteral("Lbl_DBGState"));
        Lbl_DBGState->setEnabled(true);
        sizePolicy1.setHeightForWidth(Lbl_DBGState->sizePolicy().hasHeightForWidth());
        Lbl_DBGState->setSizePolicy(sizePolicy1);
        Lbl_DBGState->setMinimumSize(QSize(110, 0));
        Lbl_DBGState->setMaximumSize(QSize(110, 16777215));
        Lbl_DBGState->setFrameShape(QFrame::Panel);
        Lbl_DBGState->setFrameShadow(QFrame::Raised);
        Lbl_DBGState->setLineWidth(2);
        Lbl_DBGState->setMidLineWidth(0);

        horizontalLayout_3->addWidget(Lbl_DBGState);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(499, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        retranslateUi(DialogDTM);

        QMetaObject::connectSlotsByName(DialogDTM);
    } // setupUi

    void retranslateUi(QDialog *DialogDTM)
    {
        BtnCnnctDTM->setText(QApplication::translate("DialogDTM", "Conectar DTM", 0));
        BtnDiscnntDTM->setText(QApplication::translate("DialogDTM", "Desconectar DTM", 0));
        label->setText(QApplication::translate("DialogDTM", "Estado DTM:", 0));
        Lbl_DTMState->setText(QApplication::translate("DialogDTM", "--------------", 0));
        label_3->setText(QApplication::translate("DialogDTM", "Debug Mode:", 0));
        Lbl_DBGState->setText(QApplication::translate("DialogDTM", "--------------", 0));
        Q_UNUSED(DialogDTM);
    } // retranslateUi

};

namespace Ui {
    class DialogDTM: public Ui_DialogDTM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDTM_H
