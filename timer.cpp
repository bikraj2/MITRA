#include "timer.h"
#include "ui_timer.h"
#include<QMessageBox>
timer::timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timer)
{
    ui->setupUi(this);
    this->setWindowTitle("Stopwatch");
    ms = s = m = 0;

    // buttons
    startButton = new QPushButton(this);
    startButton->setText("Start");
    startButton->setGeometry(10,10,75,25);
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));

    resetButton = new QPushButton(this);
    resetButton->setText("Reset");
    resetButton->setGeometry(90,10,75,25);
    connect(resetButton,SIGNAL(clicked()),this,SLOT(reset()));

    // label
    label = new QLabel(this);
    label->setGeometry(0,100,250,100);
    QFont font = label->font();
    font.setPointSize(40);
    font.setBold(true);
    label->setFont(font);
    label->setText(intToQString(m)+":"+intToQString(s));

    // timer
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(changeTime()));

}

timer::~timer()
{
    delete ui;
}

QString timer::intToQString(int num){
    QString str = QString::number(num);

    if(str.length() == 1){
        str = "0"+str;
    }

    return str;
}

void timer::changeTime(){
    ms++;
    if(ms>=100){
        ms=0;
        s++;
    }


    if(s>=60){
        s=0;
        m++;
    }
     void alert();
    //...
    label->setText(intToQString(m)+":"+intToQString(s));
}
void timer::start(){
    timer1->start(10);
    startButton->setText("Stop");
    connect(startButton,SIGNAL(clicked()),this,SLOT(stop()));
    QMessageBox:: about(this, "Focus", "Session Started") ;

}

void timer::stop(){
    timer1->stop();
    startButton->setText("Start");
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
}

void timer::reset(){
    ms = s = m = 0;
    label->setText(intToQString(m)+":"+intToQString(s));
    stop();

}



void timer::on_pushButton_clicked()
{
    this->hide();
    QWidget * parent  = this->parentWidget();
    parent->show();
}

