#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <QGraphicsItem>
#include <QImage>

class Player
{
    const int s = 4; // Number of animated sprite indices for each direction.
    QPixmap *u_sprites, *d_sprites, *l_sprites, *r_sprites;
    int u_index, d_index, l_index, r_index;
    QImage p_image;
    int width, height;

public:
    Player();
    ~Player();

    QPixmap getSprite(QPixmap *sprites, int &index);
    void updateSprite(int &index);
    QPixmap* getUSprite();
    int& getUSpriteIndex();
    void setUSpriteIndex(int index);
    QPixmap* getDSprite();
    int& getDSpriteIndex();
    void setDSpriteIndex(int index);
    QPixmap* getLSprite();
    int& getLSpriteIndex();
    void setLSpriteIndex(int index);
    QPixmap* getRSprite();
    int& getRSpriteIndex();
    void setRSpriteIndex(int index);
};

#endif // PLAYER_H
