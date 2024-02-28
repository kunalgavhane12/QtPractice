#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QString>
#include <QDate>

class Music
{
public:

    const QString &album() const;
    void setAlbum(const QString &newAlbum);

    const QString &artist() const;
    void setArtist(const QString &newArtist);

    const QString &notes() const;
    void setNotes(const QString &newNotes);

    const QDate &release() const;
    void setRelease(const QDate &newRelease);

private:
    QString m_album;
    QString m_artist;
    QString m_notes;
    QDate m_release;

};

#endif // MUSIC_H
