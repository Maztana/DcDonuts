#ifndef GAMETYPEFACTORY_H
#define GAMETYPEFACTORY_H

#include <QObject>

#include "gametype.h"

class GameTypeFactory : public QObject
{
    Q_OBJECT
public:
    explicit GameTypeFactory(QObject *parent = 0);

    static GameType* makeGameType(QList<int> identifiantGameType);
    //static GameType* makeSpecificGameType();

signals:

public slots:

};

#endif // GAMETYPEFACTORY_H
