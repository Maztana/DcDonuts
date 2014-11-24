#include "game.h"
#include "mainapplication.h"
#include "educationalquiz.h"
#include "ressources.h"
#include <QtQml>

#include <QTextStream>

/** Constructor of game with current profile
 * @brief Game::Game
 * @param profileGame the profile for the game
 */
Game::Game(Profile *profileGame):
    QObject(0), m_currentProfile(profileGame)
{
    m_currentTypeGame = 0;
    m_levelGame = 0;
}

/** Destructor of game
 * @brief Game::~Game
 */
Game::~Game()
{
    if(m_currentTypeGame != 0)
    {
        delete(m_currentTypeGame);
    }
    delete(m_levelGame);
}

/** Setter of profile for the game
 * @brief Game::setProfileGame
 * @param profileGame the new profile for game
 */
void Game::setProfileGame(Profile *profileGame)
{
    m_currentProfile = profileGame;
}

/** Setter for the game type in game.
 * @brief Game::setTypeGame
 * @param typeGame the game type
 */
void Game::setTypeGame(GameType *typeGame)
{
    if(m_currentTypeGame != 0)
    {
        delete(m_currentTypeGame);
    }
    m_currentTypeGame = typeGame;

    if(m_currentTypeGame->isQuiz())
    {
        MainApplication::s_view->rootContext()->setContextProperty("educationQuiz", (EducationalQuiz*)m_currentTypeGame);
    }
    else
    {
        // A VOIR pour le jeu supplémentaire
    }
}

/** Setter for the level game
 * @brief Game::setLevelGame
 * @param levelGame the level game
 */
void Game::setLevelGame(Level *levelGame)
{
    if(m_levelGame != 0)
    {
        delete(m_levelGame);
    }
    m_levelGame = levelGame;
}

/** Initialisation of level game
 * @brief Game::initLevelGame
 * @param nameLevel the name of level
 */
void Game::initLevelGame(QString nameLevel)
{
    setLevelGame(new Level(nameLevel));
}

/** Launcher of game type
 * @brief Game::launchTypeGame
 * @param nameTypeGame the game type
 */
void Game::launchGameType(QString nameTypeGame)
{
    //tant que pas de niveau défini
    initLevelGame("non defini");
    /////////////////////////////////

    setTypeGame(GameType::makeGameType(m_levelGame, nameTypeGame));

    connect(m_currentTypeGame, SIGNAL(incrementScore(int)), this,SLOT(scoreIncrement(int)));
    connect(m_currentTypeGame, SIGNAL(decrementScore(int)), this,SLOT(scoreDecrement(int)));

    m_currentTypeGame->launchGame();
}

/** Method for increment score of player game
 * @brief Game::scoreIncrement
 * @param nbPoints the number of point incremental
 */
void Game::scoreIncrement(int nbPoints)
{
    m_currentProfile->incrementScore(nbPoints);
    emit scoreChanged();
}

/** Method for decrement score of player game
 * @brief Game::scoreDecrement
 * @param nbPoints the number of point decremental
 */
void Game::scoreDecrement(int nbPoints)
{
    m_currentProfile->decrementScore(nbPoints);
    emit scoreChanged();
}
