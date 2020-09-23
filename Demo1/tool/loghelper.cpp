#include "loghelper.h"

LogHelper *LogHelper::self = 0;
LogHelper *LogHelper::Instance()
{
    if (!self) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!self) {
            self = new LogHelper;
        }
    }

    return self;
}
LogHelper::LogHelper(QObject *parent) : QObject(parent)
{

}
//保存日志
void LogHelper::LogInfo(QString HexString)
{

}
