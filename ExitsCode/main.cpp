#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("xed",QStringList() << "http://www.google.com");
    qInfo() << "Exit Code: " <<proc.exitCode();

    return a.exec();
}
