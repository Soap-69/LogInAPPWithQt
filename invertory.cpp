#include "invertory.h"
#include "ui_invertory.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

invertory::invertory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::invertory)
{
    ui->setupUi(this);
}

invertory::~invertory()
{
    delete ui;
}

void invertory::on_pushButton_write_clicked()
{
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"title", "file not open");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void invertory::on_pushButton_read_clicked()
{
    QFile file("C:/Users/Augus/Documents/FinalProject/invertory.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title", "file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void invertory::on_pushButton_undo_clicked()
{
    ui->plainTextEdit->undo();
}
