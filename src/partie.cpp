#include "partie.h"
#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include "ressources.h"
#include <QtQml>

#include <QTextStream>

Game::Game(Profil *profilJeu):
    QObject(0), profilActif(profilJeu)
{
    typeJeuActif = 0;
    niveauDeLaPartie = 0;
}

Game::~Game()
{
    if(typeJeuActif != 0)
    {
        delete(typeJeuActif);
    }
    delete(niveauDeLaPartie);
}

void Game::setProfilPartie(Profil *profilJeu)
{
    profilActif = profilJeu;
}

void Game::initNiveauPartie(QString nameNiveau)
{
    setNiveauDeLaPartie(new Niveau(nameNiveau));
}

void Game::launchTypeJeu(QString nameTypeJeu)
{
    //tant que pas de niveau défini
    initNiveauPartie("non defini");
    /////////////////////////////////

    setTypeJeu(TypeDeJeu::makeTypeJeu(niveauDeLaPartie, nameTypeJeu));

    connect(typeJeuActif, SIGNAL(incrementScore(int)), this,SLOT(scoreIncrement(int)));

    typeJeuActif->lancerJeu();
}

void Game::setTypeJeu(TypeDeJeu *typeJeu)
{
    if(typeJeuActif != 0)
    {
        delete(typeJeuActif);
    }
    typeJeuActif = typeJeu;

    if(typeJeuActif->isQuestionnaire())
    {
        MainApplication::q_view->rootContext()->setContextProperty("questionnaireEducatif", (QuestionnaireEducatif*)typeJeuActif);
    }
    else
    {
        // A VOIR pour le jeu supplémentaire
    }
}

void Game::setNiveauDeLaPartie(Niveau *niveauPartie)
{
    if(niveauDeLaPartie != 0)
    {
        delete(niveauDeLaPartie);
    }

    niveauDeLaPartie = niveauPartie;
}

void Game::scoreIncrement(int nbPoints)
{
    profilActif->incrementScore(nbPoints);
    emit scoreChanged();
}
