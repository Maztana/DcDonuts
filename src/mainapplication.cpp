#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include <QtQml>

#include <QTextStream>

QQuickView* MainApplication::q_view = NULL;
QGuiApplication* MainApplication::q_application = NULL;

MainApplication::MainApplication(QGuiApplication *q_application, QQuickView *q_view) :
    QObject(0)
{
    QTextStream(stdout) << "Charger les profils" << endl;

    this->q_view = q_view;
    this->q_application = q_application;
    //QObject::connect(this, SIGNAL(play()), this, SLOT(lancerPartie()));

    //Profil par defaut
    creerProfils("Claudio");
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

void MainApplication::creerProfils(QString nom)
{
    Profil *newProfil = new Profil(nom);
    profils.append(newProfil);

    changerProfilActif(newProfil);
}

void MainApplication::changerProfilActif(Profil *newProfilActif)
{
    profilActif = newProfilActif;
}
