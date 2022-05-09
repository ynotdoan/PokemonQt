#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>

class MusicPlayer
{

    QMediaPlayer *music_player;

public:
    MusicPlayer();
    ~MusicPlayer();

    void setMusic(QUrl music);
};

#endif // MUSICPLAYER_H
