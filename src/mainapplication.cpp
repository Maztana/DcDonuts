#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    creerProfils("Bamboula",  new QDate(1993, 10, 30));
    changerProfilActif(profils.first());
}

void MainApplication::lancerPartie()
{
    if(profilActif != 0)
    {
        // OUVRIR QML CHOIX TYPE JEU
    }
    else {
        // NE RIEN FAIRE
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

void MainApplication::changerLangue()
{
    //PAS D'IMPLEMENTATION
}
