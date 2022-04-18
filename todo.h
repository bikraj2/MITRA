#ifndef TODO_H
#define TODO_H

#include <QDialog>
#include <QScrollArea>

namespace Ui {
class todo;
}

class todo : public QDialog
{
    Q_OBJECT

public:
    explicit todo(QWidget *parent = nullptr);


    ~todo();
public slots:


private slots:

    void on_pushButton_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

private:
    Ui::todo *ui;
};

#endif // TODO_H
