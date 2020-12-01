#include "mythread.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}
bool MyThread::init(){
    mb = modbus_new_tcp(well_ip.toStdString().c_str(), well_port.toInt());  //由于是tcp client连接，在同一个程序中相同的端口可以连接多次。
    if(mb == nullptr){
        //QMessageBox::information(this,"error","无法建立连接环境！");
        qDebug()<<"无法建立连接环境！";
        return false;
    }


    modbus_set_slave(mb, well_pid.toInt());  //从机地址

    if(modbus_connect(mb) == -1){
        //QMessageBox::information(this,"error","连接失败！");
        qDebug()<<"连接失败！";
        modbus_free(mb);
        return false;
    };

    struct timeval t;
    t.tv_sec=0;
    t.tv_usec=2000000;   //设置modbus超时时间为1000毫秒，注意：经测试，如果没有成功建立tcp连接，则该设置无效。
    modbus_set_response_timeout(mb, t.tv_sec,t.tv_usec);
//    memset(tab_reg, 0, sizeof(tab_reg));
//    int regs = modbus_read_registers(mb, well_addr, 2, tab_reg);
//    //int regs = modbus_read_registers(mb, 0, 2, tab_reg);
//    if(regs == -1){
//        //QMessageBox::information(this,"error",modbus_strerror(errno));
//        qDebug()<<modbus_strerror(errno);
//        modbus_close(mb);
//        modbus_free(mb);
//        //return;
    //}

//    QMessageBox::about(this, "报告", QString("TCP 读取寄存器的个数: %1").arg(regs));
//    switch(well_float_mode){
//        case 0:
//            reg_value = modbus_get_float_abcd(&tab_reg[0]);
//            break;
//        case 1:
//            reg_value = modbus_get_float_cdab(&tab_reg[0]);
//            break;
//        case 2:
//            reg_value = modbus_get_float_badc(&tab_reg[0]);
//            break;
//        case 3:
//            reg_value = modbus_get_float_dcba(&tab_reg[0]);
//            break;
//    }

//    QString connectionName = "connection";

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", connectionName);

//    db.setHostName("127.0.0.1");
//    db.setUserName("root");
//    db.setPassword("123456");
//    db.setDatabaseName("modbus_db");

//    if(!db.open()){
//        //QMessageBox::warning(this, "错误", db.lastError().text());
//        qDebug()<<db.lastError().text();
//        return false;
//    }

//    query = QSqlQuery("", db);
//    QString creatTableStr = QString("create table if not exists %1 (m_time timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP, pid text NOT NULL, addr smallint NOT NULL,aa_value float NOT NULL);").arg(well_name);
//    qDebug() << creatTableStr;
//    query.exec(creatTableStr);
//    creatTableStr = QString("insert into %1 set pid ='%2',addr='%3',aa_value='%4';").arg(well_name).arg(well_pid).arg(well_addr).arg(1.2323);
//    qDebug() << creatTableStr;
//    query.exec(creatTableStr);
    start();
    return true;
}
void MyThread::run(){
    //TCP
//      QString connectionName = "connection";
//      QSqlDatabase db = QSqlDatabase::database(connectionName);
//      QSqlQuery query(db);
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("modbus_db");

    if(!db.open()){
        //QMessageBox::warning(this, "错误", db.lastError().text());
        qDebug()<<db.lastError().text();
        return; //false;
    }
    int regs;
    QSqlQuery query(db);
    QString creatTableStr = QString("create table if not exists %1 (m_time timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP, pid text NOT NULL, addr smallint NOT NULL,aa_value float NOT NULL);").arg(well_name);
    qDebug() << creatTableStr;
    query.exec(creatTableStr);
    while(1){
        memset(tab_reg, 0, sizeof(tab_reg));
        regs = modbus_read_registers(mb, well_addr, 2, tab_reg);
        regs = modbus_read_registers(mb, 0, 2, tab_reg);
        if(regs == -1){
            //QMessageBox::information(this,"error",modbus_strerror(errno));
            qDebug()<<modbus_strerror(errno);
            modbus_close(mb);
            modbus_free(mb);
            return;
        }

    //    QMessageBox::about(this, "报告", QString("TCP 读取寄存器的个数: %1").arg(regs));
        switch(well_float_mode){
            case 0:
                reg_value = modbus_get_float_abcd(&tab_reg[0]);
                break;
            case 1:
                reg_value = modbus_get_float_cdab(&tab_reg[0]);
                break;
            case 2:
                reg_value = modbus_get_float_badc(&tab_reg[0]);
                break;
            case 3:
                reg_value = modbus_get_float_dcba(&tab_reg[0]);
                break;
        }
//        ui->lineEdit_reg_value->setText(QString("%1").arg(reg_value));

        creatTableStr = QString("insert into %1 set pid ='%2',addr='%3',aa_value='%4';").arg(well_name).arg(well_pid).arg(well_addr).arg(reg_value);
        qDebug() << creatTableStr;
        query.exec(creatTableStr);
        emit(revdone(reg_value));
        QThread::msleep(1000);
    }
}
