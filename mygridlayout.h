#ifndef MYGRIDLAYOUT_H
#define MYGRIDLAYOUT_H
#include <QGridLayout>
#include <QTimer>
#include "mycard.h"
#include "myscore.h"

class MyGridLayout: public QGridLayout
{
    Q_OBJECT
public:
    MyGridLayout(QTimer *timer, int *score, int* open, MyScore* myscore, bool * is_finished);
    QTimer *timer;
    int *score;
    int* open;
    MyScore* myscore;
    bool *is_finished;
    QTimer *card_timer;
public slots:
    void Check();
    void check_cards();
};

#endif // MYGRIDLAYOUT_H
