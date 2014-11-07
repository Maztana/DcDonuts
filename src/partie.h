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
    explicit Partie(Profil *profil);
    ~Partie();


private:
    void setTypeJeu(TypeDeJeu *typeJeu);
    void setNiveauDeLaPartie(Niveau *niveauPartie);

signals:

public slots:
    void lancerJeu();

};

#endif // PARTIE_H
