#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include<QPushButton>
#include<QTimer>
#include<QLabel>



namespace Ui {
class timer;
}

class timer : public QDialog
{
    Q_OBJECT

public:
    explicit timer(QWidget *parent = nullptr);
    ~timer();

    QLabel *label;
    int m,s, ms;

public slots:
    QString intToQString(int num);
    void changeTime();
    void start();
    void stop();
    void reset();



private:



    QPushButton *startButton;
    QPushButton *resetButton;
    Ui::timer *ui;
    QTimer *timer1;

private slots:





};


#endif // TIMER_H
