#ifndef THREAD2_H
#define THREAD2_H

#include <QThread>
#include <QtCore>
#include <QtGui>




class Producer2 : public QThread
{
    Q_OBJECT
public:
    explicit Producer2(char id, QObject *parent = 0);
    
    virtual void run();

signals:
    
public slots:
    
private:
    char m_id;
};

class Consumer2 : public QThread
{
    Q_OBJECT
public:
    explicit Consumer2(QObject *parent = 0);

    virtual void run();

signals:

public slots:

};

#endif // THREAD2_H
