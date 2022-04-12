#include "notes.h"
#include "ui_notes.h"

Notes::Notes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notes)
{
    ui->setupUi(this);
}

Notes::~Notes()
{
    delete ui;
}
