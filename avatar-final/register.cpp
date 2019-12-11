#include "register.h"
#include "ui_register.h"
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

Register::Register(QWidget *parent,QStackedWidget *stack) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->stack = stack;

    //ui->checkMan
   QObject::connect(ui->checkMan, SIGNAL(clicked(bool)), this, SLOT(changeGenderMale(bool)));
   QObject::connect(ui->checkWoman, SIGNAL(clicked(bool)), this, SLOT(changeGenderFemale(bool)));

   // -- DATABASE INIT --
   //in db id interger (primary key), username text,password text , gender text;

   //DatabaseConnect();
   //DatabaseInit();
   //DatabasePopulate();

}

Register::~Register()
{
    delete ui;
}


void Register::DatabaseConnect()
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


void Register::DatabaseInit()
{

    QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");

    if(!query.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}


void Register::DatabasePopulate()
{
    /*
    QSqlQuery query;

    if(!query.exec("INSERT INTO user(username,password,email,gender) VALUES('Juan','12345','juan@gmail.com','m')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text() <<query.lastError().number();
    if(!query.exec("INSERT INTO user(username,password,email,gender) VALUES('Maria','12345','maria@gmail.com','f')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

    */
}


void Register::on_pushButton_2_clicked()
{

    //show dialog with error or correct data entered
    QMessageBox msgBox;

    QString username= ui->username->text();
    QString password = ui->password->text();
    QString email = ui->email->text();
    QString color ="n";

    qDebug()<<email;
    QString gender;

    if(username.isEmpty() || password.isEmpty() || email.isEmpty() ){
        msgBox.setText("FALTA INGRESAR DATOS");
        msgBox.exec();
        return;
    }

    if(ui->checkMan->isChecked()){
        gender = "m";
    }
    else if(ui->checkWoman->isChecked()){
        gender = "f";
    }
    else{
        //ALERT NO CHECK
        msgBox.setText("No ha seleccionado ningun genero");
        msgBox.exec();
        return;
    }



    QSqlQuery query;

    //QString squery =
    // "INSERT INTO user(username,password,email,gender) VALUES("+"'"+username+"'"+","+password+","+email+","+gender+")";


    query.prepare("INSERT INTO user(username, password,email,gender,color) VALUES (:name, :pass,:email,:gender,:color)");

    query.bindValue(":name", username);
    query.bindValue(":pass", password);
    query.bindValue(":email", email);
    query.bindValue(":gender", gender);
    query.bindValue(":color", color);

    if(!query.exec()){
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text() <<query.lastError().number();
          QString msg = "Error "+ QString(query.lastError().number()) +"al Registrar Usuario";
          msgBox.setText(msg);
          msgBox.exec();
   }
   else{
        msgBox.setText("Usuario Registrado Correctamente");
        msgBox.exec();
        this->stack->setCurrentIndex(0);
    }





}

void Register::on_pushButton_clicked()
{
    this->stack->setCurrentIndex(0);
}

void Register::changeGenderMale(bool active)
{
    //qDebug()<<"BOOL "<<active;
    if(active==true && ui->checkWoman->isChecked()==true){
        ui->checkWoman->setCheckState(Qt::Unchecked);
    }

}

void Register::changeGenderFemale(bool active)
{
    //qDebug()<<"BOOL "<<active;
    if(active==true && ui->checkMan->isChecked()==true){
        ui->checkMan->setCheckState(Qt::Unchecked);
    }
}
