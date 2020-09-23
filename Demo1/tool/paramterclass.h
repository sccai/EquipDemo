#ifndef PARAMTERCLASS_H
#define PARAMTERCLASS_H


#include <QObject>

class ParamterClass
{
public:
    ParamterClass();

public:

    QString modelType;
    bool isUseCardBorder=false;
    //打印模块是否启用
    bool isPrint1ModEnable=true;
    bool isPrint2ModEnable=false;
    bool isPrint3ModEnable=false;
    //打印机是否打印
    bool isUsePrint1=false;
    bool isUsePrint2=false;
    bool isUsePrint3=false;

    //是否覆膜
    bool isUseLam=false;

    //是否启用可擦写
    bool isUseEPrint=false;
    //打印前擦除
    bool isClearBeforePrint=false;
    //启用卡槽
    bool isOpenSolt1=false;
    bool isOpenSolt2=false;
    bool isOpenSolt3=false;
    bool isOpenSolt4=false;
};

#endif // PARAMTERCLASS_H
