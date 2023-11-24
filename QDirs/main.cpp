#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QDir mDir("D:/qt practice program/QDirs");
//    qDebug() << mDir.exists();
    QDir mDir;
//    foreach(QFileInfo mItm, mDir.drives())
//    {
//        qDebug () << mItm.absoluteFilePath();
//    }
//    QString mPath = "D:/qt practice program/QDirs/kunal";
//    if(!mDir.exists(mPath))
//    {
//        mDir.mkpath(mPath);
//        qDebug() << "Created";
//    }
//    else
//    {
//        qDebug () << "Already exists";
//    }
       foreach(QFileInfo mitm, mDir.entryInfoList())
       {
           if(mitm.isDir()) qDebug() <<"Dir:" << mitm.absoluteFilePath();
           if(mitm.isDir()) qDebug() <<"Files:" << mitm.absoluteFilePath();
       }
    return a.exec();
}
