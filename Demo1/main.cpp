#include "mainwindow.h"
#include <QApplication>
#include "qdesktopwidget.h"
#include "formchild.h"
#include "tool/appinit.h"
#include "indexform.h"
#include "roundprogressbartest.h"
#include "cleanform.h"
#include "selfcheckform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppInit::Instance()->start();
    //样式
    QFile styleFile(QStringLiteral(":/css/blue.css"));
    if(styleFile.open(QFile::ReadOnly)){
        QString qss = styleFile.readAll();
        a.setStyleSheet(qss);
        //a.setPalette(QPalette(QColor("#f0f0f0")));
        styleFile.close();
    }else{
        qDebug()<<"styleFile Loading error";
    }

    IndexForm frm;
    frm.show();
    //窗口屏幕居中
    QDesktopWidget *desktop = QApplication::desktop();
    frm.move((desktop->width() - frm.width())/ 2, (desktop->height() - frm.height()) /2);

    //MainWindow w;
    //w.show();

    //CleanForm c;
    //c.show();

    //    RoundProgressBarTest rfrm;
    //    rfrm.show();

    //    SelfCheckForm sfrm;
    //    sfrm.show();
    return a.exec();
}
