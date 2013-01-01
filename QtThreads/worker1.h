#ifndef WORKER1_H
#define WORKER1_H

#include <QThread>
#include <QtCore>
#include <QtGui>

class Producer1 : public QThread
{
    Q_OBJECT
public:
    explicit Producer1(int id, QObject *parent = 0);
    
signals:
    
public slots:

protected:
    virtual void run();

private:
    int m_id;
    
};

class Consumer1 : public QThread
{

public:
    Consumer1(int id);

    virtual void run();

    void setWaitAll(bool bValue);

private:
    int m_id;
    bool m_bWakeAll;
};


#endif // WORKER1_H
