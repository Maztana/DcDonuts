#include "partie.h"

Partie::Partie():
    QObject(0)
{
    // Implémentation incorecte du niveau
    setNiveauDeLaPartie(new Niveau());
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

void Partie::setProfilPartie(Profil *profilJeu)
{
    profilActif = profilJeu;
}

const Profil* Partie::getProfilActif()const
{
    return profilActif;
}

const Niveau* Partie::getNiveauDeLaPartie()const
{
    return niveauDeLaPartie;
}

void Partie::setTypeJeu(TypeDeJeu *typeJeu)
{
    typeJeuActif = typeJeu;
}

void Partie::setNiveauDeLaPartie(Niveau *niveauPartie)
{
    niveauDeLaPartie = niveauPartie;
}
