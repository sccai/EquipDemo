#ifndef PARAFORM_H
#define PARAFORM_H

#include <QWidget>

namespace Ui {
class ParaForm;
}

class ParaForm : public QWidget
{
    Q_OBJECT

public:
    explicit ParaForm(QWidget *parent = 0);
    ~ParaForm();


private:
    Ui::ParaForm *ui;


public:
    void SetText(const QString &text);

private slots:
    void initForm();
    void on_pushButton_Cancle_clicked();
    void on_pushButton_Save_clicked();
};


#endif // PARAFORM_H
