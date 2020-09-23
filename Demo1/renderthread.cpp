#include "renderthread.h"
#include "QtDebug"

RenderThread::RenderThread()
{

}

void RenderThread::DoRun(int _id)
{
    id =_id;
    isStart=true;
    start(HighestPriority);
}
void RenderThread::FinishRun()
{
    isStart=false;
    this->terminate();
    this->wait();
}

void RenderThread::run()
{
    index =0;
    while (isStart)
    {
        //qDebug()<<"RenderThread::run";
        if(index==3)
        {
            index=0;
        }
        emit notify(index,id); //触发信号
        index++;
        msleep(500);
    }
}
