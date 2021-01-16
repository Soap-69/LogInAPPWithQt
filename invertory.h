#ifndef INVERTORY_H
#define INVERTORY_H

#include <QDialog>

namespace Ui {
class invertory;
}

class invertory : public QDialog
{
    Q_OBJECT

public:
    explicit invertory(QWidget *parent = nullptr);
    ~invertory();

private slots:
    void on_pushButton_write_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_undo_clicked();

private:
    Ui::invertory *ui;
};

#endif // INVERTORY_H
