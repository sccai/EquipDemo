#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include <string>
#include <ostream>
#include "QDebug"
#include <iostream>

namespace DeviceInfoModel
{

//<DeviceType>PrinterModule</DeviceType>
//<DeviceName>1号打印机构</DeviceName>
//<DisplayName>1号打印机构</DisplayName>
//<DeviceSN>1</DeviceSN>
//<DeviceID>151</DeviceID>
//<DeviceIP>192.168.150.151</DeviceIP>
//<IsOnline>true</IsOnline>
//<DevicePort>5000</DevicePort>
//<IsAllowSkip>false</IsAllowSkip>
struct DeviceInfo
{
    std::string DeviceType;
    std::string DeviceName;
    std::string DisplayName;
    std::string DeviceSN;
    std::string DeviceID;
    std::string DeviceIP;
    int DevicePort;

    DeviceInfo(std::string DeviceType_,std::string DeviceName_,std::string DeviceID_, int DevicePort_, std::string DeviceIP_)
        : DeviceType(std::move(DeviceType_)), DeviceName(std::move(DeviceName_)),DeviceID(std::move(DeviceID_)), DevicePort(DevicePort_), DeviceIP(std::move(DeviceIP_))
    {

    }
};
inline void print(std::ostream& out, const DeviceInfo& device)
{
    std::cout << "\tDeviceName: " + device.DeviceName << std::endl;
    std::cout << "\tDeviceType: " + device.DeviceType << std::endl;
    std::cout << "\tDeviceIP: "   + device.DeviceIP   << std::endl;
    std::cout << "\tDevicePort: " << device.DevicePort << std::endl;
}
}

#endif // DEVICEINFO_H
