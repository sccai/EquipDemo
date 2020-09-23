#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

#include "QDebug"
#include "QTime"
/*
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"*/

//通用类
class LogHelper : public QObject
{
    Q_OBJECT
public:
    static LogHelper *Instance();
    explicit LogHelper(QObject *parent = 0);
    void LogInfo(QString HexString);
signals:

public slots:

private:
    static LogHelper *self;    //对象自身
};


#endif // LOGHELPER_H
