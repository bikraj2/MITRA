#include "notes.h"
#include "ui_notes.h"

notes::notes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notes)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

notes::~notes()
{
    delete ui;
}

void notes::on_actionNew_triggered()
{

}


void notes::on_actionOpen_triggered()
{

}


void notes::on_actionSave_triggered()
{

}


void notes::on_actionSave_as_triggered()
{

}


void notes::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void notes::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void notes::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void notes::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void notes::on_actionUndo_triggered()
{   ui->textEdit->undo();

}


void notes::on_actionAbout_Notepad_triggered()
{

}

