#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    creerProfils("Joueur G",  new QDate(1993, 10, 30));
    changerProfilActif(profils.first());
}

MainApplication::~MainApplication()
{
    qDeleteAll(profils);
    if(partieEnCours != 0)
    {
        delete(partieEnCours);
    }
}

void MainApplication::lancerPartie()
{
    if(profilActif != 0)
    {
        partieEnCours = new Partie(profilActif);

        // OUVRIR QML CHOIX TYPE JEU
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
