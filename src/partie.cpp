#include "partie.h"

Partie::Partie(Profil *profilJeu):
    QObject(0)
{
    profilActif = profilJeu;
}

void Partie::lancerJeu()
{
    typeJeuActif->lancerJeu(niveauDeLaPartie);
}
