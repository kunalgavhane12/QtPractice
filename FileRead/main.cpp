#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QFile file_DB("D:/qt practice program/QtPractice/FileRead/user_credential.txt");


    if(file_DB.open(QIODevice::ReadOnly |QIODevice::WriteOnly | QIODevice::Text))
    {
        file_DB.setPermissions(QFile::ReadOwner | QFile::WriteOwner);


        QTextStream in(&file_DB);

        QString line = in.readLine();
        qDebug() << line;

        QTextStream out(&file_DB);
        out << "line writeing";

        file_DB.close();
    }
    else
    {
        qDebug() << "File not open";
    }


return a.exec();

}
