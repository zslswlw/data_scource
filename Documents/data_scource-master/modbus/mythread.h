#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "modbus.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    bool init();
    QString well_name;
    QString well_ip;
    QString well_pid;
    int well_addr;
    QString well_port;
    int well_float_mode;
    float reg_value;
    modbus_t *mb;
    uint16_t tab_reg[32];
    QSqlQuery query;
    QSqlDatabase db;
private:

protected:
    void run();
signals:
    void revdone(float reg_value);
public slots:
};

#endif // MYTHREAD_H
