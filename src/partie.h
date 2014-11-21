#ifndef PARTIE_H
#define PARTIE_H

#include "typedejeu.h"
#include "profil.h"

class Partie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString niveau READ getNameNiveau NOTIFY niveauChanged)
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)

private:
    Profil *profilActif;
    TypeDeJeu *typeJeuActif;
    Niveau *niveauDeLaPartie;

public:
    explicit Partie(Profil* profilJeu);
    ~Partie();


    inline const QString getNameNiveau(){return niveauDeLaPartie->getName();}
    inline int getScore(){return profilActif->getScore();}

    void setProfilPartie(Profil *profilJeu);

private:
    void setTypeJeu(TypeDeJeu *typeJeu);
    void setNiveauDeLaPartie(Niveau *niveauPartie);
    void saveProfil();

signals:
    void niveauChanged();
    void scoreChanged();

public slots:
    void lancerJeu();
    void initTypeJeu(QString nameTypeJeu);
    void scoreIncrement(int nbPoints);

};

#endif // PARTIE_H
