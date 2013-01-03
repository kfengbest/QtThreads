#include "thread4.h"

Producer4::Producer4(QObject *parent) :
    QThread(parent)
{
}

void Producer4::run()
{
    qDebug() << "Producing " << m_id;

    for(int i = 0; i < 6; i++)
    {

        // Wait for previous.
        m_waitForPrevious->wait(m_mutex);

        // Working.
        qDebug() << m_id << " " << i ;

        for(int x = 0; x < 10000; x++)
            for(int y = 0; y < 20000; y++)
                int z = x-y;

        // Wakeup the next.
        m_wakeupNext->wakeOne();
    }

    qDebug() << m_id << " finished";

}


Master::Master(QObject *parent) :
    QThread(parent)
{
}

void Master::run()
{
    QMutex m;
    QWaitCondition a;
    QWaitCondition b;
    QWaitCondition c;

    Producer4 pa;
    pa.id('A');
    pa.waitForPrevious(&a);
    pa.wakeupNext(&b);
    pa.mutex(&m);

    Producer4 pb;
    pb.id('B');
    pb.waitForPrevious(&b);
    pb.wakeupNext(&c);
    pb.mutex(&m);

    Producer4 pc;
    pc.id('C');
    pc.waitForPrevious(&c);
    pc.wakeupNext(&a);
    pc.mutex(&m);

    qDebug() << "before start";

    m.lock();
    pa.start();
    pb.start();
    pc.start();

    qDebug() << "before wakeOne";

    a.wakeOne();

    qDebug() << "before pa wait";

    pa.wait();
    qDebug() << "before pb wait";
    pb.wait();
    qDebug() << "before pc wait";

    c.wakeOne();

    pc.wait();
    qDebug() << "all done";

    m.unlock();


}
