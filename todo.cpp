#include "todo.h"
#include "ui_todo.h"
#include "taskadder.h"
#include "syllabus.h"

todo::todo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todo)
{
    ui->setupUi(this);

}

todo::~todo()
{
    delete ui;
}
void todo::on_pushButton_clicked()
{
    /*taskadder AddNewTask;
    AddNewTask.setModal(true);
    AddNewTask.exec();*/
}

void todo::on_pushButton_21_clicked()
{
    syllabus Adder;
    Adder.setModal(true);
    Adder.exec();
}


void todo::on_pushButton_26_clicked()
{
    hide();
}


void todo::on_pushButton_27_clicked()
{

    static int pos1=0,pos2=0;
    pos1++;
    QGridLayout* not_started = ui->not_started;
    QHBoxLayout* taskname = new (QHBoxLayout);
    QLabel * title = new (QLabel);
    QPushButton *details = new (QPushButton);
    details->setText("Details");
    title->setText(ui->task_adder->text());
    ui->task_adder->setText("");
    taskname->addWidget(title,0);
    taskname->addWidget(details,1);
    title->setStyleSheet("color:white;\nfont-size: 20px ;\nfont: bold large;");
    details->setStyleSheet("background-color: #dfb06a;\ncolor:#3d3397;\nfont: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:6;");
    not_started->addLayout(taskname,pos1,pos2);

}
/*void todo :: taskadder(QString & name)
{
    QWidget * taskadder;
    QFormLayout * form ;
    QLineEdit * taskName;
    QPushButton * add ;
    add->setText("Details");
    form->addWidget(taskName);
    form->addWidget(add);
    taskadder->setLayout(form);
    taskadder->show();

}*/
