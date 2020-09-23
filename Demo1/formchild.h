#ifndef FORMCHILD_H
#define FORMCHILD_H

#include <QWidget>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>



namespace Ui {
class FormChild;
}

class FormChild : public QWidget
{
    Q_OBJECT

public:
    explicit FormChild(QWidget *parent = 0);
    ~FormChild();

signals:
    void changeRotate(int rotate);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormChild *ui;
    QGraphicsScene * scene;
    QGraphicsProxyWidget * w;
    //MyGraphicsProxyWidget * myView;
};

#endif // FORMCHILD_H
