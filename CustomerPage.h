#ifndef CUSTOMERPAGE_H
#define CUSTOMERPAGE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class CustomerPage;
}

class CustomerPage : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerPage(QWidget *parent = nullptr);
    ~CustomerPage();

private slots:
    void on_pushButton_checkou_clicked();
    void on_pushButton_availability_clicked();

private:
    Ui::CustomerPage *ui;
    QVector<CustomerPage*> vCustomerPage;
};

#endif // CUSTOMERPAGE_H
