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

    //Profil par defaut
    creerProfils("Claudio");
    partieEnCours = 0;
}

MainApplication::~MainApplication()
{
    if(partieEnCours != 0)
    {
        delete(partieEnCours);
    }
    qDeleteAll(profils);

    //A vérifier
    delete(q_view);
}

const QString MainApplication::getNameProfil()const
{
    QString nameProfil = "undefined";
    if(profilActif != 0)
    {
        nameProfil = profilActif->getNom();
    }
    return nameProfil;
}

bool MainApplication::lancerPartie()
{
    if(profilActif != 0)
    {
        if(partieEnCours != 0)
        {
            delete(partieEnCours);
        }
        partieEnCours = new Partie(profilActif);
        q_view->rootContext()->setContextProperty("partie", partieEnCours);
        return true;
    }
    else {
        // ERREUR BESOIN DE SELECTION JOUEUR
        // OUVRIR SELECTION JOUEUR
        return false;
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
    emit nameProfilChanged();
}
