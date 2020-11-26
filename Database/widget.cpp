#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QTableView>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印支持的数据库驱动
    //qDebug()<<QSqlDatabase::drivers();
    //添加MySql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("data_source");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query;
    QString sql = "CREATE TABLE IF NOT EXISTS well_tbl("
            "well_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, "
            "well_pid VARCHAR(100) NOT NULL, "
            "well_addr VARCHAR(40) NOT NULL, "
            "well_value VARCHAR(40) NOT NULL, "
            "PRIMARY KEY ( well_time ))ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    query.exec(sql);

    sql = "INSERT INTO well_tbl ( well_pid, well_addr,well_value )"
         "VALUES"
         "( 2, 40001,500);";
    query.exec(sql);
//odbc风格
//    query.prepare("INSERT INTO well_tbl (well_pid, well_addr, well_value) VAlUES (?, ?, ?)");
//    QVariantList well_pid_List;
//    well_pid_List<<1<<2<<3;
//    QVariantList well_addr_List;
//    well_addr_List<<40001<<40002<<40003;
//    QVariantList well_value_List;
//    well_value_List<<100<<150<<200;
//    query.addBindValue(well_pid_List);
//    query.addBindValue(well_addr_List);
//    query.addBindValue(well_value_List);
//    query.execBatch();
//oracle风格
    query.prepare("INSERT INTO well_tbl (well_pid, well_addr, well_value) VAlUES (:pid, :addr, :value)");
    QVariantList well_pid_List;
    well_pid_List<<1<<2<<3;
    QVariantList well_addr_List;
    well_addr_List<<40001<<40002<<40003;
    QVariantList well_value_List;
    well_value_List<<100<<150<<200;

    query.bindValue(":pid", well_pid_List);
    query.bindValue(":addr", well_pid_List);
    query.bindValue(":value", well_pid_List);

    query.execBatch();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
//    QString name = ui->lineEdit->text();
//    QString str = QString("delete from well_tbl where well_pid = '%1'").arg(name);
//    QSqlDatabase::database().transaction();
//    QSqlQuery query;
//    query.exec(str);
}

void Widget::on_buttonsure_clicked()
{
    QSqlDatabase::database().commit();
}

void Widget::on_pushButton_3_clicked()
{
    QSqlDatabase::database().rollback();
}

void Widget::on_pushButton_clicked()
{
    QString table_name = ui->lineEdit_well_table->text();
    QString sql = QString("CREATE TABLE IF NOT EXISTS %1("
                            "well_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,"
                            "well_pid VARCHAR(100) NOT NULL, "
                            "well_addr VARCHAR(40) NOT NULL, "
                            "well_value VARCHAR(40) NOT NULL, "
                            "PRIMARY KEY ( well_time ))ENGINE=InnoDB DEFAULT CHARSET=utf8;").arg(table_name);
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);
    QSqlDatabase::database().commit();

}

void Widget::on_pushButton_2_clicked()
{
    static QSqlQueryModel *model_table = new QSqlQueryModel(ui->tableView);
    model_table->setQuery("select * from well_tbl");
    model_table->setHeaderData(0, Qt::Horizontal, tr("时间"));
    model_table->setHeaderData(1, Qt::Horizontal, tr("设备号"));
    model_table->setHeaderData(2, Qt::Horizontal, tr("设备地址"));
    model_table->setHeaderData(3, Qt::Horizontal, tr("设备值"));
    ui->tableView->setModel(model_table);
}

void Widget::SetTree_Init(){
    ui->treeWidget_conf->clear();
    ui->treeWidget_conf->headerItem()->setText(0, "配置参数");
    wellTree("", ui->treeWidget_conf);
}

void Widget::wellTree(QString root,QTreeWidgetItem *item)
{

    QSqlQuery query;
    query.exec("select * from tree_config");        //设置查询语句

    while (query.next())
    {
        QString DEPART_NAME = query.value(0).toString(); //获取部门名称
        QString DEPART_ID = query.value(1).toString();   //获取部门ID
        QTreeWidgetItem *items =
                new QTreeWidgetItem(item,QStringList(QString(DEPART_NAME)));
        /*创建新的ITEM,插入到ITEM中，设置名称为当前查询到的部门名称*/
        if(!DEPART_NAME.isEmpty())
        {
            wellTree(DEPART_ID,items);   //递归，若传入查询到的部门，判断是否还有下级
        }
    }
    return;
}

