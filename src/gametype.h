#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <QObject>
#include "level.h"

class GameType : public QObject
{
    Q_OBJECT

    /** Name level selected */
    Q_PROPERTY(QString level READ getLevelName NOTIFY levelChanged)
    /** Number of propositions for level */
    Q_PROPERTY(int numberPropositions READ getNumberPropositions NOTIFY numberPropositionsChanged)
    /** List of index level selectable */
    Q_PROPERTY(QList<int> levelsSelectable READ getLevelsSelectable NOTIFY levelsSelectableChanged)

public:
    explicit GameType();
    virtual ~GameType();

    inline const QString getLevelName(){return m_levelGame->getName();}
    const Level& getLevel();
    int getNumberPropositions()const;
    inline QList<int>& getLevelsSelectable(){return m_listLevelSelectable;}
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
    /** Number propositions also level */
    int m_numberPropositions;
    /** List level selectable */
    QList<int> m_listLevelSelectable;

private:
    void setLevelGame(Level *levelGame);
    virtual void setNumberPropositions(int indexLevel) = 0;
    virtual void setLevelsSelectable() = 0;

signals:
    /** signal for increment score of player */
    void incrementScore(int);
    /** signal for decrement score of player */
    void decrementScore(int);
    /** When the level changed */
    void levelChanged();
    /** When number propositions changed */
    void numberPropositionsChanged();
    /** When the list selectable level changed */
    void levelsSelectableChanged();

public slots:
    virtual void launchGame() = 0;
    void initLevelsSelectable();
    void initLevelGame(int indexLevel);

};

#endif // GAMETYPE_H
