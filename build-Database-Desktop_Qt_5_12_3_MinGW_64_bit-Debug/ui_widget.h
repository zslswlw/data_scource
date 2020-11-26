/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *buttonDel;
    QPushButton *buttonsure;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_well_table;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_well_pid;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_well_addr;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_well_abcd;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget_conf;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1250, 644);
        buttonDel = new QPushButton(Widget);
        buttonDel->setObjectName(QString::fromUtf8("buttonDel"));
        buttonDel->setGeometry(QRect(610, 590, 75, 23));
        buttonsure = new QPushButton(Widget);
        buttonsure->setObjectName(QString::fromUtf8("buttonsure"));
        buttonsure->setGeometry(QRect(700, 590, 75, 23));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(790, 590, 75, 23));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 590, 75, 23));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 480, 301, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 25));
        label->setMaximumSize(QSize(60, 25));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_well_table = new QLineEdit(layoutWidget);
        lineEdit_well_table->setObjectName(QString::fromUtf8("lineEdit_well_table"));

        gridLayout->addWidget(lineEdit_well_table, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 25));
        label_2->setMaximumSize(QSize(60, 25));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_well_pid = new QLineEdit(layoutWidget);
        lineEdit_well_pid->setObjectName(QString::fromUtf8("lineEdit_well_pid"));

        gridLayout_2->addWidget(lineEdit_well_pid, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 25));
        label_4->setMaximumSize(QSize(60, 25));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_well_addr = new QLineEdit(layoutWidget);
        lineEdit_well_addr->setObjectName(QString::fromUtf8("lineEdit_well_addr"));

        gridLayout_4->addWidget(lineEdit_well_addr, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 25));
        label_3->setMaximumSize(QSize(60, 25));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_well_abcd = new QLineEdit(layoutWidget);
        lineEdit_well_abcd->setObjectName(QString::fromUtf8("lineEdit_well_abcd"));

        gridLayout_3->addWidget(lineEdit_well_abcd, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(380, 30, 821, 531));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1010, 590, 75, 23));
        treeWidget_conf = new QTreeWidget(Widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_conf->setHeaderItem(__qtreewidgetitem);
        treeWidget_conf->setObjectName(QString::fromUtf8("treeWidget_conf"));
        treeWidget_conf->setGeometry(QRect(20, 20, 311, 441));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        buttonDel->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        buttonsure->setText(QApplication::translate("Widget", "\347\241\256\345\256\232\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("Widget", "\344\272\225\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\347\274\226\345\217\267", nullptr));
        label_4->setText(QApplication::translate("Widget", "\345\234\260\345\235\200", nullptr));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\346\240\274\345\274\217", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
