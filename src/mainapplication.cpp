#include "mainapplication.h"

MainApplication::MainApplication() :
    QObject(0)
{
    creerProfils("Cool Rasta",  new QDate(1993, 10, 30));
    changerProfilActif(profils.first());

    partieEnCours = new Partie();
}

MainApplication::~MainApplication()
{
    qDeleteAll(profils);
    if(partieEnCours != 0)
    {
        delete(partieEnCours);
    }
}

const Partie* MainApplication::partie() const
{
    return partieEnCours;
}

const QString MainApplication::nameProfil() const
{
    return profilActif->getNom();
}

const QString MainApplication::nameNiveau() const
{
    return partieEnCours->getNiveauDeLaPartie()->getName();
}

bool MainApplication::runPartie()
{
    return isPartieRunning;
}

void MainApplication::setRunPartie(bool isRunPartie)
{
    isPartieRunning = isRunPartie;
}

void MainApplication::lancerPartie()
{
    if(profilActif != 0)
    {
        partieEnCours = new Partie();
        partieEnCours->setProfilPartie(profilActif);
    }
    else {
        // ERREUR BESOIN DE SELECTION JOUEUR
        // OUVRIR SELECTION JOUEUR
    }
}

void MainApplication::creerProfils(QString nom, QDate *date)
{
    Profil *defaultProfil = new Profil(nom, date);
    profils.append(defaultProfil);
}

void MainApplication::changerProfilActif(Profil *newProfilActif)
{
    profilActif = newProfilActif;
}
