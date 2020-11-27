#ifndef MYCARD_H
#define MYCARD_H
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class MyCard:public QPushButton
{
    Q_OBJECT
public:
    MyCard(const QString& text, int* open, bool *is_finished, QWidget* parent=0, const QString& space=" ");
    QLabel *label;
    QString text;
    int *open;
    bool *is_finished;
    bool is_removed;
    bool is_clicked;
    void makeRemove();
    void makeInvisible();
    void makeShow();
public slots:
    void arrange();
};

#endif // MYCARD_H
