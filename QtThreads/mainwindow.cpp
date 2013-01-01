#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_consumer = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id = m_threadpool1.size();
    Producer1* t = new Producer1(id);
    m_threadpool1.append(t);
    t->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(m_consumer == NULL)
    {
        m_consumer = new Consumer1(1000);
    }

    m_consumer->setWaitAll(false);
    m_consumer->start();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(m_consumer == NULL)
    {
        m_consumer = new Consumer1(1000);
    }

    m_consumer->setWaitAll(true);
    m_consumer->start();

}

void MainWindow::on_pushButton_4_clicked()
{
    for(int i = 0; i < m_threadpool1.size(); i++)
    {
        QThread* t = m_threadpool1.at(i);
        t->start();
    }
}

void MainWindow::on_pushButton_5_clicked()
{

    qDebug() << "idealThreadCount: " << QThread::idealThreadCount();

}
