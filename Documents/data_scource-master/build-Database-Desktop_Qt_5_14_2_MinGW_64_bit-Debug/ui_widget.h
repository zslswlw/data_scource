/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget_conf;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *buttonDel;
    QPushButton *buttonsure;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1250, 644);
        formLayout = new QFormLayout(Widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidget_conf = new QTreeWidget(Widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_conf->setHeaderItem(__qtreewidgetitem);
        treeWidget_conf->setObjectName(QString::fromUtf8("treeWidget_conf"));

        verticalLayout->addWidget(treeWidget_conf);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 0, 3, 1, 1);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        buttonDel = new QPushButton(Widget);
        buttonDel->setObjectName(QString::fromUtf8("buttonDel"));

        gridLayout_2->addWidget(buttonDel, 0, 1, 1, 1);

        buttonsure = new QPushButton(Widget);
        buttonsure->setObjectName(QString::fromUtf8("buttonsure"));

        gridLayout_2->addWidget(buttonsure, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\344\272\225\347\253\231", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "\345\216\206\345\217\262\351\205\215\347\275\256", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        buttonDel->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        buttonsure->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
