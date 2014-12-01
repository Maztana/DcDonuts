#include "level.h"


/** Complete constructor level whith name
 * @brief Level::Level
 * @param nameNiveau name of level
 */
Level::Level(QString nameNiveau) :
    QObject(0), m_name(nameNiveau)
{
    // Tant que les niveaux ne sont pas définis
    m_numberPropositions = 4;
    ///////////////////////////////////////////
}

/** Getter of level name
 * @brief Level::getName
 * @return the name of level
 */
const QString& Level::getName()const
{
    return m_name;
}

/** Getter of number propositions also level
 * @brief getNumberPropositions
 * @return the number of propositions
 */
int Level::getNumberPropositions()const
{
    return m_numberPropositions;
}
