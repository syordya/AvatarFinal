#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedWidget>
#include "mainwidget.h"
#include "dialog.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr,Dialog * dialog=nullptr);
    //Login(QStackedWidget * stack);
    ~Login();

    void DatabaseConnect();
private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    Dialog *dialog;
    QStackedWidget * stack;
    MainWidget * mainwidget;
};

#endif // LOGIN_H
