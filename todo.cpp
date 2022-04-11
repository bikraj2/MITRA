#include "todo.h"
#include "ui_todo.h"
#include "taskadder.h"
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
