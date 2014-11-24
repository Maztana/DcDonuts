#ifndef GAME_H
#define GAME_H

#include "gametype.h"
#include "profile.h"

class Game : public QObject
{
    Q_OBJECT

    /** Score of current profile */
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

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

    inline int getScore(){return m_currentProfile->getScore();}
    //void setProfileGame(Profile *profileGame);

private:
    void setTypeGame(GameType *typeGame);
    void setLevelGame(Level *levelGame);

signals:
    void levelChanged();
    void scoreChanged();

public slots:
    inline const QString getLevelName(){return m_levelGame->getName();}
    void initLevelGame(QString nameLevel);
    void launchGameType(QString nameTypeGame);
    void scoreIncrement(int nbPoints);
    void scoreDecrement(int nbPoints);

};

#endif // GAME_H
