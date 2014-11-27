#ifndef GAME_H
#define GAME_H

#include "gametype.h"
#include "profile.h"

class Game : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString level READ getLevelName NOTIFY levelChanged)

private:
    /** Current profile */
    Profile *m_currentProfile;
    /** Current type game */
    GameType *m_currentTypeGame;
    /** Current level game */
    Level *m_levelGame;

public:
    explicit Game(Profile* profileGame);
    ~Game();

    inline const QString getLevelName(){return m_levelGame->getName();}

private:
    void setTypeGame(GameType *typeGame);
    void setLevelGame(Level *levelGame);

signals:
    /** When the score changed */
    void scoreChanged();
    /** When the level changed */
    void levelChanged();

public slots:

    void initLevelGame(QString nameLevel);
    void launchGameType(QString nameTypeGame);
    void scoreIncrement(int nbPoints);
    void scoreDecrement(int nbPoints);

};

#endif // GAME_H
