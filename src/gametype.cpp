#include "gametype.h"
#include "ressources.h"

int GameType::s_incremental_score = 1;

/** Constructor complete of game type
 * @brief GameType::GameType
 */
GameType::GameType():
    QObject(0), m_levelGame(nullptr)
{
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

/** Getter of number propositions also level
 * @brief GameType::getNumberPropositions
 * @return the number of propositions
 */
int GameType::getNumberPropositions()const
{
    return m_numberPropositions;
}

/** Setter for the level game
 * @brief Game::setLevelGame
 * @param levelGame the level game
 */
void GameType::setLevelGame(Level *levelGame)
{
    delete(m_levelGame);
    m_levelGame = levelGame;
    setNumberPropositions(m_levelGame->getIndex());
    setLevelsSelectable();
    emit levelChanged();
}

/** Initialisation of level game
 * @brief Game::initLevelGame
 * @param nameLevel the name of level
 */
void GameType::initLevelGame(int indexLevel)
{
    setLevelGame(new Level(indexLevel));
    launchGame();
}
