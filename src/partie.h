#ifndef PARTIE_H
#define PARTIE_H

#include "typedejeu.h"
#include "profil.h"

class Game : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

private:
    Profil *profilActif;
    TypeDeJeu *typeJeuActif;
    Niveau *niveauDeLaPartie;

public:
    explicit Game(Profil* profilJeu);
    ~Game();

    inline int getScore(){return profilActif->getScore();}
    void setProfilPartie(Profil *profilJeu);

private:
    void setTypeJeu(TypeDeJeu *typeJeu);
    void setNiveauDeLaPartie(Niveau *niveauPartie);

signals:
    void niveauChanged();
    void scoreChanged();

public slots:
    inline const QString getNameNiveau(){return niveauDeLaPartie->getName();}
    void initNiveauPartie(QString nameNiveau);
    void launchTypeJeu(QString nameTypeJeu);
    void scoreIncrement(int nbPoints);

};

#endif // PARTIE_H
