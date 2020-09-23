#ifndef PARAWINDOW_H
#define PARAWINDOW_H

#include <QDialog>
#include "tool/paramterclass.h"

namespace Ui {
class ParaWindow;
}

class ParaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ParaWindow(QWidget *parent = 0);
    ~ParaWindow();

private:
    Ui::ParaWindow *ui;

public:
    void LoadParamter();
    void SaveParamter2File(ParamterClass *paramterClass);
    ParamterClass *para;
private slots:
    void initForm();
    void on_pushButton_Cancle_clicked();
    void on_pushButton_Save_clicked();
};

#endif // PARAWINDOW_H
