#include "dialog.h"
#include "ui_dialog.h"


#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QSurfaceFormat>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QFormLayout>
#include <QListWidget>
#include "login.h"
#include "register.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef QT_NO_OPENGL
#include "dialog.h"
#include "mainwidget.h"
#endif

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->gender = "f";
    this->mainwidget = ui->widget;
    this->actual_color = "null";
    this->id_user = "-1";
}

void Dialog::initialize()
{
    Login *login = new Login(nullptr,this);
    this->stackedWidget = new QStackedWidget;

    Register *registe = new Register(nullptr,stackedWidget);

    //ADDED LOGIN
    stackedWidget->addWidget(login);
    //ADDED REGISTER
    stackedWidget->addWidget(registe);




    //ADDED AVATAR
    QWidget *avatar_widget = new QWidget;


    QVBoxLayout *avatarlayout = new QVBoxLayout;
    QPushButton *back_login = new QPushButton("Login", this);
    connect(back_login, SIGNAL(clicked()), this, SLOT(backLogin()));
    avatarlayout->addWidget(back_login);
    avatarlayout->addWidget(ui->widget);


    QVBoxLayout *optionslayout = new QVBoxLayout;
    //QFormLayout *optionslayout = new QFormLayout;
    //QHBoxLayout * box;
    //QCheckBox *check;


    list_checkboxes = new QListWidget;
    QStringList strList;
    strList <<"Normal" << "Red" << "Blue" << "Green"<< "PBlue"<< "PBrown";
    //<<"PRed"<<"PBlue"<<"PGreen";

    list_checkboxes->addItems(strList);

    QListWidgetItem* item = 0;
    for(int i = 0; i < list_checkboxes->count(); ++i){
        item = list_checkboxes->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        //if(i==0){
        //    item->setCheckState(Qt::Checked);
        //}
        //else{
            item->setCheckState(Qt::Unchecked);
        //}
    }

    //widget->show();
    //widget->setLayout(optionslayout);
    //optionslayout->addItem(item);
    //optionslayout->setWidget(item);


    /*
    box = new QHBoxLayout;
    check = new QCheckBox("Color Normal");
    list_checkbox.push_back(check);
    check->setCheckState(Qt::Checked);

    optionslayout->addRow(check);

    box = new QHBoxLayout;
    check = new QCheckBox("Color Red");
    list_checkbox.push_back(check);
    optionslayout->addRow(check);

    box = new QHBoxLayout;
    check = new QCheckBox("Color Blue");
    list_checkbox.push_back(check);
    optionslayout->addRow(check);

    box = new QHBoxLayout;
    check = new QCheckBox("Color Green");
    list_checkbox.push_back(check);
    optionslayout->addRow(check);*/




    QPushButton *save_data = new QPushButton("Save", this);
    connect(save_data, SIGNAL(clicked()), this, SLOT(savedata()));
    avatarlayout->addWidget(save_data);

    QHBoxLayout *general_layout = new QHBoxLayout;

    general_layout->addLayout(avatarlayout,70);
    general_layout->addWidget(list_checkboxes,30);
    //general_layout->addLayout(optionslayout,30);

    avatar_widget->setLayout(general_layout);
    //avatar_widget->setLayout(avatarlayout);
    //avatar_widget->setLayout(optionslayout);







    stackedWidget->addWidget(avatar_widget);



    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(stackedWidget);

    setLayout(layout);


    /*
    for(int i=0;i<list_checkbox.size(); i++){

        connect( list_checkbox[i], SIGNAL(clicked()), this, SLOT(changecolor()));
    }*/

    QObject::connect(list_checkboxes, SIGNAL(itemClicked(QListWidgetItem*)),
                     this, SLOT(highlightChecked(QListWidgetItem*)));


}

void Dialog::backLogin(){

    stackedWidget->setCurrentIndex(0);
}

void Dialog::savedata(){
    qDebug()<<"Saving data " <<this->id_user <<this->actual_color;

    QSqlQuery query;
    //show dialog with error or correct data entered
    QMessageBox msgBox;


    query.prepare("UPDATE  user SET color =:color WHERE id = :id;");

    query.bindValue(":color", this->actual_color);
    query.bindValue(":id", this->id_user);


    if(!query.exec()){
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text() <<query.lastError().number();
          QString msg = "Error "+ QString(query.lastError().number()) +"al Actualizar Usuario";
          msgBox.setText(msg);
          msgBox.exec();
   }
   else{
        msgBox.setText("Se Actualizo Correctamente");
        msgBox.exec();
    }

}


void Dialog::reset(QString color){

    QListWidgetItem* item = 0;
    for(int i = 1; i < list_checkboxes->count(); ++i){
        item = list_checkboxes->item(i);
        item->setCheckState(Qt::Unchecked);
    }

    if(color == "n"){
        list_checkboxes->item(0)->setCheckState(Qt::Checked);
    }
    else if(color == "r"){
        list_checkboxes->item(1)->setCheckState(Qt::Checked);
    }
    else if(color == "b"){
        list_checkboxes->item(2)->setCheckState(Qt::Checked);
    }
    else if(color == "g"){
        list_checkboxes->item(3)->setCheckState(Qt::Checked);
    }
    else if(color == "p_blue"){
        list_checkboxes->item(4)->setCheckState(Qt::Checked);
    }
    else if(color == "p_brown"){
        list_checkboxes->item(5)->setCheckState(Qt::Checked);
    }

}

void Dialog::highlightChecked(QListWidgetItem *item){
     qDebug()<<"TEXT "<<item->text();

     QString actual_check = item->text();
     if(item->checkState()==Qt::Unchecked){
         item->setCheckState(Qt::Checked);
     }

     if(this->gender == "f"){
        if(item->text()=="Red"){
            ui->widget->ChangeTexture("woman_red.jpg");this->actual_color="r";
        }else if(item->text()=="Blue"){
            ui->widget->ChangeTexture("woman_blue.jpg");this->actual_color="b";
        }else if(item->text()=="Green"){
            ui->widget->ChangeTexture("woman_green.jpg");this->actual_color="g";
        }else if(item->text()=="Normal"){
            ui->widget->ChangeTexture("woman.jpg");this->actual_color="n";
        }else if(item->text()=="PBlue"){
            ui->widget->ChangeTexture("womanp_blue.jpg");this->actual_color="p_blue";
        }else if(item->text()=="PBrown"){
            ui->widget->ChangeTexture("womanp_brown.jpg");this->actual_color="p_brown";
        }
    }
    if(this->gender == "m"){
        if(item->text()=="Red"){
            ui->widget->ChangeTexture("man_red.BMP");this->actual_color="r";
        }else if(item->text()=="Blue"){
            ui->widget->ChangeTexture("man_blue.BMP");this->actual_color="b";
        }else if(item->text()=="Green"){
            ui->widget->ChangeTexture("man_green.BMP");this->actual_color="g";
        }else if(item->text()=="Normal"){
            ui->widget->ChangeTexture("man.BMP");this->actual_color="n";
        }else if(item->text()=="PBlue"){
            ui->widget->ChangeTexture("manp_blue.BMP");this->actual_color="p_blue";
        }else if(item->text()=="PBrown"){
            ui->widget->ChangeTexture("manp_brown.BMP");this->actual_color="p_brown";
        }
    }


     QListWidgetItem* item2 = 0;
     for(int i = 0; i < list_checkboxes->count(); ++i){
         item2 = list_checkboxes->item(i);

         if(item2->text()!=item->text() && item2->checkState()==Qt::Checked){
             item2->setCheckState(Qt::Unchecked);
         }
     }



}


Dialog::~Dialog()
{
    delete ui;
}
