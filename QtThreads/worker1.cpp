#include "worker1.h"

QMutex g_mutex;
QWaitCondition g_con;

void printme()
{

    qDebug() << "printme " << QThread::currentThread()->objectName() << " begin running";

    g_mutex.lock();

    for(int i = 0; i < 60000;i++)
    {
        for(int j = 0; j < 40000; j++)
            int r = i+j;

        if(i%10000 == 0)
            qDebug() << "Producer " << QThread::currentThread()->objectName() << " is running" << i;
    }

    qDebug() << "printme " << QThread::currentThread()->objectName() << " begin running";

    g_mutex.unlock();
}

Producer1::Producer1(int id, QObject *parent) :
    QThread(parent),
    m_id(id)
{
    setObjectName(QString::number(id));
}

/*
void Producer1::run()
{

    qDebug() << "Producer " << m_id << " begin running";

    g_mutex.lock();

 //   qDebug() << "Producer " << m_id << " after lock";

    for(int i = 0; i < 60000;i++)
    {
        for(int j = 0; j < 40000; j++)
            int r = i+j;

        if(i%10000 == 0)
            qDebug() << "Producer " << m_id << " is running" << i;
    }
    g_mutex.unlock();

    qDebug() << "Producer " << m_id << " before wait";
    g_con.wait(&g_mutex);
    qDebug() << "Producer " << m_id << " after wait ";


}

*/

/*
void Producer1::run()
{
    qDebug() << "thread " << QThread::currentThread()->objectName() << " begin running";

    g_mutex.lock();

    for(int i = 0; i < 60000;i++)
    {
        for(int j = 0; j < 40000; j++)
            int r = i+j;

        if(i%10000 == 0)
            qDebug() << "Producer " << QThread::currentThread()->objectName() << " is running" << i;
    }

    qDebug() << "thread " << QThread::currentThread()->objectName() << " end running";

    g_mutex.unlock();

}
*/

void Producer1::run()
{
    qDebug() << "thread " << QThread::currentThread()->objectName() << " begin running";

    g_mutex.lock();

    for(int i = 1; i < 20000;i++)
    {
        for(int j = 0; j < 30000; j++)
            int r = i+j;

//        if(i%10000 == 0)
//            qDebug() << "Producer " << QThread::currentThread()->objectName() << " is running" << i;
    }


    g_mutex.unlock();

    qDebug() << "thread " << QThread::currentThread()->objectName() << " before wait";
    g_con.wait(&g_mutex);
    qDebug() << "thread " << QThread::currentThread()->objectName() << " after wait";



}

Consumer1::Consumer1(int id)
    : m_id(id),
      m_bWakeAll(false)
{

}

void Consumer1::run()
{
    qDebug() << "Consumer " << m_id << " before wakeall ";

    if(m_bWakeAll)
        g_con.wakeAll();
    else
        g_con.wakeOne();

    qDebug() << "Consumer " << m_id << " after wakeall";


}

void Consumer1::setWaitAll(bool bValue)
{
    m_bWakeAll = bValue;
}

