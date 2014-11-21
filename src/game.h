#ifndef PARTIE_H
#define PARTIE_H

#include "typedejeu.h"
#include "profile.h"

class Game : public QObject
{
    Q_OBJECT

    /** Score of current profile */
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

private:
    /** Current profile */
    Profile *m_profilActif;
    /** Current type game */
    TypeDeJeu *m_currentTypeGame;
    /** Current level game */
    Niveau *m_levelGame;

public:
    explicit Game(Profile* profileGame);
    ~Game();

    inline int getScore(){return m_profilActif->getScore();}
    void setProfileGame(Profile *profileGame);

private:
    void setTypeGame(TypeDeJeu *typeGame);
    void setLevelGame(Niveau *levelGame);

signals:
    void levelChanged();
    void scoreChanged();

public slots:
    inline const QString getNameLevel(){return m_levelGame->getName();}
    void initLevelGame(QString nameLevel);
    void launchTypeGame(QString nameTypeGame);
    void scoreIncrement(int nbPoints);

};

#endif // PARTIE_H
