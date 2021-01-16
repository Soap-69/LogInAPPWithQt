#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT


public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_pushButton_AddInvertory_clicked();

    void on_pushButton_monthlySalesTotal_clicked();


    void on_pushButton_totalTaxes_clicked();

    void on_pushButton_monthlySalesPerItem_clicked();

    void on_pushButton_ListOrder_clicked();


    void on_pushButton_SingleOrder_clicked();

    void on_pushButton_ListCustomer_clicked();

private:
    Ui::AdminPage *ui;
};

#endif // ADMINPAGE_H
