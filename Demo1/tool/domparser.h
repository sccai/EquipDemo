#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QString>
#include <QDomElement>
#include "deviceinfo.h"
#include "tool/paramterclass.h"
class DomParser
{
public:
    DomParser();

    bool readFile(const QString &fileName,const QString &cleanfileName);
    bool loadParamterFile(const QString &fileName);
    void printAllMembers();
    //设备参数集合
    std::vector<DeviceInfoModel::DeviceInfo> m_deviceinfolist;

    //clean设备集合
    std::vector<DeviceInfoModel::DeviceInfo> m_cleandeviceinfolist;
    ParamterClass *para;
    std::map<QString,QString> paramap;//参数字典
    bool WriteValue(QString key,QString v);
    QString ReadValue(QString key);
    bool LoadSettings(const QString &fileName);
    void SaveSettings(const QString &fileName,ParamterClass *para);
private:
    void parseEquipMembers(const QDomElement &element);
    void parseTeacherMembers(const QDomElement &element);
    void parseTeacher(const QDomElement &element);
    void parseParamterMembers(const QDomElement &element);
    void writeParamterMembers(const QDomElement &element,ParamterClass *para);

    //是否打印
    QString Print1_IsUsingKey = "Print1Using";
    QString Print2_IsUsingKey = "Print2Using";
    QString Print3_IsUsingKey = "Print3Using";

    //是否启用打印模块
    QString PrintMod1_IsUsingKey = "PrintModel1";
    QString PrintMod2_IsUsingKey = "PrintModel2";
    QString PrintMod3_IsUsingKey = "PrintModel3";
    QString CardBorder_IsUsingKey = "CardBorder_IsUsing";
    //覆膜模块
    QString Lam_IsUsingKey = "Lam_IsUsing";
    //可擦写模块
    QString EPrint_IsUsingKey = "EPrint_IsUsing";
    QString EPrint_IsClearBeforeKey = "EPrint_IsClearBefore";

    QString OpenSlot1_IsUsingKey="OpenSlot1_IsUsing";
    QString OpenSlot2_IsUsingKey="OpenSlot2_IsUsing";
    QString OpenSlot3_IsUsingKey="OpenSlot3_IsUsing";
    QString OpenSlot4_IsUsingKey="OpenSlot4_IsUsing";
};

#endif // DOMPARSER_H
