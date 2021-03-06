#ifndef GAME_H
#define GAME_H

#include "gametype.h"
#include "profile.h"

class Game : public QObject
{
    Q_OBJECT

private:
    /** Current profile */
    static Profile *m_currentProfile;
    /** Current game type */
    GameType *m_currentGameType;

public:
    explicit Game(Profile* profileGame);
    ~Game();
    static int getIdCurrentProfile();

private:
    void setTypeGame(GameType *typeGame);

signals:
    /** When game type is modified */
    void gameTypeChanged();

public slots:
    void initGameType(QList<int> identifiantsGameType);
};

#endif // GAME_H
