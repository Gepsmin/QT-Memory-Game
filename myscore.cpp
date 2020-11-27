#include "myscore.h"
#include <iostream>

using namespace std;

//stores the score value
MyScore::MyScore(int* score, QTimer *timer, bool* is_finished)
{
    this->score = score;
    this->label = new QLabel("Score: 0");
    this->timer = timer;
    this->is_finished = is_finished;
}

//slot function to manipulate the stored score variable
//every correct choosen card will adds 1 to the score variable
//when the score reach the 15 it prompts a message that states the game won
void MyScore::scorer(){
    *(this->score)+=1;
    this->label->setText("Score: "+ QString::number(*(this->score)));
    if(*(this->score)>=15&&!*(this->is_finished)){
        this->timer->stop();
        *(this->is_finished) = true;
        QMessageBox *qm = new QMessageBox();
        qm->setText("You Won!");
        qm->setStandardButtons(QMessageBox::Close);
        qm->setWindowTitle("Congratulations");
        qm->setIcon(QMessageBox::Information);
        qm->exec();
    }

}

