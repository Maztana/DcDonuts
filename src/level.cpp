#include "level.h"


/** Complete constructor level whith name
 * @brief Level::Level
 * @param indexNiveau index of level
 */
Level::Level(int indexNiveau) :
    QObject(0), m_indexLevel(indexNiveau)
{
    initLevel();
}

/** Getter of level index
 * @brief Level::getIndex
 * @return the index of level
 */
int Level::getIndex()const
{
    return m_indexLevel;
}

/** Getter of level name
 * @brief Level::getName
 * @return the name of level
 */
const QString& Level::getName()const
{
    return m_name;
}

void Level::initLevel()
{
    switch (m_indexLevel) {
    case 1:
        m_name = "Easy";
        break;
    case 2:
        m_name = "Medium";
        break;
    case 3:
        m_name = "Hard";
        break;
    case 4:
        m_name = "Auto";
        break;
    }
}
