#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <QObject>
#include "level.h"

class GameType : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString level READ getLevelName NOTIFY levelChanged)

public:
    explicit GameType();
    virtual ~GameType();

    inline const QString getLevelName(){return m_levelGame->getName();}
    const Level& getLevel();
    /** If the game is a quiz
     * @brief isQuiz
     * @return True if is a quiz, else return false
     */
    virtual inline bool isQuiz()const{return false;}

protected:
    /** the value of incremental score*/
    static int s_incremental_score;
    /** Current level game */
    Level *m_levelGame;

private:
    void setLevelGame(Level *levelGame);

signals:
    /** signal for increment score of player */
    void incrementScore(int);
    /** signal for decrement score of player */
    void decrementScore(int);
    /** When the level changed */
    void levelChanged();

public slots:
    virtual void launchGame() = 0;
    void initLevelGame(QString nameLevel);

};

#endif // GAMETYPE_H
