#include "newgame.h"
#include <iostream>

using namespace std;

//random number generator to use after in random_shuffle
int random2(int i){
    return rand()%i;
}

//child class of QPushButton
//it stores the values used to manage the game and manipuletes them when clicked
NewGame::NewGame(MyTimer *myTimer, MyScore *myScore, MyGridLayout *myGrid, QString texts[], int* open, bool* is_finished)
{
    srand(time(NULL));
    this->myGrid = myGrid;
    this->myScore = myScore;
    this->myTimer = myTimer;
    this->setText("New Game");
    this->open = open;
    this->is_finished = is_finished;
    for(int i=0; i<30; i++){
        this->texts[i]= texts[i];
    }
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(makeNew()));
}


//slot function to react when clicked
//resets the time
//resets the score
//marks the game as not finished
//reorganizes the grid with new MyCard Objects
void NewGame::makeNew(){


    random_shuffle(&(this->texts[0]), &(this->texts[29]),random2);
    this->myTimer->counter = 0;
    this->myTimer->label->setText("Times (secs): 0");
    this->myTimer->timer->start(1000);
    *(this->myScore->score) = 0;
    this->myScore->label->setText("Score: 0");
    *(this->open)= 0;
    *(this->is_finished) = false;

    for(int i =0; i <this->myGrid->count(); i++){
        MyCard *card = qobject_cast<MyCard*>(this->myGrid->itemAt(i)->widget());
        card->label->setText("?");
        card->is_removed = false;
        card->is_clicked = false;
        card->text = texts[i];
        card->setText(card->label->text());
    }

}
