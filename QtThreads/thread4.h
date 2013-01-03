#ifndef THREAD4_H
#define THREAD4_H

#include <QThread>
#include <QtCore>
#include <QtGui>

class Producer4 : public QThread
{
    Q_OBJECT
public:
    explicit Producer4(QObject *parent = 0);
    virtual void run();

    void id(char id) {m_id = id;}
    void waitForPrevious(QWaitCondition* con) {m_waitForPrevious = con;}
    void wakeupNext(QWaitCondition* con) {m_wakeupNext = con;}
    void mutex(QMutex* m) {m_mutex = m;}


signals:
    
public slots:

private:
    char m_id;
    QWaitCondition* m_waitForPrevious;
    QWaitCondition* m_wakeupNext;
    QMutex*         m_mutex;
};

class Master : public QThread
{
    Q_OBJECT
public:
    explicit Master(QObject *parent = 0);
    virtual void run();

    void id(char id) {m_id = id;}

signals:

public slots:

private:
    char m_id;

};

#endif // THREAD4_H
