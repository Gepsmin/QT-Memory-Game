#include "mytimer.h"
#include <iostream>

using namespace  std;

//class to store the time value
MyTimer::MyTimer(bool *is_finished)
{
    this->counter = 0;
    this->is_finished = is_finished;
    this->label = new QLabel("Times (secs): 0");
    this->timer = new QTimer();

    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(Timer()));

    this->timer->start(1000);
}

//slot function to manipulate the stored time value
//every clock tick adds 1 to the time variable
//when the game reach the time limit it prompts a message that states the game lost
void MyTimer::Timer(){
    this->counter += 1;
    this->label->setText("Times (secs): "+ QString::number(this->counter));
    if(this->counter>=180){
        this->timer->stop();
        *(this->is_finished) = true;
        QMessageBox *qm = new QMessageBox();
        qm->setText("You Failed!");
        qm->setStandardButtons(QMessageBox::Close);
        qm->setIcon(QMessageBox::Critical);
        qm->exec();
    }
}
