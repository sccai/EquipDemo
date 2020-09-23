#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();


private:
    Ui::MyDialog *ui;


public:
    void SetText(const QString &text);

private slots:
    void initForm();
    void on_pushButton_Cancle_clicked();
    void on_pushButton_Save_clicked();
};

#endif // MYDIALOG_H
