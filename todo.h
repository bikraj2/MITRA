#ifndef TODO_H
#define TODO_H

#include <QDialog>

namespace Ui {
class todo;
}

class todo : public QDialog
{
    Q_OBJECT

public:
    explicit todo(QWidget *parent = nullptr);
    ~todo();
private slots:
    void on_pushButton_clicked();

private:
    Ui::todo *ui;
};

#endif // TODO_H
