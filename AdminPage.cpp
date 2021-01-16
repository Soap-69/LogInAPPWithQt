#include "AdminPage.h"
#include "ui_AdminPage.h"
#include "invertory.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QInputDialog>

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    connect(ui->pushButton_Quit, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_pushButton_AddInvertory_clicked()
{
    invertory invertoryPage;
    invertoryPage.setModal(true);
    invertoryPage.exec();
}

void AdminPage::on_pushButton_monthlySalesTotal_clicked()
{
    int total = 0;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString text = in.readLine();
            if(!text.isEmpty()){
                QStringList line = text.split(':');
                total = total + (line[2]).toInt();
            }
        }
        QString monthlySale = QString::number(total);
        QMessageBox::warning(this,"Monthlysales", "The Monthly sales price is $" + monthlySale);
        file.close();
    }
}

void AdminPage::on_pushButton_totalTaxes_clicked()
{
    double tax = 0;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString text = in.readLine();
            if(!text.isEmpty()){
                QStringList line = text.split(':');
                //vehicle sale tax in Boston is 6.25%
                tax = tax + (line[2]).toDouble() * 0.0625;
            }
        }
        QString monthlySaleTaxes = QString::number(tax);
        QMessageBox::warning(this,"Monthlysales", "The Monthly total tax is $" + monthlySaleTaxes);
        file.close();
    }
}

void AdminPage::on_pushButton_monthlySalesPerItem_clicked()
{
    int count_911 = 0;
    int count_718 = 0;
    int count_macan = 0;
    int count_cayenne = 0;
    int count_panamera = 0;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString text = in.readLine();
            if(!text.isEmpty()){
                QStringList line = text.split(':');
                if(line[1] == "Macan"){
                    count_macan++;
                }
                if(line[1] == "Cayenne"){
                    count_cayenne++;
                }
                if(line[1] == "718"){
                    count_718++;
                }
                if(line[1] == "911"){
                    count_911++;
                }
                if(line[1] == "Panamera"){
                    count_panamera++;
                }
            }
        }
        QString count_911s = QString::number(count_911);
        QString count_718s = QString::number(count_718);
        QString count_macans = QString::number(count_macan);
        QString count_cayennes = QString::number(count_cayenne);
        QString count_panameras = QString::number(count_panamera);
        QMessageBox::warning(this,"Monthlysales", "Sales per item: \nMacan: " + count_macans + "\nPanamera: " + count_panameras + "\n911: "+ count_911s + "\n718: " + count_718s + "\nCayenne: " + count_cayennes);
        file.close();
    }
}

void AdminPage::on_pushButton_ListOrder_clicked()
{
    QString getName;
    QString vehicleType;
    QString orderNumber;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        bool ok;
        QString text = QInputDialog::getText(this, tr("Search by customer name"),
                                                 tr("Customer name:"), QLineEdit::Normal,
                                                 "", &ok);
        while(!in.atEnd()){
            QString customertext = in.readLine();
            if(!customertext.isEmpty()){
                QStringList line = customertext.split(':');
                getName = line[3];
                orderNumber = line[0];
                vehicleType = line[1];
                if(ok && !text.isEmpty() && text == getName){
                    QMessageBox::information(this,"ListOrder", "The detail of this customer(" + getName + ")(order number and order detail): \n" + orderNumber + "------" + vehicleType);
                }
            }
        }
        file.close();
    }
}

void AdminPage::on_pushButton_SingleOrder_clicked()
{
    QString getOrderID;
    QString vehicleType;
    QString orderNumber;
    QString customerName;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        bool ok;
        QString text = QInputDialog::getText(this, tr("Search by customer name"),
                                                 tr("Customer name:"), QLineEdit::Normal,
                                                 "", &ok);
        while(!in.atEnd()){
            QString customertext = in.readLine();
            if(!customertext.isEmpty()){
                QStringList line = customertext.split(':');
                getOrderID = line[0];
                vehicleType = line[1];
                customerName = line[3];
                if(ok && !text.isEmpty() && text == getOrderID){
                    QMessageBox::information(this,"ListOrder", "The detail of this customer(" + getOrderID + ")(customer name and order detail): \n" + customerName + "------" + vehicleType);
                }
            }
        }
        file.close();
    }
}

void AdminPage::on_pushButton_ListCustomer_clicked()
{
    QString name;
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString text = in.readLine();
            if(!text.isEmpty()){
                QStringList line = text.split(':');
                if(line[0] != "0000"){
                   name = line[3];
                   QMessageBox::information(this,"Customer List", "Customer name by item sales from high to low: \n" +  name);
                   }
             }
        }
        file.close();
    }
}
