#ifndef SELFCHECKFORM_H
#define SELFCHECKFORM_H

#include "iostream"
#include <QWidget>
#include "QVector"
#include "singlecheckdevice.h"
namespace Ui {
class SelfCheckForm;
}

class SelfCheckForm : public QWidget
{
    Q_OBJECT

public:
    explicit SelfCheckForm(QWidget *parent = nullptr);
    ~SelfCheckForm();
    void initForm();
    void InitEquip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SelfCheckForm *ui;
    int  index=0;
    QVector<SingleCheckDevice*> singVec;
    SingleCheckDevice * m_pMyThread;

public slots:

};

#endif // SELFCHECKFORM_H
