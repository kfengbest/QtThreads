#include "thread5.h"
#include <QtCore>
#include <QtGui>

Thread5::Thread5(char id, QObject *parent) :
    QThread(parent), m_id(id)
{
}

QMutex g_m6;

void Thread5::run()
{

    for(int i = 0; i < 20; i++)
    {
        QMutexLocker locker(&g_m6);

     //   qDebug() << m_id << " befor " << m_counter->number();
        m_counter->increase();

        for(int x = 0; x < 10000; x++)
            for(int y = 0; y < 10000; y++)
                int z = x-y;

        qDebug() << m_id << " after " << m_counter->number();

    }
}

Counter::Counter()
    : m_n(0)
{
}

Counter::~Counter()
{

}

Counter* Counter::get()
{
    static Counter s_theOneAndOnly;
    return &s_theOneAndOnly;
}

void Counter::increase()
{
    m_n++;
}

void Counter::decrease()
{
    m_n--;
}

