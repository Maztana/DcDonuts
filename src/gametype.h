#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <QObject>
#include "level.h"

class GameType : public QObject
{
    Q_OBJECT

public:
    explicit GameType(Level* gameLevel);
    virtual ~GameType();

    const Level& getLevel();
    /** If the game is a quiz
     * @brief isQuiz
     * @return True if is a quiz, else return false
     */
    virtual inline bool isQuiz()const{return false;}
    static GameType* makeGameType(Level* gameLevel, QString gameName);

protected:
    /** the value of incremental score*/
    static int s_incremental_score;
    /** the level of game */
    const Level *m_gameLevel;

private:
    static GameType* makeGameModeCalcul(Level* gameLevel, QString gameName);

signals:
    /** signal for increment score of player */
    void incrementScore(int);
    /** signal for decrement score of player */
    void decrementScore(int);

public slots:
    virtual void launchGame() = 0;

};

#endif // GAMETYPE_H
