#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QTableView>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QTreeWidget>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印支持的数据库驱动
//    qDebug()<<QSqlDatabase::drivers();
    //添加MySql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("data_scource");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
//    QSqlQuery query;
//    QString sql = "CREATE TABLE IF NOT EXISTS well_tbl("
//            "well_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, "
//            "well_pid VARCHAR(100) NOT NULL, "
//            "well_addr VARCHAR(40) NOT NULL, "
//            "well_value VARCHAR(40) NOT NULL, "
//            "PRIMARY KEY ( well_time ))ENGINE=InnoDB DEFAULT CHARSET=utf8;";
//    query.exec(sql);

//    sql = "INSERT INTO well_tbl ( well_pid, well_addr,well_value )"
//         "VALUES"
//         "( 2, 40001,500);";
//    query.exec(sql);
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
//    query.prepare("INSERT INTO well_tbl (well_pid, well_addr, well_value) VAlUES (:pid, :addr, :value)");
//    QVariantList well_pid_List;
//    well_pid_List<<1<<2<<3;
//    QVariantList well_addr_List;
//    well_addr_List<<40001<<40002<<40003;
//    QVariantList well_value_List;
//    well_value_List<<100<<150<<200;

//    query.bindValue(":pid", well_pid_List);
//    query.bindValue(":addr", well_pid_List);
//    query.bindValue(":value", well_pid_List);

//    query.execBatch();

    SetTree_Init();
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
//    QString table_name = ui->lineEdit_well_table->text();
//    QString sql = QString("CREATE TABLE IF NOT EXISTS %1("
//                            "well_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,"
//                            "well_pid VARCHAR(100) NOT NULL, "
//                            "well_addr VARCHAR(40) NOT NULL, "
//                            "well_value VARCHAR(40) NOT NULL, "
//                            "PRIMARY KEY ( well_time ))ENGINE=InnoDB DEFAULT CHARSET=utf8;").arg(table_name);
//    QSqlDatabase::database().transaction();
//    QSqlQuery query;
//    query.exec(sql);
//    QSqlDatabase::database().commit();

}

void Widget::on_pushButton_2_clicked()
{
    static QSqlQueryModel *model_table = new QSqlQueryModel(ui->tableView);
    model_table->setQuery("select * from well_conf");
    model_table->setHeaderData(0, Qt::Horizontal, tr("时间"));
    model_table->setHeaderData(1, Qt::Horizontal, tr("设备号"));
    model_table->setHeaderData(2, Qt::Horizontal, tr("设备地址"));
    model_table->setHeaderData(3, Qt::Horizontal, tr("设备值"));
    ui->tableView->setModel(model_table);
}

void Widget::SetTree_Init(){
    ui->treeWidget_conf->clear();
    ui->treeWidget_conf->headerItem()->setText(0, "参数名");
    ui->treeWidget_conf->headerItem()->setText(1,  "内容");
    ui->treeWidget_conf->setColumnCount(2);
//    ui->treeWidget_conf->setHeaderLabels(QStringList()<<"天东1井");
//    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget_conf,QStringList(QString("天东1井")));
//    imageItem1->setIcon(0,QIcon("xxx.png"));
//    QTreeWidgetItem *imageItem1_1 = new QTreeWidgetItem(imageItem1,QStringList(QString("ip"))); //子节点1
//    imageItem1->addChild(imageItem1_1); //添加子节点
//    QLineEdit* ip_Value=new QLineEdit();
//    ip_Value->setMaximumWidth(150);
//    ip_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_1, 1, ip_Value);
//    QTreeWidgetItem *imageItem1_2 = new QTreeWidgetItem(imageItem1,QStringList(QString("端口"))); //子节点1
//    imageItem1->addChild(imageItem1_2); //添加子节点
//    QLineEdit* port_Value=new QLineEdit();
//    port_Value->setMaximumWidth(150);
//    port_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_2, 1, port_Value);
//    QTreeWidgetItem *imageItem1_3 = new QTreeWidgetItem(imageItem1,QStringList(QString("参数"))); //子节点1
//    imageItem1->addChild(imageItem1_3); //添加子节点
//    QLineEdit* param_Value=new QLineEdit();
//    param_Value->setMaximumWidth(150);
//    param_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3, 1, param_Value);
//    QTreeWidgetItem *imageItem1_3_1 = new QTreeWidgetItem(imageItem1_3,QStringList()<<"单位"); //子节点1
//    imageItem1_3->addChild(imageItem1_3_1);
//    QLineEdit* unit_Value=new QLineEdit();
//    unit_Value->setMaximumWidth(150);
//    unit_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3_1, 1, unit_Value);

//    QTreeWidgetItem *imageItem1_3_2 = new QTreeWidgetItem(imageItem1_3,QStringList()<<"ID"); //子节点1
//    imageItem1_3->addChild(imageItem1_3_2);
//    QLineEdit* id_Value=new QLineEdit();
//    id_Value->setMaximumWidth(150);
//    id_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3_2, 1, id_Value);

//    QTreeWidgetItem *imageItem1_3_3 = new QTreeWidgetItem(imageItem1_3,QStringList()<<"地址"); //子节点1
//    imageItem1_3->addChild(imageItem1_3_3);
//    QLineEdit* addr_Value=new QLineEdit();
//    addr_Value->setMaximumWidth(150);
//    addr_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3_3, 1, addr_Value);

//    QTreeWidgetItem *imageItem1_3_4 = new QTreeWidgetItem(imageItem1_3,QStringList()<<"类型"); //子节点1
//    imageItem1_3->addChild(imageItem1_3_4);
//    QLineEdit* dtype_Value=new QLineEdit();
//    dtype_Value->setMaximumWidth(150);
//    dtype_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3_4, 1, dtype_Value);

//    QTreeWidgetItem *imageItem1_3_5 = new QTreeWidgetItem(imageItem1_3,QStringList()<<"格式"); //子节点1
//    imageItem1_3->addChild(imageItem1_3_5);
//    QLineEdit* fromat_Value=new QLineEdit();
//    fromat_Value->setMaximumWidth(150);
//    fromat_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    ui->treeWidget_conf->setItemWidget(imageItem1_3_5, 1, fromat_Value);



//    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget_conf,QStringList(QString("图像2")));
//    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band1"))); //子节点1
//    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2,QStringList(QString("Band2"))); //子节点2
//    imageItem2->addChild(imageItem2_1);  //添加子节点
//    imageItem2->addChild(imageItem2_2);


//    wellTree("", ui->treeWidget_conf);
//    QSqlQuery query;
//    query.exec("select * from tree_config");        //设置查询语句

//    while (query.next())
//    {
//        QString well_name = query.value(0).toString(); //井号
//        QString well_param = query.value(1).toString();   //参数
//        QString well_unit = query.value(2).toString();   //单位
//        QString well_ip = query.value(3).toString(); //ip
//        QString well_port = query.value(4).toString();   //端口
//        QString well_id = query.value(5).toString();   //设备号
//        QString well_addr = query.value(6).toString();    //寄存器地址
//        QString well_dtype = query.value(7).toString();    //数据类型
//        QString well_fromat = query.value(8).toString();     //数据格式



//        qDebug()<<well_name<<well_param<<well_unit<<well_ip<<well_port<<well_id<<well_addr<<well_dtype<<well_fromat;
//        QTreeWidgetItem *items =
//                new QTreeWidgetItem(ui->treeWidget_conf,QStringList(QString(DEPART_NAME)));


//        QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget_conf,QStringList(QString(well_name)));
//        imageItem1->setIcon(0,QIcon("xxx.png"));
//        QTreeWidgetItem *imageItem1_1 = new QTreeWidgetItem(imageItem1,QStringList(QString(well_param))); //子节点1
//        imageItem1->addChild(imageItem1_1); //添加子节点

//        /*创建新的ITEM,插入到ITEM中，设置名称为当前查询到的部门名称*/
//        if(!DEPART_NAME.isEmpty())
//        {
//            //wellTree(DEPART_ID,items);   //递归，若传入查询到的部门，判断是否还有下级
//        }
//    }
//    return;

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


void Widget::wellTree(QString root, QTreeWidget *tree)
{
    QSqlQuery query;
    query.exec("select DEPART_NAME,DEPART_ID from TAB_DEPART where DEPART_UPPER_DEPT='"+root+"'");
    while (query.next())
    {
        QString DEPART_NAME = query.value(0).toString();
        QString DEPART_ID = query.value(1).toString();
        QTreeWidgetItem *item =
                new QTreeWidgetItem(tree,QStringList(QString(DEPART_NAME)));
        /*创建ITEM,由于是最高部门，插入对象为TreeWidget*/
        if(!DEPART_NAME.isEmpty())
        {
           wellTree(DEPART_ID,item);    //开启递归
        }
    }
    return;
}


void Widget::on_pushButton_4_clicked()
{
    QWidget *w=new QWidget;
        //阻塞其他窗体
        w->setWindowModality(Qt::ApplicationModal);
        QLabel *wl_name=new QLabel;
        wl_name->setText("井名:");

        QLabel *wl_ip=new QLabel;
        wl_ip->setText("IP  :");

        QLabel *wl_port=new QLabel;
        wl_port->setText("端口:");


//        QLabel *content=new QLabel;
//        content->setText("脚本:");
        QLineEdit *wl_name_val=new QLineEdit;
        QLineEdit *wl_ip_val=new QLineEdit;
        QLineEdit *wl_port_val=new QLineEdit;

//        QTextEdit *shell_val=new QTextEdit;
        QPushButton *ok_btn=new QPushButton;
        ok_btn->setText("ok");
        ok_btn->setIcon(QIcon("://images/ok.png"));
        QPushButton *cancel_btn=new QPushButton;
        cancel_btn->setText("cancel");
        cancel_btn->setIcon(QIcon("://images/false.png"));

        QHBoxLayout *lay1=new QHBoxLayout;
        lay1->addWidget(wl_name);
        lay1->addWidget(wl_name_val);

        QHBoxLayout *lay2=new QHBoxLayout;
        lay2->addWidget(wl_ip);
        lay2->addWidget(wl_ip_val);

        QHBoxLayout *lay3=new QHBoxLayout;
        lay3->addWidget(wl_port);
        lay3->addWidget(wl_port_val);



        QHBoxLayout *lay4=new QHBoxLayout;
        lay4->addWidget(ok_btn);
        lay4->addWidget(cancel_btn);
        QVBoxLayout *v1=new QVBoxLayout;
        v1->addLayout(lay1);
        v1->addLayout(lay2);
        v1->addLayout(lay3);
        v1->addLayout(lay4);

        w->setLayout(v1);
        w->show();

        connect(ok_btn,&QPushButton::clicked,[this,w,wl_name_val,wl_ip_val,wl_port_val]
        {
            this->add_quick_cmd(wl_name_val->text(),wl_ip_val->text(), wl_port_val->text());
            w->close();
        });
}

//向treeWidget添加快捷指令
void Widget::add_quick_cmd(QString name,QString ip_val,QString port_val)
{
    if(name=="") return;
    QTreeWidgetItem *head=new QTreeWidgetItem(QStringList()<<name);
    this->ui->treeWidget_conf->addTopLevelItem(head);
//    QCheckBox *check=new QCheckBox;
//    //记录父子关系
//    this->widget_to_parentItem_map[check]=head;
//    //连接checkbox选中的槽函数
//    connect(check,SIGNAL(stateChanged(int)),this,SLOT(quick_cmds_check_change(int)));
//    this->ui->treeWidget_conf->setItemWidget(head,1,check);
    QTreeWidgetItem *wl_ip_tree=new QTreeWidgetItem(QStringList()<<"IP");
    QLineEdit* ip_Value=new QLineEdit();
    ip_Value->setMaximumWidth(150);
    ip_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");

//    QTextEdit *shell_val=new QTextEdit;
//    shell_val->setMaximumWidth(150);
//    shell_val->setMaximumHeight(40);
    head->addChild(wl_ip_tree);
    ip_Value->setText(ip_val);
    this->ui->treeWidget_conf->setItemWidget(wl_ip_tree,1,ip_Value);

    QTreeWidgetItem *wl_port_tree=new QTreeWidgetItem(QStringList()<<"端口");
    QLineEdit* port_Value=new QLineEdit();
    port_Value->setMaximumWidth(150);
    port_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_port_tree);
    port_Value->setText(port_val);
    this->ui->treeWidget_conf->setItemWidget(wl_port_tree,1,port_Value);


}


//添加设备信息
void Widget::add_point_conf(QTreeWidgetItem *currentItem_,QString pname_val,QString punit_val,QString pID_val,QString paddr_val,QString pdtype_val,QString pfromat_val){
    if(pname_val=="") return;
    QTreeWidgetItem *currentItem = currentItem_;
    if(currentItem==NULL)
    {
        return;
    }
    //如果没有父节点就直接删除
    if(currentItem->parent()!=NULL)
    {
        currentItem = currentItem->parent();
    }

    QTreeWidgetItem *head=new QTreeWidgetItem(QStringList()<<"点表名");

    currentItem->addChild(head);
//    this->ui->treeWidget_conf->addTopLevelItem(head);
    QLineEdit* pname_Value=new QLineEdit();
    pname_Value->setText(pname_val);
    pname_Value->setMaximumWidth(150);
    pname_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    QCheckBox *check=new QCheckBox;
//    //记录父子关系
//    this->widget_to_parentItem_map[check]=head;
//    //连接checkbox选中的槽函数
//    connect(check,SIGNAL(stateChanged(int)),this,SLOT(quick_cmds_check_change(int)));
    this->ui->treeWidget_conf->setItemWidget(head,1,pname_Value);


    QTreeWidgetItem *wl_punit_tree=new QTreeWidgetItem(QStringList()<<"单位");
    QLineEdit* punit_Value=new QLineEdit();
    punit_Value->setMaximumWidth(150);
    punit_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_punit_tree);
    punit_Value->setText(punit_val);
    this->ui->treeWidget_conf->setItemWidget(wl_punit_tree,1,punit_Value);

    QTreeWidgetItem *wl_pID_tree=new QTreeWidgetItem(QStringList()<<"ID");
    QLineEdit* pID_Value=new QLineEdit();
    pID_Value->setMaximumWidth(150);
    pID_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_pID_tree);
    pID_Value->setText(pID_val);
    this->ui->treeWidget_conf->setItemWidget(wl_pID_tree,1,pID_Value);

    QTreeWidgetItem *wl_paddr_tree=new QTreeWidgetItem(QStringList()<<"地址");
    QLineEdit* paddr_Value=new QLineEdit();
    paddr_Value->setMaximumWidth(150);
    paddr_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_paddr_tree);
    paddr_Value->setText(paddr_val);
    this->ui->treeWidget_conf->setItemWidget(wl_paddr_tree,1,paddr_Value);

    QTreeWidgetItem *wl_pdtype_tree=new QTreeWidgetItem(QStringList()<<"类型");
    QLineEdit* pdtype_Value=new QLineEdit();
    pdtype_Value->setMaximumWidth(150);
    pdtype_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_pdtype_tree);
    pdtype_Value->setText(pdtype_val);
    this->ui->treeWidget_conf->setItemWidget(wl_pdtype_tree,1,pdtype_Value);

    QTreeWidgetItem *wl_pfromat_tree=new QTreeWidgetItem(QStringList()<<"格式");
    QLineEdit* pfromat_Value=new QLineEdit();
    pfromat_Value->setMaximumWidth(150);
    pfromat_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    head->addChild(wl_pfromat_tree);
    pfromat_Value->setText(pfromat_val);
    this->ui->treeWidget_conf->setItemWidget(wl_pfromat_tree,1,pfromat_Value);

//    QTreeWidgetItem *wl_port_tree=new QTreeWidgetItem(QStringList()<<"端口");
//    QLineEdit* port_Value=new QLineEdit();
//    port_Value->setMaximumWidth(150);
//    port_Value->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
//    head->addChild(wl_port_tree);
//    port_Value->setText(port_val);
//    this->ui->treeWidget_conf->setItemWidget(wl_port_tree,1,port_Value);

}

//快捷指令按钮处理的函数
void Widget::quick_cmds_check_change(int state)
{

    QCheckBox* check = qobject_cast<QCheckBox*>(sender());
    QTreeWidgetItem *parent=widget_to_parentItem_map[check];
    QString bash=((QTextEdit *)ui->treeWidget_conf->itemWidget(parent->child(0),1))->toPlainText();
    bool is_checked=state>1?true:false;
    if(is_checked)
    {
//        quick_cmd=new QProcess;
//        quick_cmd->start("bash");
//        qDebug()<<bash;
//        quick_cmd->write(bash.toLocal8Bit()+'\n');
//        connect(quick_cmd,SIGNAL(readyReadStandardOutput()),this,SLOT(cmd_output()));
//         connect(quick_cmd,SIGNAL(readyReadStandardError()),this,SLOT(cmd_error_output()));
        qDebug()<<"井被选中";
    }
    else{


    }

}

void Widget::on_pushButton_5_clicked()
{
    QWidget *w=new QWidget;
        //阻塞其他窗体
        w->setWindowModality(Qt::ApplicationModal);
        QLabel *wl_pname=new QLabel;
        wl_pname->setText("点表名:");

        QLabel *wl_punit=new QLabel;
        wl_punit->setText("单位:");

        QLabel *wl_pID=new QLabel;
        wl_pID->setText("ID");

        QLabel *wl_paddr=new QLabel;
        wl_paddr->setText("地址");

        QLabel *wl_pdtype=new QLabel;
        wl_pdtype->setText("类型");

        QLabel *wl_pfromat=new QLabel;
        wl_pfromat->setText("格式");

//        QLabel *content=new QLabel;
//        content->setText("脚本:");
        QLineEdit *wl_pname_val=new QLineEdit;
        QLineEdit *wl_punit_val=new QLineEdit;
        QLineEdit *wl_pID_val=new QLineEdit;
        QLineEdit *wl_paddr_val=new QLineEdit;
        QLineEdit *wl_pdtype_val=new QLineEdit;
        QLineEdit *wl_pfromat_val=new QLineEdit;

//        QTextEdit *shell_val=new QTextEdit;
        QPushButton *ok_btn=new QPushButton;
        ok_btn->setText("ok");
        ok_btn->setIcon(QIcon("://images/ok.png"));
        QPushButton *cancel_btn=new QPushButton;
        cancel_btn->setText("cancel");
        cancel_btn->setIcon(QIcon("://images/false.png"));

        QHBoxLayout *lay1=new QHBoxLayout;
        lay1->addWidget(wl_pname);
        lay1->addWidget(wl_pname_val);

        QHBoxLayout *lay2=new QHBoxLayout;
        lay2->addWidget(wl_punit);
        lay2->addWidget(wl_punit_val);

        QHBoxLayout *lay3=new QHBoxLayout;
        lay3->addWidget(wl_pID);
        lay3->addWidget(wl_pID_val);

        QHBoxLayout *lay4=new QHBoxLayout;
        lay4->addWidget(wl_paddr);
        lay4->addWidget(wl_paddr_val);

        QHBoxLayout *lay5=new QHBoxLayout;
        lay5->addWidget(wl_pdtype);
        lay5->addWidget(wl_pdtype_val);

        QHBoxLayout *lay6=new QHBoxLayout;
        lay6->addWidget(wl_pfromat);
        lay6->addWidget(wl_pfromat_val);


        QHBoxLayout *lay7=new QHBoxLayout;
        lay7->addWidget(ok_btn);
        lay7->addWidget(cancel_btn);
        QVBoxLayout *v1=new QVBoxLayout;
        v1->addLayout(lay1);
        v1->addLayout(lay2);
        v1->addLayout(lay3);
        v1->addLayout(lay4);
        v1->addLayout(lay5);
        v1->addLayout(lay6);
        v1->addLayout(lay7);

        w->setLayout(v1);
        w->show();

        connect(ok_btn,&QPushButton::clicked,[this,w,wl_pname_val,wl_punit_val,wl_pID_val,wl_paddr_val,wl_pdtype_val,wl_pfromat_val]
        {
            QTreeWidgetItem *currentItem = ui->treeWidget_conf->currentItem();
            this->add_point_conf(currentItem,wl_pname_val->text(),wl_punit_val->text(),wl_pID_val->text(),wl_paddr_val->text(),wl_pdtype_val->text(),wl_pfromat_val->text());
            w->close();
        });
}

void Widget::on_pushButton_7_clicked()
{
    ui->treeWidget_conf->clear();
    ui->treeWidget_conf->headerItem()->setText(0, "参数名");
    ui->treeWidget_conf->headerItem()->setText(1,  "内容");
    ui->treeWidget_conf->setColumnCount(2);
    QSqlQuery query;
    query.exec("select * from well_num");        //设置查询语句

    while (query.next())
    {
        QString well_name = query.value(0).toString();
        QString well_ip = query.value(1).toString();
        QString well_port = query.value(2).toString();
        this->add_quick_cmd(well_name,well_ip,well_port);
    }

    query.exec("select * from well_conf");
    while(query.next()){
        QString well_name = query.value(0).toString();
        QString well_param = query.value(1).toString();
        QString well_unit = query.value(2).toString();
        QString well_id = query.value(3).toString();
        QString well_addr = query.value(4).toString();
        QString well_dtype = query.value(5).toString();
        QString well_fromat = query.value(6).toString();


        QList<QTreeWidgetItem *> item = ui->treeWidget_conf->findItems(well_name,Qt::MatchContains,0);
        QTreeWidgetItem *currentItem = item[0];
        this->add_point_conf(currentItem, well_param, well_unit, well_id, well_addr, well_dtype, well_fromat);


    }
}

void Widget::on_pushButton_8_clicked(){
    QMap<QString,  QList<QMap<QString,QMap<QString,QString>>>> it_Map;
    QList<QMap<QString,QMap<QString,QString>>> it_List;
    int num =ui->treeWidget_conf->topLevelItemCount();

    for(int i=0; i<num; i++){
        //qDebug()<<i<<ui->treeWidget_conf->topLevelItem(i)->text(0);

        QTreeWidgetItem* currenttopLevelItem =ui->treeWidget_conf->topLevelItem(i);
        int itemChildrenCounts = currenttopLevelItem->childCount();
        it_List.clear();
        int j = 0;
        while(j < itemChildrenCounts){
            QTreeWidgetItem* currentChild = currenttopLevelItem->child(j);
            QMap<QString,QMap<QString,QString>> qmap;
            QMap<QString, QString> qmap_2;
            if(currentChild->childCount()==0){
                qmap_2.clear();
                qmap_2.insert("key",((QLineEdit* )(ui->treeWidget_conf->itemWidget(currentChild, 1)))->text());
                qmap.insert(currentChild->text(0), qmap_2);
            }else{
                int itemChildrenCounts_2 = currentChild->childCount();
                int k = 0;
                qmap_2.clear();
                while(k < itemChildrenCounts_2){

                    QTreeWidgetItem* currentChild_2 = currentChild->child(k);
                    qmap_2.insert(currentChild_2->text(0), ((QLineEdit* )(ui->treeWidget_conf->itemWidget(currentChild_2, 1)))->text());
                    qmap.insert(((QLineEdit* )(ui->treeWidget_conf->itemWidget(currentChild, 1)))->text(), qmap_2);
                    k++;
                }
            }

            it_List<<qmap;

            it_Map.insert(currenttopLevelItem->text(0), it_List);
            j++;
        }
    }

    qDebug()<<it_Map;
    QMap<QString,  QList<QMap<QString,QMap<QString,QString>>>>::Iterator it=it_Map.begin();
    while(it!=it_Map.end())
    {
        QSqlQuery query;
        query.prepare("REPLACE INTO well_num (well_name, well_ip, well_port) values(:well_name, :well_ip, :well_port);");
        query.bindValue(":well_name",it.key());
        query.bindValue(":well_ip",it.value().at(0).value("IP").value("key"));
        query.bindValue(":well_port",it.value().at(1).value("端口").value("key"));
//        query.bindValue(":Shijian",Catchtime);
//        QString sql = "REPLACE INTO well_num (well_name, well_ip, well_port) values ('天东12井', '192.168.1.100', '502');";
        if(!query.exec())
        {
            qDebug()<<query.lastError()<<"well_num error";//--------->QSqlError("", "Unable to fetch row", "No query")
        }
//        else
//        {
//           while(query.next())
//           {
//                maxid=query.value(0).toInt();
//                qDebug()<<maxid;

//           }
          QList<QMap<QString,QMap<QString,QString>>>::Iterator it_list = it.value().begin()+2;
          while (it_list!=it.value().end()) {
                query.prepare("REPLACE INTO well_conf (well_name,well_param,well_unit,well_id,well_addr,well_dtype,well_fromat) values(:well_name,:well_param,:well_unit,:well_id,:well_addr,:well_dtype,:well_fromat);");
                query.bindValue(":well_name",it.key());
                query.bindValue(":well_param",it_list->begin().key());
                query.bindValue(":well_unit",it_list->begin().value().value("单位"));
                query.bindValue(":well_id",it_list->begin().value().value("ID"));
                query.bindValue(":well_addr",it_list->begin().value().value("地址"));
                query.bindValue(":well_dtype",it_list->begin().value().value("类型"));
                query.bindValue(":well_fromat",it_list->begin().value().value("格式"));
//                QString sql = "REPLACE INTO well_conf (well_name,well_param,well_unit,well_id,well_addr,well_dtype,well_fromat) values('天东1井', '流量','万方/天','1','40005','float','ABCD')";
                if(!query.exec())
                {
                    qDebug()<<query.lastError()<<"well_config error";//--------->QSqlError("", "Unable to fetch row", "No query")
                }
//                qDebug()<<it.key()<<"\t"<<it_list->begin().key()<<"\t"<<it_list->begin().value().value("单位")<<it_list->begin().value().value("ID");
                it_list++;
          }

        it++;
    }



}
