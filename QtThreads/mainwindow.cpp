#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_consumer = NULL;
    m_producer2 = NULL;
    m_consumer2 = NULL;
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

// Read
void MainWindow::on_pushButton_7_clicked()
{
    if(m_consumer2 == NULL)
        m_consumer2 = new Consumer2();

    m_consumer2->start();
}

// Producer2
void MainWindow::on_pushButton_6_clicked()
{

    char id = 'A' + m_threadpool1.size();
    Producer2* t = new Producer2(id);
    m_threadpool1.append(t);
    t->start();

}
