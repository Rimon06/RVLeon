/********************************************************************************
** Form generated from reading UI file 'regs32.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGS32_H
#define UI_REGS32_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Regs32
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *Regs32)
    {
        if (Regs32->objectName().isEmpty())
            Regs32->setObjectName(QStringLiteral("Regs32"));
        Regs32->resize(274, 262);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Regs32->sizePolicy().hasHeightForWidth());
        Regs32->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(Regs32);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(Regs32);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(1);
        tableWidget->horizontalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(Regs32);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(Regs32);

        QMetaObject::connectSlotsByName(Regs32);
    } // setupUi

    void retranslateUi(QWidget *Regs32)
    {
        Regs32->setWindowTitle(QApplication::translate("Regs32", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Regs32", "x0", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(0, 0);
        ___qtablewidgetitem1->setText(QApplication::translate("Regs32", "0x00000000", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("Regs32", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Regs32: public Ui_Regs32 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGS32_H
