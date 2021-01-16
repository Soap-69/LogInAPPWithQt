#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AdminPage.h"
#include "CustomerPage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "admin" && password == "1234"){
       adminpage = new AdminPage(this);
       adminpage->show();
       QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
       if(file.open(QFile::ReadOnly | QFile::Text)){
           QTextStream in(&file);
           while(!in.atEnd()){
               QString text = in.readLine();
               if(!text.isEmpty()){
                   QStringList line = text.split(':');
                   if(line[3] == "0"){
                       QMessageBox::warning(this,"Stock Warning!", line[1] + " needs resupply!");
                   }
               }
           }
          file.close();
       }
    }
    else{
        hide();
        customerpage = new CustomerPage(this);
        customerpage->show();
    }
}
