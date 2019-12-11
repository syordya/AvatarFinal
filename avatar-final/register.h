#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QStackedWidget>


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr,QStackedWidget *stack = nullptr);
    ~Register();

    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void changeGenderMale(bool active);
    void changeGenderFemale(bool active);

private:
    Ui::Register *ui;
     QStackedWidget * stack;
};

#endif // REGISTER_H
