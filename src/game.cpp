#include "game.h"
#include "mainapplication.h"
#include "educationalquiz.h"
#include "ressources.h"
#include "gametypefactory.h"
#include <QtQml>

/** Constructor of game with current profile
 * @brief Game::Game
 * @param profileGame the profile for the game
 */
Game::Game(Profile *profileGame):
    QObject(0), m_currentProfile(profileGame)
{
    m_currentGameType = nullptr;
}

/** Destructor of game
 * @brief Game::~Game
 */
Game::~Game()
{
    delete(m_currentGameType);
}

/** Setter for the game type in game.
 * @brief Game::setTypeGame
 * @param typeGame the game type
 */
void Game::setTypeGame(GameType *typeGame)
{
    delete(m_currentGameType);
    m_currentGameType = typeGame;

    if(m_currentGameType->isQuiz())
    {
        MainApplication::s_view->rootContext()->setContextProperty("educationQuiz", (EducationalQuiz*)m_currentGameType);
    }
    else
    {
        // A VOIR pour le jeu supplémentaire
    }
}

/** Init the game type
 * @brief Game::initGameType
 * @param nameTypeGame the game type
 */
void Game::initGameType(QList<int> identifiantsGameType)
{
    setTypeGame(GameTypeFactory::makeGameType(identifiantsGameType));

    connect(m_currentGameType, SIGNAL(incrementScore(int)), m_currentProfile,SLOT(scoreIncrement(int)));
    connect(m_currentGameType, SIGNAL(decrementScore(int)), m_currentProfile,SLOT(scoreDecrement(int)));

    emit gameTypeChanged();
}
