#include "login.h"
#include "ui_login.h"
#include "mainwidget.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

Login::Login(QWidget *parent,Dialog *dialog) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //this->stack = stack;
    //this->mainwidget = mainwidget;
    this->dialog = dialog;
    DatabaseConnect();

}


Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //ingresar main menu (avatar)

    qDebug()<<"main avatar";

    //show dialog with error or correct data entered
    QMessageBox msgBox;

    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare( "SELECT * FROM user WHERE username = ? and password = ?" );
    query.bindValue( 0, username );
    query.bindValue( 1, password );

    if(username.isEmpty() || password.isEmpty()){
        msgBox.setText("USUARIO O PASSWORD NO INGRESADO");
        msgBox.exec();
        return;
    }

    if( !query.exec() )
    {
      // Error Handling, check query.lastError(), probably return
        msgBox.setText("USUARIO O PASSWORD INCORRECTOS");
        msgBox.exec();
        return;
    }

    if(query.next()==false){
        msgBox.setText("USUARIO O PASSWORD INCORRECTOS");
        msgBox.exec();
        return;
    }else{
        //qDebug()<<query.value(1)<<query.value(2)<<query.value(3)<<query.value(4);

        dialog->reset(query.value(5).toString());
        dialog->stackedWidget->setCurrentIndex(2);
        //for change the model
        dialog->mainwidget->InitModel(query.value(4).toString(),query.value(5).toString());
        //for change the clothes
        dialog->gender = query.value(4).toString().toStdString();
        //add user
        dialog->id_user = query.value(0).toString();
        //add color before
        dialog->actual_color = query.value(5).toString();

    }

}

void Login::DatabaseConnect()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName("user.db");

        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}


void Login::on_pushButton_2_clicked()
{
    dialog->stackedWidget->setCurrentIndex(1);
}
