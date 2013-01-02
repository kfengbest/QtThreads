#include "thread2.h"

const int g_BufferSize = 200;
char g_Buffer[g_BufferSize];
int g_index = 0;
QMutex g_mutex2;

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
        g_mutex2.lock();

        if(g_index >= g_BufferSize)
            break;

        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;

        g_Buffer[g_index] = m_id;

        for(int x = 0; x < 3000; x++)
            for(int y = 0; y < 3000; y++)
                int z = x-y;

        g_index++;

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
    qDebug() << g_Buffer;
}
