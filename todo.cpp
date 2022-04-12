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
    taskadder AddNewTask;
    AddNewTask.setModal(true);
    AddNewTask.exec();
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

