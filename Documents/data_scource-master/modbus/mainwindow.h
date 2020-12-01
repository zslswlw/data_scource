#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "mythread.h"
#include <QTreeWidget>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct timeval
    {
        uint32_t  tv_sec;
        uint32_t  tv_usec;
    };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton *pbRtu;
    QPushButton *pbTcp;
    QPushButton *pbRun;
    QPushButton *pbStop;

private slots:
    void doRtuQuery();
    void doTcpQuery();
    void slot_up_value(float reg_value);
    void slot_close_done();
private:
    Ui::MainWindow *ui;
    MyThread mythread;

};

#endif // MAINWINDOW_H
