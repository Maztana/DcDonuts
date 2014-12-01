#include "gametype.h"
#include "ressources.h"

#include "addition.h"
#include "subtraction.h"
#include "division.h"
#include "multiplication.h"

int GameType::s_incremental_score = 1;

/** Constructor complete of game type
 * @brief GameType::GameType
 * @param gameLevel the level of game
 */
GameType::GameType():
    QObject(0), m_levelGame(nullptr)
{
    //tant que pas de niveau défini
    initLevelGame("non defini");
    /////////////////////////////////
}

/** Destructor of game type
 * @brief GameType::~GameType
 */
GameType::~GameType()
{
    delete(m_levelGame);
}

/** Getter of level game
 * @brief GameType::getLevel
 * @return the level of game
 */
const Level& GameType::getLevel()
{
    return *m_levelGame;
}

/** Setter for the level game
 * @brief Game::setLevelGame
 * @param levelGame the level game
 */
void GameType::setLevelGame(Level *levelGame)
{
    delete(m_levelGame);
    m_levelGame = levelGame;
    emit levelChanged();
}


/** Initialisation of level game
 * @brief Game::initLevelGame
 * @param nameLevel the name of level
 */
void GameType::initLevelGame(QString nameLevel)
{
    setLevelGame(new Level(nameLevel));
}
