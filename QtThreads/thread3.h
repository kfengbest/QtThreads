#ifndef THREAD3_H
#define THREAD3_H

#include <QThread>
#include <QtCore>
#include <QtGui>

class Producer3 : public QThread
{
    Q_OBJECT
public:
    explicit Producer3(char id, int size, QMutex* pMutex, QObject *parent = 0);
    virtual ~Producer3();

    virtual void run();
    QWaitCondition* finishedCondition() const {return m_finishedCon;}
    char* buffer() const { return m_buffer;}

signals:
    
public slots:
    
private:
    char m_id;
    int m_size;
    char* m_buffer;
    int m_index;

    QMutex* m_mutex;
    QWaitCondition* m_finishedCon;
};

class Consumer3 : public QThread
{
    Q_OBJECT
public:
    explicit Consumer3(char id, QObject *parent = 0);

    virtual void run();

signals:

public slots:

private:
    char m_id;

};

#endif // THREAD3_H
