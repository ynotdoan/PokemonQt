#include <QMediaPlayer>
#include <QAudioOutput>
#include "Headers/musicplayer.h"

// Music does not loop, so after a song finishes playing, the game goes to silience :(

MusicPlayer::MusicPlayer()
{
    this->music_player = new QMediaPlayer;
//    this->music_player->setVolume(5);
    this->audio_out = new QAudioOutput;
    this->music_player->setAudioOutput(this->audio_out);
}

MusicPlayer::~MusicPlayer()
{
    delete this->music_player; delete this->audio_out;
}

void MusicPlayer::setMusic(QUrl music)
{
    // Stops playing current music.
//    this->music_player->pause();
    // Updates the music in mediaplayer with new music passed in.
//    this->music_player->setMedia(music);
    this->music_player->setSource(music);
    // Play new music.
    this->audio_out->setVolume(50);
    this->music_player->play();
}
