#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>

class MusicPlayer
{

    QMediaPlayer *music_player;
    QAudioOutput *audio_out = new QAudioOutput;


public:
    MusicPlayer();
    ~MusicPlayer();

    void setMusic(QUrl music);
};

#endif // MUSICPLAYER_H
