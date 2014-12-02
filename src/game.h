#ifndef GAME_H
#define GAME_H

#include "gametype.h"
#include "profile.h"

class Game : public QObject
{
    Q_OBJECT

private:
    /** Current profile */
    Profile *m_currentProfile;
    /** Current type game */
    GameType *m_currentGameType;

public:
    explicit Game(Profile* profileGame);
    ~Game();

private:
    void setTypeGame(GameType *typeGame);

signals:

public slots:
    void launchGameType(QList<int> identifiantsGameType);
};

#endif // GAME_H
