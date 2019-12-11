#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QStackedWidget>
#include <QOpenGLWidget>
#include <vector>
#include <QCheckBox>
#include <QListWidgetItem>
#include <mainwidget.h>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QOpenGLWidget *firstPageWidget;
    void initialize();
    QStackedWidget *stackedWidget;
    QListWidget *list_checkboxes;
    vector<QCheckBox*> list_checkbox;
    MainWidget * mainwidget;
    string gender;
    QString id_user;
    QString actual_color;
    ~Dialog();

    void reset(QString color);
private slots:
    void backLogin();
    void savedata();
public slots:
    void highlightChecked(QListWidgetItem *item);
private:
    Ui::Dialog *ui;


};



#endif // DIALOG_H
