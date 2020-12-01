#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QString>
#include <QThread>
#include <QSqlError>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mythread()
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList()<<"key"<<"value");
    ui->treeWidget->setHeaderHidden(true);
    ui->treeWidget->setFixedWidth(400);
    //站点
    QTreeWidgetItem* Well_site = new QTreeWidgetItem(QStringList()<<"天东1井");
    ui->treeWidget->addTopLevelItem(Well_site);

    //IP
    QTreeWidgetItem* IP_ = new QTreeWidgetItem(QStringList()<<"IP");
    QLineEdit* LineEdit_IP = new QLineEdit();
    LineEdit_IP->setText("127.0.0.1");
    LineEdit_IP->setMaximumWidth(150);
    LineEdit_IP->setMaximumHeight(40);
    Well_site->addChild(IP_);
    ui->treeWidget->setItemWidget(IP_, 1, LineEdit_IP);

    //devID
    QTreeWidgetItem *devID = new QTreeWidgetItem(QStringList()<<"设备ID");
    QSpinBox *SpinBox_DevID = new QSpinBox();
    SpinBox_DevID->setValue(1);
    SpinBox_DevID->setMaximumWidth(150);
    SpinBox_DevID->setMaximumHeight(40);
    Well_site->addChild(devID);
    ui->treeWidget->setItemWidget(devID, 1, SpinBox_DevID);

    //addr
    QTreeWidgetItem *Addr = new QTreeWidgetItem(QStringList()<<"点表");
    QComboBox *ComboBox_ABCD  = new QComboBox();
    ComboBox_ABCD->addItems(QStringList()<<"油压"<<"套压"<<"井温"<<"产量");
    QSpinBox *SpinBox_Addr = new QSpinBox();
    SpinBox_Addr->setMaximum(49999);
    SpinBox_Addr->setMinimum(40000);
    SpinBox_Addr->setValue(40000);
    SpinBox_Addr->setMaximumWidth(150);
    SpinBox_Addr->setMaximumHeight(40);
    Well_site->addChild(Addr);
    ui->treeWidget->setItemWidget(Addr, 1, SpinBox_Addr);

    //port
    QTreeWidgetItem *Port = new QTreeWidgetItem(QStringList()<<"端口号");
    QSpinBox *SpinBox_Port  = new QSpinBox();
    SpinBox_Port ->setMaximum(65535);
    SpinBox_Port->setValue(502);
    SpinBox_Port->setMaximumWidth(150);
    SpinBox_Port->setMaximumHeight(40);
    Well_site->addChild(Port);
    ui->treeWidget->setItemWidget(Port, 1, SpinBox_Port);

    //格式编码
    QTreeWidgetItem *ABCD = new QTreeWidgetItem(QStringList()<<"格式");
    QComboBox *ComboBox_ABCD  = new QComboBox();
    ComboBox_ABCD->addItems(QStringList()<<"AB CD"<<"CD AB"<<"BA DC"<<"DC BA");
    ComboBox_ABCD->setMaximumWidth(150);
    ComboBox_ABCD->setMaximumHeight(40);
    Well_site->addChild(ABCD);
    ui->treeWidget->setItemWidget(ABCD, 1, ComboBox_ABCD);




    connect(ui->pushButton_run, SIGNAL(clicked()), this, SLOT(doTcpQuery()));
    connect(&mythread, SIGNAL(revdone(float)), this, SLOT(slot_up_value(float)));
    connect(this, SIGNAL(destroyed()), this, SLOT(slot_close_done()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_up_value(float reg_value){
    ui->lcdNumber_reg_value->display(QString("%1").arg(reg_value));
}

void MainWindow::slot_close_done(){


    mythread.quit();
    mythread.wait();

    delete &mythread;

};

void MainWindow::doRtuQuery()
{
    //RTU
    modbus_t *mb;
    uint16_t tab_reg[32]={0};

    mb = modbus_new_rtu("COM3", 9600, 'N', 8, 1);   //相同的端口只能同时打开一个
    modbus_set_slave(mb, 1);  //设置modbus从机地址

    modbus_connect(mb);

    struct timeval t;
    t.tv_sec=0;
    t.tv_usec=1000000;   //设置modbus超时时间为1000毫秒
    modbus_set_response_timeout(mb, t.tv_sec,t.tv_usec);

    int regs=modbus_read_registers(mb, 0, 10, tab_reg);

    QMessageBox::about(this, "报告", QString("RTU 读取寄存器的个数: %1").arg(regs));
    modbus_close(mb);
    modbus_free(mb);

}

void MainWindow::doTcpQuery()
{
    //TCP
    mythread.well_name = ui->lineEdit_name->text();
    mythread.well_ip = ui->lineEdit_IP->text();
    mythread.well_pid = ui->lineEdit_pid->text();
    mythread.well_addr = ui->lineEdit_addr->text().toInt() - 40000;
    mythread.well_port = ui->lineEdit_port->text();
    mythread.well_float_mode = ui->comboBox_mode->currentIndex();
    qDebug("mode is: %d", mythread.well_float_mode);

    if(!mythread.init()){
        QMessageBox::warning(NULL, "失败", "连接失败！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    } else {
      ui->pushButton_run->setEnabled(false);
      ui->pushButton_stop->setEnabled(true);
    }
}
