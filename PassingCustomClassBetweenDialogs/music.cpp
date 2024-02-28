#include "music.h"

const QString &Music::album() const
{
    return m_album;
}

void Music::setAlbum(const QString &newAlbum)
{
    m_album = newAlbum;
}

const QString &Music::artist() const
{
    return m_artist;
}

void Music::setArtist(const QString &newArtist)
{
    m_artist = newArtist;
}

const QString &Music::notes() const
{
    return m_notes;
}

void Music::setNotes(const QString &newNotes)
{
    m_notes = newNotes;
}

const QDate &Music::release() const
{
    return m_release;
}

void Music::setRelease(const QDate &newRelease)
{
    m_release = newRelease;
}
