#ifndef NEWGAME_H
#define NEWGAME_H
#include <QLabel>
#include <QPushButton>
#include "mytimer.h"
#include "myscore.h"
#include "mygridlayout.h"
#include <algorithm>
#include <QGridLayout>
#include "mycard.h"
#include <time.h>

class NewGame: public QPushButton
{
    Q_OBJECT
public:
    NewGame(MyTimer *myTimer, MyScore *myScore, MyGridLayout *myGrid, QString texts[], int* open, bool* is_finished);
    MyTimer *myTimer;
    MyScore *myScore;
    MyGridLayout *myGrid;
    QString texts[30];
    int *open;
    bool *is_finished;
public slots:
    void makeNew();
};

#endif // NEWGAME_H
