#include "signup.h"
#include "ui_signup.h"
#include <QtSql>
#include<QMessageBox>
#include<mainwindow.h>
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    QString full_name,nickname,email,username,password,date;
    full_name=ui->lineEdit->text();
    nickname=ui->lineEdit_2->text();
    username=ui->lineEdit_5->text();
    password=(ui->lineEdit_6->text());
    date = ui->lineEdit_4->text();
    if(full_name=="" || nickname ==""||username==""||password==""||date=="")
    {
        QMessageBox::warning(this,"Incomplete information","Make sure you have entered all the fields.");

    }
    QRegularExpression username_pattern("^[a-zA-Z0-9_-]{5,10}$");//only includes alphabets or digits or underscore or hyphen; 5 to 10 characters
    QRegularExpressionMatch username_is_valid = username_pattern.match(username);

    QRegularExpression password_pattern("^.*(?=.{8,})(?=.*[a-zA-Z])(?=.*\\d)(?=.*[!@#$%^&-+=()])(?=\\S+$).*$");
    QRegularExpressionMatch password_is_valid = password_pattern.match(password);
    if(password_is_valid.hasMatch()&&username_is_valid.hasMatch())
    {
        QSqlQuery qry1;
        if(qry1.exec("Select * from HI where username='"+username+"'"))
        {
            int loop=0;
            while (qry1.next())
            {
                loop+=1;

            }00
          if(loop>=1)
            {
                QMessageBox::warning(this,"User already registered!","Please try a different username.");
            }
        }
        encrypt(password);
        QSqlQuery qry,not_started,on_going,completed;
        qry.prepare("Insert into HI (full_name,nickname,username,password1,DOB) values('"+full_name+"','"+nickname+"','"+username+"','"+password+"','"+date+"')");
        if(qry.exec())
        {


            QString not_started_qry="Create Table '"+username+"_not_started'(taskname varchar(100))",on_going_qry="Create Table '"+username+"_on_going'(taskname varchar(100))",completed_qry="Create Table '"+username+"_completed' (taskname varchar(100))";
            not_started.exec(not_started_qry);
            on_going.exec(on_going_qry);
            completed.exec(completed_qry);
            QMessageBox::information(this,"User Registered","You have been registered.");
            this->hide();
            QWidget *parent = this->parentWidget();
            parent->show();
        }
    }
    else{
    if (!username_is_valid.hasMatch() && !password_is_valid.hasMatch())
        QMessageBox::warning(this, "Invalid username and password", "Your username:\n  - may include letters, numbers, underscore or hyphen.\n  - needs to include 5 to 10 characters.\n\nYour password must :\n  - include at least one letter, number and symbol.\n  - be at least 8 characters long.");
    else if (!username_is_valid.hasMatch())
        QMessageBox::warning(this, "Invalid username", "Your username:\n  - may include letters, numbers, underscore or hyphen.\n  - needs to include 5 to 10 characters.");
    else if (!password_is_valid.hasMatch())
        QMessageBox::warning(this, "Invalid password", "Your password must:\n  - include at least one letter, number and symbol.\n  - be at least 8 characters long.");
}
}
void signup::encrypt(QString &string_encrypt)
{

    QString p_text = string_encrypt;
    int k=598658, value,ascii;

    for (int i = 0; i < p_text.size(); i++)
    {
        ascii = (p_text[i]).QChar::unicode();
        if (ascii >= 48 && ascii <= 57)
        {
            value = ((ascii + k - 48) % 10 + 48);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            value = ((ascii + k - 65) % 26 + 65);
            string_encrypt[i] = static_cast<char>(value);
        }
        else if (ascii >= 97 && ascii <= 122)
        {
            value = ((ascii + k - 97) % 26 + 97);
            string_encrypt[i] = static_cast<char>(value);
        }
        else
        {
            string_encrypt[i] = static_cast<char>(ascii);
        }
    }
}



void signup::on_pushButton_2_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

