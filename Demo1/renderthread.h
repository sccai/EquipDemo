#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QObject>
#include <QThread>

class RenderThread : public QThread
{
        Q_OBJECT
signals:
        void notify(int,int id);
public:
        RenderThread();

        //启动线程
        void DoRun(int);
        void FinishRun();

protected:

        //线程处理函数
        void run();
        int index =0;
        bool isStart=false;
        int id;
};

#endif // RENDERTHREAD_H
