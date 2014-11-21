#include "game.h"
#include "mainapplication.h"
#include "questionnaireeducatif.h"
#include "ressources.h"
#include <QtQml>

#include <QTextStream>

Game::Game(Profile *profileGame):
    QObject(0), m_profilActif(profileGame)
{
    m_currentTypeGame = 0;
    m_levelGame = 0;
}

Game::~Game()
{
    if(m_currentTypeGame != 0)
    {
        delete(m_currentTypeGame);
    }
    delete(m_levelGame);
}

void Game::setProfileGame(Profile *profileGame)
{
    m_profilActif = profileGame;
}

void Game::setTypeGame(TypeDeJeu *typeGame)
{
    if(m_currentTypeGame != 0)
    {
        delete(m_currentTypeGame);
    }
    m_currentTypeGame = typeGame;

    if(m_currentTypeGame->isQuestionnaire())
    {
        MainApplication::s_view->rootContext()->setContextProperty("questionnaireEducatif", (QuestionnaireEducatif*)m_currentTypeGame);
    }
    else
    {
        // A VOIR pour le jeu supplémentaire
    }
}

void Game::setLevelGame(Niveau *levelGame)
{
    if(m_levelGame != 0)
    {
        delete(m_levelGame);
    }

    m_levelGame = levelGame;
}

void Game::initLevelGame(QString nameLevel)
{
    setLevelGame(new Niveau(nameLevel));
}

void Game::launchTypeGame(QString nameTypeGame)
{
    //tant que pas de niveau défini
    initLevelGame("non defini");
    /////////////////////////////////

    setTypeGame(TypeDeJeu::makeTypeJeu(m_levelGame, nameTypeGame));

    connect(m_currentTypeGame, SIGNAL(incrementScore(int)), this,SLOT(scoreIncrement(int)));

    m_currentTypeGame->lancerJeu();
}

void Game::scoreIncrement(int nbPoints)
{
    m_profilActif->incrementScore(nbPoints);
    emit scoreChanged();
}
