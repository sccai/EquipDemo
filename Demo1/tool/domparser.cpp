#include "domparser.h"
#include <QDomDocument>
#include <QFile>
#include <iostream>
#include "QDebug"
DomParser::DomParser()
{

}

bool DomParser::readFile(const QString &fileName,const QString &fcleanfileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        std::cerr << "Error: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr) << std::endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "ArrayOfDeviceInfoModel")
    {
        std::cerr << "Error: Not a ArrayOfDeviceInfoModel" << std::endl;
        return false;
    }

    parseEquipMembers(root);
    return true;
}

void DomParser::parseEquipMembers(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "DeviceInfoModel")
        {
            auto children = child.childNodes();
            auto firstChild = children.at(0).toElement();
            auto secondChild = children.at(1).toElement();
            auto thirdChild = children.at(3).toElement();
            auto fiveChild = children.at(5).toElement();
            auto sixChild = children.at(6).toElement();

            int port = sixChild.text().toInt();
            //            QString devicetype = firstChild.text();
            //            QString devicename= secondChild.text();
            //            QString displayname = thirdChild.text();
            //            QString ip = fiveChild.text();

            m_deviceinfolist.emplace_back(firstChild.text().toStdString(),secondChild.text().toStdString(),thirdChild.text().toStdString(),
                                          port, fiveChild.text().toStdString());

            //parseTeacherMembers(child.toElement());
        }
        child = child.nextSibling();
    }
}

void DomParser::parseTeacherMembers(const QDomElement &element)
{
    //    QDomNode child = element.firstChild();
    //    while (!child.isNull())
    //    {
    //        if (child.toElement().tagName() == "entry")
    //        {
    //            parseTeacher(child.toElement());
    //        }
    //        child = child.nextSibling();
    //    }
}

void DomParser::parseTeacher(const QDomElement &element)
{
    //    auto children = element.childNodes();
    //    auto firstChild = children.at(0).toElement();
    //    auto secondChild = children.at(1).toElement();
    //    int age = firstChild.text().toInt();

    //    m_teachers.emplace_back(element.attribute("name").toStdString(),
    //                age, secondChild.text().toStdString());
}


//参数设置
bool DomParser::loadParamterFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        std::cerr << "Error: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr) << std::endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "ParamterInfoModel")
    {
        std::cerr << "Error: Not a ParamterInfoModel" << std::endl;
        return false;
    }
    para=new ParamterClass();
    parseParamterMembers(root);
    return true;
}
//不使用
void DomParser::parseParamterMembers(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "Print1Using")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isUsePrint1=finalValue;
        }
        else if (child.toElement().tagName() == "Print2Using")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isUsePrint2=finalValue;
        }
        else if (child.toElement().tagName() == "Print3Using")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isUsePrint3=finalValue;
        }
        else if (child.toElement().tagName() == "PrintModel1")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isPrint1ModEnable=finalValue;
        }
        else if (child.toElement().tagName() == "PrintModel2")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isPrint2ModEnable=finalValue;
        }
        else if (child.toElement().tagName() == "PrintModel3")
        {
            auto children = child.toElement();
            QString value = children.text();
            QVariant tempValue = value;
            bool finalValue = tempValue.toBool();
            para->isPrint3ModEnable=finalValue;
        }
        child = child.nextSibling();
    }
}

//更新单个节点
bool DomParser::WriteValue(QString key,QString v)
{
    if (paramap.count(key) == 0)
    {
        qDebug() << "no this key" << endl;
        paramap[key]=v;
    }
    else
    {
        paramap[key]=v;
    }
}

//读取单个节点
QString DomParser::ReadValue(QString key)
{
    if (paramap.count(key) == 0)
    {
        qDebug() << "no this key" << endl;
        return "";
    }
    else
    {
        return paramap[key];
    }
}


//bool 转 QString
QString bool2QString(bool v)
{
    if(v==true)
    {
        return "true";
    }
    else
    {
        return "false";
    }
    //QString res = QString::number(v);
    //return res;
}

//QString 转 bool，defaultvalue:默认值
bool QString2bool(QString v,bool defaultvalue)
{
    if(v.isEmpty())
    {
        return defaultvalue;
    }
    try {
        QVariant tempValue = v;
        bool res = tempValue.toBool();
        return res;
    }
    catch (...) {
        return defaultvalue;
    }
}

//加载
bool DomParser::LoadSettings(const QString &fileName)
{
    try {
        //打开文件
        QFile file(fileName); //相对路径、绝对路径、资源路径都可以
        if(!file.open(QFile::ReadOnly))
            return false;

        //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
        //或者用遍历的方法去匹配tagname或者attribut，value来更新
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return false;
        }
        file.close();

        QDomElement root = doc.documentElement();
        if (root.tagName() != "ParamterInfoModel")
        {
            std::cerr << "Error: Not a ParamterInfoModel" << std::endl;
            return false;
        }

        QDomNodeList list=root.elementsByTagName("Settings");
        if(list.size()>0)
        {
            for (int i=0;i<list.size();i++)
            {
                QDomNode nodeTitle=list.at(i).firstChild(); //定位到第一个子节点的子元素
                QDomNode nodeValue=list.at(i).lastChild(); //定位到第一个子节点的子元素
                QString key= nodeTitle.toElement().text();//Key值
                QString value= nodeValue.toElement().text();//Key值
                paramap[key]=value;
            }
        }
        para=new ParamterClass();
        para->isUsePrint1= QString2bool(ReadValue(Print1_IsUsingKey),false);
        para->isUsePrint2= QString2bool(ReadValue(Print2_IsUsingKey),false);
        para->isUsePrint3= QString2bool(ReadValue(Print3_IsUsingKey),false);
        para->isPrint1ModEnable= QString2bool(ReadValue(PrintMod1_IsUsingKey),false);
        para->isPrint2ModEnable= QString2bool(ReadValue(PrintMod2_IsUsingKey),false);
        para->isPrint3ModEnable= QString2bool(ReadValue(PrintMod3_IsUsingKey),false);
        //OCR
        para->isUseCardBorder=QString2bool(ReadValue(CardBorder_IsUsingKey),false);
        //覆膜
        para->isUseLam= QString2bool(ReadValue(Lam_IsUsingKey),false);
        //可擦写
        para->isUseEPrint= QString2bool(ReadValue(EPrint_IsUsingKey),false);
        para->isClearBeforePrint= QString2bool(ReadValue(EPrint_IsClearBeforeKey),false);
        //卡槽
        para->isOpenSolt1=QString2bool(ReadValue(OpenSlot1_IsUsingKey),false);
        para->isOpenSolt2=QString2bool(ReadValue(OpenSlot2_IsUsingKey),false);
        para->isOpenSolt3=QString2bool(ReadValue(OpenSlot3_IsUsingKey),false);
        para->isOpenSolt4=QString2bool(ReadValue(OpenSlot4_IsUsingKey),false);
    }
    catch (...) {
        qDebug() << "LoadSettings Exception" << endl;
        return false;
    }
}

//保存xml内容
void DomParser::SaveSettings(const QString &fileName,ParamterClass *para)
{
    WriteValue(CardBorder_IsUsingKey,bool2QString(para->isUseCardBorder));
    //打印参数
    WriteValue(Print1_IsUsingKey,bool2QString(para->isUsePrint1));
    WriteValue(Print2_IsUsingKey,bool2QString(para->isUsePrint2));
    WriteValue(Print3_IsUsingKey,bool2QString(para->isUsePrint3));
    //打印模块
    WriteValue(PrintMod1_IsUsingKey,bool2QString(para->isPrint1ModEnable));
    WriteValue(PrintMod2_IsUsingKey,bool2QString(para->isPrint2ModEnable));
    WriteValue(PrintMod3_IsUsingKey,bool2QString(para->isPrint3ModEnable));

    //覆膜模块
    WriteValue(Lam_IsUsingKey,bool2QString(para->isUseLam));
    //可擦写模块
    WriteValue(EPrint_IsUsingKey,bool2QString(para->isUseEPrint));
    WriteValue(EPrint_IsClearBeforeKey,bool2QString(para->isClearBeforePrint));
    //
    WriteValue(OpenSlot1_IsUsingKey,bool2QString(para->isOpenSolt1));
    WriteValue(OpenSlot2_IsUsingKey,bool2QString(para->isOpenSolt2));
    WriteValue(OpenSlot3_IsUsingKey,bool2QString(para->isOpenSolt3));
    WriteValue(OpenSlot4_IsUsingKey,bool2QString(para->isOpenSolt4));
    //打开文件
    QFile file(fileName); //相对路径、绝对路径、资源路径都可以
    if(!file.open(QFile::ReadOnly))
        return;

    //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
    //或者用遍历的方法去匹配tagname或者attribut，value来更新
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement();
    QDomNodeList list=root.elementsByTagName("Settings");
    //root.appendChild()
    if(list.size()>0)
    {
        for (auto n : paramap)
        {
            QString title=n.first;
            QString value=n.second;
            for (int i=0;i<list.size();i++)
            {
                QDomNode nodeTitle=list.at(i).firstChild(); //定位到第一个子节点的子元素
                QDomNode nodeValue=list.at(i).lastChild(); //定位到第一个子节点的子元素
                QString key= nodeTitle.toElement().text();//Key值
                if(key==title)
                {
                    QDomNode oldnode=nodeValue.lastChild(); //标签之间的内容作为节点的子节点出现,当前是Pride and Projudice
                    nodeValue.firstChild().setNodeValue(value);
                    QDomNode newnode=nodeValue.lastChild();
                    nodeValue.replaceChild(newnode,oldnode);
                    break;
                }
            }
        }
    }
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();
}
