#include <QApplication>
#include <QWidget>
#include "mytimer.h"
#include "myscore.h"
#include "mygridlayout.h"
#include "mycard.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <algorithm>
#include <QVector>
#include <iostream>
#include "newgame.h"
#include <time.h>
#include <QSpacerItem>

using namespace std;

//values to give the cards
QString texts[30]= {"van Gogh", "Picasso", "da Vinci", "Warhol", "Michelangelo", "Matisse",
                    "Pollock", "Munch", "Monet", "Magritte", "Dali", "Hopper", "Kahlo", "Kusama", "Rousseau",
                  "van Gogh", "Picasso", "da Vinci", "Michelangelo", "Warhol", "Matisse",
                    "Pollock", "Munch", "Monet", "Magritte", "Dali", "Hopper", "Kahlo", "Kusama", "Rousseau"};


//random number generator to use after in random_shuffle
int random(int i){
    return rand()%i;
}

//main function to arrange all the objects, functions, and variables
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);
    //used widgets and layouts to arrange others
    QWidget *qw = new QWidget();
    QVBoxLayout *qv = new QVBoxLayout;
    QHBoxLayout *qh = new QHBoxLayout;
    //quit button (when clicked it will end the game)
    QPushButton *quitButton = new QPushButton("Quit");
    int open = 0;
    int score = 0;
    bool is_finished = false;

    QObject::connect(quitButton, SIGNAL(clicked()), &app, SLOT(quit()));


    MyTimer *myTimer = new MyTimer(&is_finished);
    MyScore *myScore = new MyScore(&score, myTimer->timer, &is_finished);

    MyGridLayout *gridLayout = new MyGridLayout(myTimer->timer, &score, &open, myScore, &is_finished);


    random_shuffle(&texts[0], &texts[29], random);

    NewGame *newGameButton = new NewGame(myTimer, myScore, gridLayout, texts, &open, &is_finished);

    //arranges grid and the cards inside
    int i = 0;
    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            MyCard *c = new MyCard(texts[i], &open, &is_finished);
            QObject::connect(c, SIGNAL(clicked()), c, SLOT(arrange()));
            QObject::connect(c, SIGNAL(clicked()), gridLayout, SLOT(check_cards()));
            gridLayout->addWidget(c, row, col, 1, 1);
            i++;
        }
    }

    //will arrange the grid and the header
    QSpacerItem *qSpace = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);


    //arranges the orders of items
    qh->addWidget(myTimer->label);
    qh->addWidget(myScore->label);
    qh->addWidget(newGameButton);
    qh->addWidget(quitButton);

    qv->addLayout(qh);
    qv->addSpacerItem(qSpace);
    qv->addLayout(gridLayout);


    qw->setWindowTitle("Card Match Game");
    qw->resize(960, 540);
    qw->setLayout(qv);
    qw->show();

    return app.exec();
}

