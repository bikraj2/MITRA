#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtSql>
#include <QMainWindow>
#include"dialog1.h"
#include "signup.h"
#include "forgotpassword.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
        QSqlDatabase db;
        void connClose()
        {
            db.close();
            db.removeDatabase(QSqlDatabase::defaultConnection);
        }
        bool connOpen()
        {
            QDir data("C:/Db");
                if (!data.exists())
                {
                    data.mkpath("C:/Db");
                }
                db  =  QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("C:/Db/users.db");
                db.open();
                if(!db.open())
                {
                    qDebug()<<"Failed to connect to database.!!";
                    return true;
                }
                else
                {
                    qDebug()<<"Connected Successdully";
                    return false;
                }
        }
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_pushButton_login_3_clicked();

    void on_pushButton_singup_3_clicked();

    bool setTable();
    void encrypt(QString &string_encrypt);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    Dialog1 *firstwindow;
    signup * register1;
    ForgotPassword * password1;
};
#endif // MAINWINDOW_H
