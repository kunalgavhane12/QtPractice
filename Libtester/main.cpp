#include <QCoreApplication>
#include "mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib clib;
    clib.Test();

    return a.exec();
}
