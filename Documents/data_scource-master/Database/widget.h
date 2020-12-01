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

    void on_pushButton_4_clicked();

    void quick_cmds_check_change(int);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
    QMap <QWidget*,QTreeWidgetItem *> widget_to_parentItem_map;

    void SetTree_Init();

    void wellTree(QString root, QTreeWidgetItem *item);  //后续递归调用，插入到父亲节点
    void wellTree(QString root,QTreeWidget *tree);       //第一次插入，根节点，最高级部门
    void add_quick_cmd(QString name,QString ip,QString port);
    void add_point_conf(QTreeWidgetItem *currentItem,QString pname,QString punit,QString pID_val,QString paddr,QString pdtype,QString pfromat);
};

#endif // WIDGET_H
