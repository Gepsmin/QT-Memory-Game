#include "mygridlayout.h"
#include <iostream>

using namespace std;

//child of QGridLayout class
//stores the game variables and controls the whether choosen cards are the same or not
MyGridLayout::MyGridLayout(QTimer *timer, int* score, int* open, MyScore* myscore, bool* is_finished):QGridLayout()
{
    this->timer = timer;
    this->score = score;
    this->open = open;
    this->myscore = myscore;
    this->is_finished= is_finished;
    this->card_timer = new QTimer();
    QObject::connect(this->card_timer,SIGNAL(timeout()), this, SLOT(Check()));
}

//slot function to check the open cards
//it holds the cards open 0.5 secs
void MyGridLayout::check_cards(){
    if(*(this->open)<2){
        //*(this->open)+=1;
        //Bu islemi card icinde yapmam lazim remove olayini kontrol edebilmek icin

    }else if(!*(this->is_finished)){
        this->card_timer->start(500);
    }
}

//checks open cards values and manages them
//if they are the same calls the scorer function to add 1 to the score
void MyGridLayout::Check(){

    QString prev = "";
    *(this->open)= 0;
    MyCard *prevCard;
    this->card_timer->stop();
    if(!*(this->is_finished)){
        for(int i= 0; i<this->count(); i++){
            MyCard *card = qobject_cast<MyCard*>(this->itemAt(i)->widget());
            QString s = card->label->text();
            if(s!=""&&s!="?"){
                if(prev==""){
                    prev = s;
                    prevCard = card;
                }else if(prev==s){
                    card->makeRemove();
                    prevCard->makeRemove();
                    this->myscore->scorer();
                }else{
                    card->makeInvisible();
                    prevCard->makeInvisible();
                }
            }
        }
    }

}
