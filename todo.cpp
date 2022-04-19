#include "todo.h"
#include "ui_todo.h"
#include "taskadder.h"
#include "syllabus.h"
#include "mainwindow.h"
#include<QMessageBox>
#include<QtSql>
todo::todo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todo)
{
    ui->setupUi(this);
    MainWindow x;
    x.db_conn_open();
    load_not_started();
    load_in_progress();
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
    QWidget * parent1 =this->parentWidget();
    hide();
    parent1->show();
}


bool todo::on_pushButton_27_clicked()
{
     extern QString username;
    QString table_name=username+"_not_started";
    QString task=ui->task_adder->text();
    if(task=="")
    {
        QMessageBox::warning(this,"ERROR","Feilds cannot be empty");
        return true;
    }
    QSqlQuery qry,check;
    QString check1="Select * from '"+table_name+"' where taskname='"+task+"'";
    if(check.exec(check1))
    {
        int loop=0;
         while (check.next())
        {
                loop+=1;
        }
         if(loop>=1)
         {
             QMessageBox::warning(this,"Similar task detected","Make sure you enter a different task");
             return false;
         }
    }
    QString query="INSERT into  '"+table_name+"' (taskname) VALUES ('"+task+"')";
    qry.prepare(query);
    if(qry.exec())
    {
        qDebug()<<"Done Successfully";
    }
     else
    {
        qDebug()<< qry.lastError().text();
        return true;
    }
    pos1++;
    QGridLayout* not_started = ui->not_started_2;
    QWidget * widgets = new QWidget;
    QScrollArea * area = ui->not_started;
    widgets->setLayout(not_started);
    area->setWidget(widgets);
    QHBoxLayout* taskname = new (QHBoxLayout);
    QLabel * title = new (QLabel);
    QPushButton *details = new (QPushButton);

    details->setText("Details");
    title->setText(task);
    taskname->addWidget(title,0);
    taskname->addWidget(details,1);
    title->setStyleSheet("color:white;\nfont-size: 20px ;\nfont: bold large;");
    details->setStyleSheet("background-color: #dfb06a;\ncolor:#3d3397;\nfont: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:6;");
    not_started->addLayout(taskname,pos1,0);
    ui->task_adder->setText("");
    connect(details,&QPushButton::clicked,[=](){
        QString table_name_not_started=username+"_not_started";
        QString table_name_on_going=username+"_on_going";
        QSqlQuery delete_;
        QString delete_qry="Delete from '"+table_name_not_started+"' where taskname='"+task+"'";
        QSqlQuery insert;
        QString insert_qry="INSERT INTO '"+table_name_on_going+"' (taskname) values ('"+task+"')";
        if(delete_.exec(delete_qry))
        {
            qDebug()<<"Deleted my g";
        }
        else
        {
            qDebug()<<"NOt delered"+delete_.lastError().text();
        }

        if(insert.exec(insert_qry))
        {
            if(delete_.exec(delete_qry))
            {
                qDebug()<<"Insert";
                pos1=0;
                pos2=0;
                load_not_started();
                load_in_progress();
            }
        }
                else
        {
                qDebug()<<"Not inserted";
        }
    });

    return true;
}

void todo::load_not_started()
{
    extern QString username;
    QString table_name=username+"_not_started";
    pos1++;
    QGridLayout* not_started = ui->not_started_2;
    QWidget * widgets = new QWidget;
    QScrollArea * area = ui->not_started;
    widgets->setLayout(not_started);
    area->setWidget(widgets);

    QSqlQuery get_data;
    QString qry="Select taskname from '"+table_name+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new (QHBoxLayout);
               QLabel * title = new (QLabel);
               QPushButton *details = new (QPushButton);
               details->setText("Details");
               QSize size= QSize(4,4);
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color:white;\nfont-size: 20px ;\nfont: bold large;");
               details->setStyleSheet("background-color: #dfb06a;\ncolor:#3d3397;\nfont: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:6;");
               not_started->addLayout(taskname,pos1,0);
               ui->task_adder->setText("");
               pos1+=1;
           }
    }

}
void todo::load_in_progress()
{
    extern QString username;
    QString table_name=username+"_on_going";
    pos2++;
    QGridLayout* not_started = ui->on_going_2;
    QWidget * widgets = new QWidget;
    QScrollArea * area = ui->on_going;
    widgets->setLayout(not_started);
    area->setWidget(widgets);

    QSqlQuery get_data;
    QString qry="Select taskname from '"+table_name+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new (QHBoxLayout);
               QLabel * title = new (QLabel);
               QPushButton *details = new (QPushButton);
               details->setText("Details");
               QSize size= QSize(4,4);
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color:white;\nfont-size: 20px ;\nfont: bold large;");
               details->setStyleSheet("background-color: #dfb06a;\ncolor:#3d3397;\nfont: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:6;");
               not_started->addLayout(taskname,pos2,0);
               ui->task_adder->setText("");
               pos2+=1;
}
}
}
void todo:: load_completed()
{
    extern QString username;
    QString table_name=username+"_not_started";
    pos1++;
    QGridLayout* not_started = ui->completed_2;
    QWidget * widgets = new QWidget;
    QScrollArea * area = ui->not_started;
    widgets->setLayout(not_started);
    area->setWidget(widgets);

    QSqlQuery get_data;
    QString qry="Select taskname from '"+table_name+"'";
    if(get_data.exec(qry))
    {

           while (get_data.next())
           {
               QString task=get_data.value(0).toString();
               QHBoxLayout* taskname = new (QHBoxLayout);
               QLabel * title = new (QLabel);
               QPushButton *details = new (QPushButton);
               details->setStyleSheet("min-width: 150px;");
               QSize size= QSize(4,4);
               details->resize(size);
               title->setText(task);
               taskname->addWidget(title,0);
               taskname->addWidget(details,1);
               title->setStyleSheet("color:white;\nfont-size: 20px ;\nfont: bold large;");
               details->setStyleSheet("background-color: #dfb06a;\ncolor:#3d3397;\nfont: bold 20px ; \nborder-width: 5px;\nborder-radius: 15px; padding:6;");
               not_started->addLayout(taskname,pos1,0);
               ui->task_adder->setText("");
               pos1+=1;
}
}
}
int todo:: pos1=0;
int todo:: pos2=0;
int todo:: pos3=0;
