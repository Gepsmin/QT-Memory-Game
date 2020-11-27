#ifndef MYSCORE_H
#define MYSCORE_H
#include <QLabel>
#include <QTimer>
#include <QMessageBox>

class MyScore:QObject
{
    Q_OBJECT
public:
    MyScore(int* score, QTimer *timer, bool* is_finished);
    QLabel *label;
    QTimer *timer;
    int *score;
    bool *is_finished;
    void scorer();
};

#endif // MYSCORE_H
