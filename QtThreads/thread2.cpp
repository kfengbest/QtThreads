#include "thread2.h"

const int g_BufferSize = 500;
char g_Buffer[g_BufferSize];
int g_index = 0;
QMutex g_mutex2;
QWaitCondition g_NotEmpty;
QWaitCondition g_NotFull;


Producer2::Producer2(char id, QObject *parent) :
    QThread(parent),
    m_id(id)
{
}

/*
void Producer2::run()
{
    qDebug() <<  " Producing..." << m_id;

    for(int i = 0; i < g_BufferSize; i++)
    {
        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;

        g_Buffer[i] = m_id;
    }

    qDebug() << "Produce finished." << m_id;
}
*/

void Producer2::run()
{
    qDebug() <<  " Producing..." << m_id;

    while(true)
    {


        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;


        g_mutex2.lock();
        if(g_index == g_BufferSize)
        {
            g_NotEmpty.wakeOne();
            g_NotFull.wait(&g_mutex2);
        }
        g_mutex2.unlock();

        g_mutex2.lock();

        g_Buffer[g_index] = m_id;

        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;

        g_index++;

        if(g_index%50 == 0)
            qDebug() << m_id << "producing " << g_index;

        g_mutex2.unlock();


    }

    qDebug() << "Produce finished." << m_id;

}



Consumer2::Consumer2(QObject *parent) :
    QThread(parent)
{

}

void Consumer2::run()
{
    while(true)
    {
        qDebug() <<  " Comsuming...";

        g_mutex2.lock();
        g_NotEmpty.wait(&g_mutex2);

        qDebug() << g_Buffer;

        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;

        g_index = 0;

        g_mutex2.unlock();

        g_NotFull.wakeAll();

        qDebug() <<  " Comsumed.";

    }


}
