#ifndef BOSS_H
#define BOSS_H

#include <QImage>
#include <QPixmap>

class Boss
{

    QPixmap arceus;

public:
    Boss();
    ~Boss();

    QPixmap getBoss(QString name);
    QString setBossMove(QString name);
};

#endif // BOSS_H
