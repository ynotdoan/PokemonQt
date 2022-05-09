#include <QMediaPlayer>

#include "Headers/musicplayer.h"

MusicPlayer::MusicPlayer()
{
    this->music_player = new QMediaPlayer();
    this->music_player->setVolume(100);
}

MusicPlayer::~MusicPlayer()
{
    delete this->music_player;
}

void MusicPlayer::setMusic(QUrl music)
{
    this->music_player->stop();
    this->music_player->setMedia(music);
    this->music_player->play();
}
