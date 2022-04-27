#ifndef SPRITE_H
#define SPRITE_H

#include <QPixmap>
#include <QGraphicsItem>

class Sprite: public QGraphicsPixmapItem
{
    int up_index, down_index, left_index, right_index;
    QPixmap *up_sprites, *down_sprites, *left_sprites, *right_sprites;

public:
    Sprite(QPixmap map, int width, int height);
    ~Sprite();

    QPixmap getSprite(QPixmap *sprites, int &index);
    void updateSpriteIndex(int &index);

    QPixmap* getUpSprite();
    int& getUpSpriteIndex();
    void setUpSpriteIndex(int index);
    QPixmap* getDownSprite();
    int& getDownSpriteIndex();
    void setDownSpriteIndex(int index);
    QPixmap* getLeftSprite();
    int& getLeftSpriteIndex();
    void setLeftSpriteIndex(int index);
    QPixmap* getRightSprite();
    int& getRightSpriteIndex();
    void setRightSpriteIndex(int index);
};

#endif // SPRITE_H
