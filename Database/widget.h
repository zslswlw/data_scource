#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTreeWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_buttonDel_clicked();

    void on_buttonsure_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;

    void SetTree_Init();

    void wellTree(QString root, QTreeWidgetItem *item);  //后续递归调用，插入到父亲节点
    void wellTree(QString root,QTreeWidget *tree);       //第一次插入，根节点，最高级部门
};

#endif // WIDGET_H
