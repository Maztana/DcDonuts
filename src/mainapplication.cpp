#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include <QtQml>

#include <QTextStream>

QQuickView* MainApplication::q_view = NULL;
QGuiApplication* MainApplication::q_application = NULL;

MainApplication::MainApplication(QGuiApplication *q_application, QQuickView *q_view) :
    QObject(0), managerBDD(ManagerBdd::getInstance())
{
    chargerProfils();

    this->q_view = q_view;
    this->q_application = q_application;

    partieEnCours = 0;

}

MainApplication::~MainApplication()
{
    if(partieEnCours != 0)
    {
        delete(partieEnCours);
    }
    qDeleteAll(profils);
}

void MainApplication::chargerProfils(){

    bool isOpen = managerBDD.openDB();

    if(isOpen){
        profils=managerBDD.selectAllProfils();

        if(profils.size()<1){
            // si aucun profil en BDD
            //Profil par defaut
            creerProfils("DefaultProfil");
        }
        else{

            changerProfilActif(profils.value(0)); // on prend le premier par défaut pour le moment
        }
    }

}

void MainApplication::lancerPartie()
{

    if(profilActif != 0)
    {
        if(partieEnCours != 0)
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


