#include "level.h"


/** Constructor level for classic level
 * @brief Level::Level
 * @param indexLevel index of level
 */
Level::Level(int indexLevel) :
    QObject(0), m_indexLevel(indexLevel)
{
    initLevel();
}

/** Constructor level for flashcard
 * @brief Level::Level
 * @param nameLevel name of data base flashcard
 */
Level::Level(QString nameLevel) :
    QObject(0), m_indexLevel(0), m_name(nameLevel)
{
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

/** Initialize level name
 * @brief Level::initLevel
 */
void Level::initLevel()
{
    switch (m_indexLevel){
    case 1:
        m_name = tr("Easy");
        break;
    case 2:
        m_name = tr("Medium");
        break;
    case 3:
        m_name = tr("Hard");
        break;
    }
}
