#include "commhelper.h"
#include "QDebug"


CommHelper *CommHelper::self = 0;
CommHelper *CommHelper::Instance()
{
    if (!self) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!self) {
            self = new CommHelper;
        }
    }
    return self;
}
CommHelper::CommHelper(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_LINUX
    // linux
    //logpath="/home/dg/EquipDemo/log.txt";
    logpath="log.txt";
#endif

#ifdef Q_OS_WIN32
    // win
    QFile file(":/log.txt");
#endif
}
//延迟...毫秒
void CommHelper::sleepme(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

//QByteArray和十六进制的QString（char*）相互转换
QByteArray CommHelper::HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty()) {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }else{
                qDebug()<<"非法的16进制字符："<<s;
            }
        }
    }
    return ret;
}

//QByteArray和十六进制的QString（char*）相互转换
QString CommHelper::ByteArrayToHexString(QByteArray &ba)
{
    QDataStream out(&ba,QIODevice::ReadWrite);
    //将str的数据 读到out里面去
    QString buf;
    while(!out.atEnd())
    {
        qint8 outChar = 0;
        out >> outChar;//每次一个字节的填充到 outchar
        QString str=QString("%1").
                arg(outChar&0xFF,2,16,QLatin1Char('0')).
                toUpper() + QString(" ");

        buf += str;
    }
    return buf;
}

//十六进制的QString（char*）相互转换－>QByteArray
QStringList CommHelper::HexStringToBytes(QString HexString)
{
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    if(HexString.length()%2!=0)
    {
        HexString = HexString+" ";
    }

    //ShowLog("解析传感器参数 = "+HexString);
    bool ok;
    QStringList strList;

    int len=HexString.length()/2;

    for (int hex=0;hex<=len;hex++)
    {
        QString s = HexString.mid(hex*2,2);
        if(!s.isEmpty())
        {
            //char c = s.toInt(&ok,16)&0xFF;
            int c = s.toInt(&ok,16);
            if(ok){
                //qDebug()<<"c = "<<c;
                strList <<QString::number(c);
                //ret[hex]=c;
            }else{
                qDebug()<<"非法的16进制字符："<<s;
            }
        }
    }
    return strList;
}

//获取传感器状态值
QStringList CommHelper::GetStatusBackData(QStringList &ba)
{
    QStringList strList;
    bool ok;
    int datalen = ba.at(3).toInt(&ok)+4;

    for (int hex=4;hex<datalen;hex++)
    {
        QString cmd= ba.at(hex);
        QString binary= QString::number(cmd.toInt(),2);
        QString strNew = QString("%1").arg(binary.toInt(), 8, 10, QLatin1Char('0'));
        strList<<strNew;
    }

    ShowLog("传感器状态值 = "+strList.join(","));
    return strList;
}

//格式化输出当前时刻
//qDebug()<<"currentTime:"<<QTime::currentTime().toString("hh:mm:ss:zzz");
void CommHelper::Showtime()
{
    qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
}
//保存日志信息
void CommHelper::ShowLog(QString HexString)
{
    if(IsShowDebug)
    {
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")<<" : "<<HexString;
    }
    QFile file(logpath);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << HexString << endl;
    file.flush();
    file.close();
}
//是否输出调试信息，默认：false
void CommHelper::SetDebug(bool value)
{
    IsShowDebug=value;
}

///////////////////////////
//另一个 函数 char 转为 16进制
char convertCharToHex(char ch)
{
    /*
    0x30等于十进制的48，48也是0的ASCII值，，
    1-9的ASCII值是49-57，，所以某一个值－0x30，，
    就是将字符0-9转换为0-9
    */
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

//将单个字符串转换为hex
//0-F -> 0-15
char CommHelper::ConvertHexChar(char c)
{
    if((c >= '0') && (c <= '9'))
        return c - 0x30;
    else if((c >= 'A') && (c <= 'F'))
        return c - 'A' + 10;//'A' = 65;
    else if((c >= 'a') && (c <= 'f'))
        return c - 'a' + 10;
    else
        return -1;
}

//发卡器版本号解析
QString CommHelper::GetStrData(QByteArray binaryData)
{
    QString str = "";
    for (int i = 9; i < binaryData[2] + 3; i++)//第9字节到最后一个数据字节
    {
        str += int(binaryData[i]);//或者binaryData.at(i)
    }
    return str;
}

//字符串转Hex(QByteArray)类型
QByteArray CommHelper::QString2Hex(QString hexStr)
{
    QByteArray senddata;
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = hexStr.length();
    senddata.resize(len/2);
    char lstr, hstr;
    for(int i = 0; i < len; )
    {
        //将第一个不为' '的字符赋给hstr;
        hstr = hexStr[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        //当i >= len时，跳出循环
        if(i >= len)
            break;
        //当i < len时，将下一个字符赋值给lstr;
        lstr = hexStr[i].toLatin1();
        //将hstr和lstr转换为0-15的对应数值
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        //
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata * 16 + lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

//ByteArray转换为16进制字符串
QString CommHelper::ByteArrayToHexStringCard(QByteArray data){
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
    for(int i=1;i<len;i++)
    {
        ret.insert(2*i+i-1," ");
    }

    return ret;
}

quint16 UpdateCRC16(quint16 crcIn,unsigned char bytee)
{
    quint32 crc = crcIn;
    quint32 ins = (quint32)bytee | 0x100;

    do
    {
        crc <<= 1;
        ins <<= 1;
        if ((ins & 0x100) == 0x100)
        {
            ++crc;
        }
        if ((crc & 0x10000) == 0x10000)
        {
            crc ^= 0x1021;
        }
    }
    while (!((ins & 0x10000) == 0x10000));
    return (quint16)crc;
}

quint16 CommHelper::Cal_crc16(char *data, int size)
{
    int i = 0;
    quint16 crc = 0;
    for (i = 0; i < size; i++)
    {
        crc = UpdateCRC16(crc, data[i]);
    }
    crc = UpdateCRC16(crc, 0);
    crc = UpdateCRC16(crc, 0);
    return (quint16)(crc);
}
///////////////////////////

bool CommHelper::CheckCode()
{


    return true;
}
