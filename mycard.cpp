#include "mycard.h"
#include <iostream>

using namespace std;

//Child class of QPushButton
//every object stores the value that given before
MyCard::MyCard(const QString& text, int* open,bool* is_finished, QWidget* parent, const QString& space):QPushButton(space, parent)
{
    this->label = new QLabel("?");
    this->is_removed = false;
    this->is_clicked = false;
    this->text = text;
    this->open = open;
    this->is_finished = is_finished;
    this->setText(this->label->text());
}

//slot function
//checks the number of current opened card
void MyCard::arrange(){
    if(*(this->open)<2){
        makeShow();
    }
}

//makes the cards value to empty
//modifies the bool values to continue
void MyCard::makeRemove(){
    if(!*(this->is_finished)){
        this->is_removed = true;
        this->label->setText("");
        this->setText(this->label->text());
        *(this->open) = 0;
        update();
    }

}

//makes the cards value to '?'
//modifies the bool values to continue
void MyCard::makeInvisible(){
    if(!is_removed&&is_clicked&&!*(this->is_finished)){
        this->is_clicked= false;
        this->label->setText("?");
        this->setText(this->label->text());
        *(this->open) = 0;
        update();
    }
}

//makes the cards value to given value
//modifies the bool values to continue
void MyCard::makeShow(){
    if(!is_removed&&!is_clicked&&!*(this->is_finished)&&*(this->open)<2){
        *(this->open)+=1;
        this->is_clicked = true;
        this->label->setText(this->text);
        this->setText(this->label->text());
        update();
    }
}
