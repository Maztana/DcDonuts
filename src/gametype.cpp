#include "gametype.h"
#include "ressources.h"

#include "addition.h"
#include "soustraction.h"
#include "division.h"
#include "multiplication.h"

int GameType::s_incremental_score = 1;

/** Constructor complete of game type
 * @brief GameType::GameType
 * @param gameLevel the level of game
 */
GameType::GameType(Level* gameLevel):
    QObject(0), m_gameLevel(gameLevel)
{
}

/** Destructor of game type
 * @brief GameType::~GameType
 */
GameType::~GameType()
{
}

/** Getter of level game
 * @brief GameType::getLevel
 * @return the level of game
 */
const Level& GameType::getLevel()
{
    return *m_gameLevel;
}

/** Factory for make a concret game type with level and name
 * @brief GameType::makeGameType
 * @param gameLevel the level of game
 * @param gameName the name of concret game type
 * @return the concret game type
 */
GameType* GameType::makeGameType(Level* gameLevel, QString gameName)
{
    GameType* currentGameType;

    if(!gameName.compare(MODE_FLASHCARD))
    {
        currentGameType = new Addition(gameLevel);
    }
    else if(!gameName.compare(MODE_DENOMBREMENT))
    {
        currentGameType = new Subtraction(gameLevel);
    }
    else if(!gameName.compare(MODE_COULEUR))
    {
        currentGameType = new Multiplication(gameLevel);
    }
    else
    {
        currentGameType = GameType::makeGameModeCalculation(gameLevel, gameName);
    }
    return currentGameType;
}

/** Factory for make a concret game type calculation with level and name
 * @brief GameType::makeGameModeCalculation
 * @param gameLevel the level of game
 * @param gameName the name of concret game type
 * @return the concret game type
 */
GameType* GameType::makeGameModeCalculation(Level* gameLevel, QString gameName)
{
    GameType* currentGameType;

    if(!gameName.compare(MODE_ADDITION))
    {
        currentGameType = new Addition(gameLevel);
    }
    else if(!gameName.compare(MODE_SOUSTRACTION))
    {
        currentGameType = new Subtraction(gameLevel);
    }
    else if(!gameName.compare(MODE_MULTIPLICATION))
    {
        currentGameType = new Multiplication(gameLevel);
    }
    else
    {
        currentGameType = new Division(gameLevel);
    }
    return currentGameType;
}
