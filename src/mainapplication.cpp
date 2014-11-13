#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include <QtQml>

#include <QTextStream>

QQuickView* MainApplication::q_view = NULL;

MainApplication::MainApplication(QQuickView *q_view) :
    QObject(0)
{
    this->q_view = q_view;
    //QObject::connect(this, SIGNAL(play()), this, SLOT(lancerPartie()));

    //Profil par defaut
    creerProfils("Claudio",  new QDate(2003, 10, 30));
    partieEnCours = NULL;
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
        if(partieEnCours != NULL)
        {
            delete(partieEnCours);
        }
        partieEnCours = new Partie(profilActif);

        q_view->rootContext()->setContextProperty("partie", partieEnCours);
    }
    else {
        // ERREUR BESOIN DE SELECTION JOUEUR
        // OUVRIR SELECTION JOUEUR
    }
}

void MainApplication::creerProfils(QString nom, QDate *date)
{
    Profil *newProfil = new Profil(nom, date);
    profils.append(newProfil);

    changerProfilActif(newProfil);
}

void MainApplication::changerProfilActif(Profil *newProfilActif)
{
    profilActif = newProfilActif;
}
