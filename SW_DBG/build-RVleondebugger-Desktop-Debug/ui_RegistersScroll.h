/********************************************************************************
** Form generated from reading UI file 'RegistersScroll.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERSSCROLL_H
#define UI_REGISTERSSCROLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistersScroll
{
public:
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QCheckBox *HexCheckBox;
    QTableWidget *RegsTable;

    void setupUi(QScrollArea *RegistersScroll)
    {
        if (RegistersScroll->objectName().isEmpty())
            RegistersScroll->setObjectName(QStringLiteral("RegistersScroll"));
        RegistersScroll->resize(276, 251);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegistersScroll->sizePolicy().hasHeightForWidth());
        RegistersScroll->setSizePolicy(sizePolicy);
        RegistersScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 274, 249));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        HexCheckBox = new QCheckBox(scrollAreaWidgetContents);
        HexCheckBox->setObjectName(QStringLiteral("HexCheckBox"));

        gridLayout->addWidget(HexCheckBox, 0, 0, 1, 1);

        RegsTable = new QTableWidget(scrollAreaWidgetContents);
        if (RegsTable->columnCount() < 1)
            RegsTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        RegsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (RegsTable->rowCount() < 32)
            RegsTable->setRowCount(32);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        RegsTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        RegsTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        RegsTable->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(20, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(21, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(22, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(23, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(24, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(25, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(26, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(27, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(28, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(29, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(30, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        RegsTable->setVerticalHeaderItem(31, __qtablewidgetitem32);
        RegsTable->setObjectName(QStringLiteral("RegsTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RegsTable->sizePolicy().hasHeightForWidth());
        RegsTable->setSizePolicy(sizePolicy1);
        RegsTable->setMinimumSize(QSize(0, 0));
        RegsTable->setFocusPolicy(Qt::NoFocus);
        RegsTable->setFrameShape(QFrame::NoFrame);
        RegsTable->setFrameShadow(QFrame::Raised);
        RegsTable->setLineWidth(0);
        RegsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RegsTable->setProperty("showDropIndicator", QVariant(false));
        RegsTable->setDragDropOverwriteMode(false);
        RegsTable->setAlternatingRowColors(true);
        RegsTable->setSelectionMode(QAbstractItemView::NoSelection);
        RegsTable->setGridStyle(Qt::DashLine);
        RegsTable->setCornerButtonEnabled(false);
        RegsTable->horizontalHeader()->setVisible(false);
        RegsTable->horizontalHeader()->setCascadingSectionResizes(true);
        RegsTable->horizontalHeader()->setHighlightSections(true);
        RegsTable->horizontalHeader()->setMinimumSectionSize(12);
        RegsTable->horizontalHeader()->setStretchLastSection(true);
        RegsTable->verticalHeader()->setVisible(true);
        RegsTable->verticalHeader()->setCascadingSectionResizes(true);
        RegsTable->verticalHeader()->setDefaultSectionSize(20);
        RegsTable->verticalHeader()->setHighlightSections(true);
        RegsTable->verticalHeader()->setMinimumSectionSize(40);
        RegsTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        RegsTable->verticalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(RegsTable, 1, 0, 1, 1);

        RegistersScroll->setWidget(scrollAreaWidgetContents);

        retranslateUi(RegistersScroll);

        QMetaObject::connectSlotsByName(RegistersScroll);
    } // setupUi

    void retranslateUi(QScrollArea *RegistersScroll)
    {
        RegistersScroll->setWindowTitle(QApplication::translate("RegistersScroll", "ScrollArea", 0));
        HexCheckBox->setText(QApplication::translate("RegistersScroll", "Hexadecimal Value", 0));
        QTableWidgetItem *___qtablewidgetitem = RegsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RegistersScroll", "Valor", 0));
        QTableWidgetItem *___qtablewidgetitem1 = RegsTable->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("RegistersScroll", "x0 (Zero)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = RegsTable->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("RegistersScroll", "x1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = RegsTable->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("RegistersScroll", "x2", 0));
        QTableWidgetItem *___qtablewidgetitem4 = RegsTable->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("RegistersScroll", "x3", 0));
        QTableWidgetItem *___qtablewidgetitem5 = RegsTable->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("RegistersScroll", "x4", 0));
        QTableWidgetItem *___qtablewidgetitem6 = RegsTable->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("RegistersScroll", "x5", 0));
        QTableWidgetItem *___qtablewidgetitem7 = RegsTable->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("RegistersScroll", "x6", 0));
        QTableWidgetItem *___qtablewidgetitem8 = RegsTable->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("RegistersScroll", "x7", 0));
        QTableWidgetItem *___qtablewidgetitem9 = RegsTable->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("RegistersScroll", "x8", 0));
        QTableWidgetItem *___qtablewidgetitem10 = RegsTable->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("RegistersScroll", "x9", 0));
        QTableWidgetItem *___qtablewidgetitem11 = RegsTable->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("RegistersScroll", "x10", 0));
        QTableWidgetItem *___qtablewidgetitem12 = RegsTable->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("RegistersScroll", "x11", 0));
        QTableWidgetItem *___qtablewidgetitem13 = RegsTable->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("RegistersScroll", "x12", 0));
        QTableWidgetItem *___qtablewidgetitem14 = RegsTable->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("RegistersScroll", "x13", 0));
        QTableWidgetItem *___qtablewidgetitem15 = RegsTable->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("RegistersScroll", "x14", 0));
        QTableWidgetItem *___qtablewidgetitem16 = RegsTable->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("RegistersScroll", "x15", 0));
        QTableWidgetItem *___qtablewidgetitem17 = RegsTable->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("RegistersScroll", "x16", 0));
        QTableWidgetItem *___qtablewidgetitem18 = RegsTable->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("RegistersScroll", "x17", 0));
        QTableWidgetItem *___qtablewidgetitem19 = RegsTable->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("RegistersScroll", "x18", 0));
        QTableWidgetItem *___qtablewidgetitem20 = RegsTable->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("RegistersScroll", "x19", 0));
        QTableWidgetItem *___qtablewidgetitem21 = RegsTable->verticalHeaderItem(20);
        ___qtablewidgetitem21->setText(QApplication::translate("RegistersScroll", "x20", 0));
        QTableWidgetItem *___qtablewidgetitem22 = RegsTable->verticalHeaderItem(21);
        ___qtablewidgetitem22->setText(QApplication::translate("RegistersScroll", "x21", 0));
        QTableWidgetItem *___qtablewidgetitem23 = RegsTable->verticalHeaderItem(22);
        ___qtablewidgetitem23->setText(QApplication::translate("RegistersScroll", "x22", 0));
        QTableWidgetItem *___qtablewidgetitem24 = RegsTable->verticalHeaderItem(23);
        ___qtablewidgetitem24->setText(QApplication::translate("RegistersScroll", "x23", 0));
        QTableWidgetItem *___qtablewidgetitem25 = RegsTable->verticalHeaderItem(24);
        ___qtablewidgetitem25->setText(QApplication::translate("RegistersScroll", "x24", 0));
        QTableWidgetItem *___qtablewidgetitem26 = RegsTable->verticalHeaderItem(25);
        ___qtablewidgetitem26->setText(QApplication::translate("RegistersScroll", "x25", 0));
        QTableWidgetItem *___qtablewidgetitem27 = RegsTable->verticalHeaderItem(26);
        ___qtablewidgetitem27->setText(QApplication::translate("RegistersScroll", "x26", 0));
        QTableWidgetItem *___qtablewidgetitem28 = RegsTable->verticalHeaderItem(27);
        ___qtablewidgetitem28->setText(QApplication::translate("RegistersScroll", "x27", 0));
        QTableWidgetItem *___qtablewidgetitem29 = RegsTable->verticalHeaderItem(28);
        ___qtablewidgetitem29->setText(QApplication::translate("RegistersScroll", "x28", 0));
        QTableWidgetItem *___qtablewidgetitem30 = RegsTable->verticalHeaderItem(29);
        ___qtablewidgetitem30->setText(QApplication::translate("RegistersScroll", "x29", 0));
        QTableWidgetItem *___qtablewidgetitem31 = RegsTable->verticalHeaderItem(30);
        ___qtablewidgetitem31->setText(QApplication::translate("RegistersScroll", "x30", 0));
        QTableWidgetItem *___qtablewidgetitem32 = RegsTable->verticalHeaderItem(31);
        ___qtablewidgetitem32->setText(QApplication::translate("RegistersScroll", "x31", 0));
    } // retranslateUi

};

namespace Ui {
    class RegistersScroll: public Ui_RegistersScroll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERSSCROLL_H
