#include <QMediaPlayer>

#include "Headers/musicplayer.h"

// Music does not loop, so after a song finishes playing, the game goes to silience :(

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
    // Stops playing current music.
    this->music_player->stop();
    // Updates the music in mediaplayer with new music passed in.
    this->music_player->setMedia(music);
    // Play new music.
    this->music_player->play();
}
