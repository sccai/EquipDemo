#include "appinit.h"
#include "qmutex.h"
#include "qapplication.h"
#include "qevent.h"
#include "qwidget.h"

AppInit *AppInit::self = 0;
AppInit *AppInit::Instance()
{
    if (!self) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!self) {
            self = new AppInit;
        }
    }

    return self;
}

AppInit::AppInit(QObject *parent) : QObject(parent)
{
    domparser=new DomParser;
    domparser->readFile(deviceconfigpath,devicecleanpath);//"/home/dg/EquipDemo/deviceinfo.xml");//绝对路径，冒号：开头是资源路径

    //domparser->printAllMembers();
}
void AppInit::LoadParamterFile()
{
    //domparser->loadParamterFile(paramterpath);//"/home/dg/EquipDemo/deviceinfo.xml");//绝对路径，冒号：开头是资源路径
    //获取当前运行路径
    QString configpath=QCoreApplication::applicationDirPath()+"/ParamterConfig.xml";//"/home/aisino/project/EquipDemo/build-Demo1-unknown-u8c03u8bd5"
    domparser->LoadSettings(configpath);
    //domparser->LoadSettings(paramterpath);
}
void AppInit::SaveParamterFile(ParamterClass *para)
{
    //获取当前运行路径
    QString configpath=QCoreApplication::applicationDirPath()+"/ParamterConfig.xml";//"/home/aisino/project/EquipDemo/build-Demo1-unknown-u8c03u8bd5"
    domparser->SaveSettings(configpath,para);
    //domparser->SaveSettings(paramterpath,para);//不能用资源里的文件，不能保存
}
bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

void AppInit::start()
{
    qApp->installEventFilter(this);
}


