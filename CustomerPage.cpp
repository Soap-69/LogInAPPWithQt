#include "CustomerPage.h"
#include "ui_CustomerPage.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QInputDialog>


CustomerPage::CustomerPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerPage)
{
    ui->setupUi(this);
     connect(ui->pushButton_Exit, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}

CustomerPage::~CustomerPage()
{
    delete ui;
}


void CustomerPage::on_pushButton_checkou_clicked()
{
    double total = 0;
    if(ui->checkBox_macan->isChecked()){
        total += 52100 * 1.0625;
    }
    if(ui->checkBox_3->isChecked()){
        total += 67500 * 1.0625;
    }
    if(ui->checkBox_718->isChecked()){
        total += 59900 * 1.0625;
    }
    if(ui->checkBox_911->isChecked()){
        total += 99200 * 1.0625;
    }
    if(ui->checkBox_panamera->isChecked()){
        total += 87200 * 1.0625;
    }
    QString totals = QString::number(total);
    QMessageBox::information(this, "checkout", "Your total is: $" + totals);
}


void CustomerPage::on_pushButton_availability_clicked()
{
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString text = in.readLine();
            if(!text.isEmpty()){
                QStringList line = text.split(':');
                if(line[3] == "0" && line[1] == "PORSCHE_718"){
                    ui->checkBox_718->hide();
                }
                if(line[3] == "0" && line[1] == "PORSCHE_Macan"){
                    ui->checkBox_macan->hide();
                }
                if(line[3] == "0" && line[1] == "PORSCHE_Panamera"){
                    ui->checkBox_panamera->hide();
                }
                if(line[3] == "0" && line[1] == "PORSCHE_911"){
                    ui->checkBox_911->hide();
                }
                if(line[3] == "0" && line[1] == "PORSCHE_Cayenne"){
                    ui->checkBox_3->hide();
                }
            }
        }
    }
}
