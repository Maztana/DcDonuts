#ifndef PARTIE_H
#define PARTIE_H

#include "typedejeu.h"
#include "profil.h"

class Partie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString niveau READ getNameNiveau NOTIFY niveauChanged)

private:
    Profil *profilActif;
    TypeDeJeu *typeJeuActif;
    Niveau *niveauDeLaPartie;

public:
    explicit Partie(Profil* profilJeu);
    ~Partie();


    inline const QString getNameNiveau(){return niveauDeLaPartie->getName();}

    void setProfilPartie(Profil *profilJeu);

    //inline const Profil* getProfilActif()const{return profilActif;}
    //inline const TypeDeJeu* getTypeJeu()const{return typeJeuActif;}
    //inline const Niveau* getNiveauDeLaPartie()const{return niveauDeLaPartie;}

private:
    void setTypeJeu(TypeDeJeu *typeJeu);
    void setNiveauDeLaPartie(Niveau *niveauPartie);

signals:
    void niveauChanged();

public slots:
    void lancerJeu();

};

#endif // PARTIE_H
