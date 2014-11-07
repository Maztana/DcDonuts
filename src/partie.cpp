#include "partie.h"

Partie::Partie(Profil *profilJeu):
    QObject(0)
{
    profilActif = profilJeu;
}

Partie::~Partie()
{
    delete(typeJeuActif);
    delete(niveauDeLaPartie);
}

void Partie::lancerJeu()
{
    if(typeJeuActif != 0 && niveauDeLaPartie != 0)
    {
        typeJeuActif->lancerJeu(niveauDeLaPartie);
    }
}

void Partie::setTypeJeu(TypeDeJeu *typeJeu)
{
    typeJeuActif = typeJeu;
}

void Partie::setNiveauDeLaPartie(Niveau *niveauPartie)
{
    niveauDeLaPartie = niveauPartie;
}
