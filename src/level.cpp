#include "level.h"

/** Complete constructor level whith name
 * @brief Level::Level
 * @param nameNiveau name of level
 */
Level::Level(QString nameNiveau) :
    QObject(0), m_name(nameNiveau)
{
}

/** Getter of level name
 * @brief Level::getName
 * @return the name of level
 */
const QString& Level::getName()const
{
    return m_name;
}
