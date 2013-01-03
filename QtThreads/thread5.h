#ifndef THREAD5_H
#define THREAD5_H

#include <QThread>

class Counter
{
public:
    Counter();
    ~Counter();

    void increase();
    void decrease();

    int number() const {return m_n;}

private:
    int m_n;
};

class Thread5 : public QThread
{
    Q_OBJECT
public:
    explicit Thread5(char id, QObject *parent = 0);

    virtual void run();

signals:
    
public slots:

private:

   Counter m_counter;

   char m_id;
};

#endif // THREAD5_H
