#ifndef INDEXFORM_H
#define INDEXFORM_H

#include <QWidget>

class QToolButton;

namespace Ui {
class IndexForm;
}

class IndexForm : public QWidget
{
    Q_OBJECT

public:
    explicit IndexForm(QWidget *parent = 0);
    ~IndexForm();

private:
    Ui::IndexForm *ui;
    QList<QToolButton *> btns;

private slots:
    void initForm();
    void initNav();
    void buttonClicked();

private slots:
    void on_btnReturn_pressed();
    void on_btnMsg_pressed();
};

#endif // INDEXFORM_H
