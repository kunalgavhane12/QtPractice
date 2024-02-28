#include "watcher.h"

watcher::watcher(QObject *parent) : QObject(parent)
{
    fsw.addPath(QDir::currentPath());
    fsw.addPath(QDir::currentPath() + QDir::separator() + "test.txt");

    connect(&fsw, &QFileSystemWatcher::fileChanged, this, &watcher::fileChanged);
    connect(&fsw, &QFileSystemWatcher::directoryChanged, this, &watcher::directoryChanged);

}

void watcher::directoryChanged(const QString &path)
{
    qInfo() << "Directory Changed: " << path;
    if(fsw.directories().length())
    {
        qInfo() << "Dir that have changed:";

        foreach(QString dir, fsw.directories()){
            qInfo() << dir;
        }
    }

}

void watcher::fileChanged(const QString &path)
{
    qInfo() << "File Changed: " << path;
    if(fsw.files().length())
    {
        qInfo() << "File that have changed:";

        foreach(QString file, fsw.files()){
            qInfo() << file;
        }
    }
}
