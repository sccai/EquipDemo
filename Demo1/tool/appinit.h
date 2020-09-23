#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>
#include "tool/domparser.h"
class AppInit : public QObject
{
    Q_OBJECT
public:
    static AppInit *Instance();
    explicit AppInit(QObject *parent = 0);    
    DomParser *domparser;
    void start();

    void LoadParamterFile();
    void SaveParamterFile(ParamterClass *para);
protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static AppInit *self;
    //QString deviceconfigpath="/home/dg/EquipDemo/deviceinfo.xml";//绝对路径
    QString deviceconfigpath=":/Configurations/deviceinfo.xml";//添加到项目资源，相对路径

    QString devicecleanpath=":/Configurations/deviceclean.xml";//添加到项目资源，相对路径

    QString paramterpath=":/Configurations/ParamterConfig.xml";//添加到项目资源，相对路径

signals:

public slots:
};

#endif // APPINIT_H
