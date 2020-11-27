#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

class MyTimer:QObject
{
    Q_OBJECT

public:
    MyTimer(bool* is_finished);
    QTimer *timer;
    QLabel *label;
    int counter;
    bool* is_finished;

public slots:
    void Timer();
};

#endif // MYTIMER_H
