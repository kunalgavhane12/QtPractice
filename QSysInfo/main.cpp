#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Info";
    qInfo() << "Boot Id: " <<sys.bootUniqueId();
    qInfo() << "Build: " <<sys.buildAbi();
    qInfo() << "Cpu: " <<sys.buildCpuArchitecture();
    qInfo() << "Kernal: " <<sys.kernelType();
    qInfo() << "Version: " <<sys.kernelVersion();
    qInfo() << "MAC: " <<sys.macVersion();
    qInfo() << "Windows: " <<sys.windowsVersion();
    qInfo() << "Host: " <<sys.machineHostName();
    qInfo() << "Product: " <<sys.prettyProductName();
    qInfo() << "Product Type: " <<sys.productType();
    qInfo() << "Version: " <<sys.productVersion();


#ifndef W_OS_Linux
    qInfo() << "Linux Code here";
#elif defined (W_OS_WIN32)
    qInfo() << "Windows Code here";
#elif defined (W_OS_MACX)
    qInfo() << "MAC Code here";
#else
    qInfo() << "Unknown OS Code here";

#endif

    return a.exec();
}
