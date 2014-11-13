#ifndef PARTIE_H
#define PARTIE_H

#include "typedejeu.h"
#include "profil.h"

class Partie : public QObject
{
    Q_OBJECT

private:
    Profil *profilActif;
    TypeDeJeu *typeJeuActif;
    Niveau *niveauDeLaPartie;

public:
    explicit Partie();
    ~Partie();

    void setProfilPartie(Profil *profilJeu);

    const Profil* getProfilActif()const;
    const Niveau* getNiveauDeLaPartie()const;

private:
    void setTypeJeu(TypeDeJeu *typeJeu);
    void setNiveauDeLaPartie(Niveau *niveauPartie);

signals:

public slots:
    void lancerJeu();

};

#endif // PARTIE_H
