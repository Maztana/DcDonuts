#include "calcul.h"
#include <QDateTime>


/** Constructor
 * @brief Calcul::Calcul
 */
Calcul::Calcul() :
    EducationalQuiz()
{
    m_min_values.clear();
    m_max_values.clear();
}

/** Destructor
 * @brief Calcul::~Calcul
 */
Calcul::~Calcul()
{

}

/** Getter of proposition
 * @brief Calcul::getProposition
 * @return a posible proposition for this question
 */
const QString Calcul::getProposition()const
{
    int propo = m_min_values[m_levelGame->getIndex()-1];

    if(getResult().toInt() < (m_min_values[m_levelGame->getIndex()-1] + getNumberPropositions()))
    {
        propo = qrand() % getNumberPropositions() + m_min_values[m_levelGame->getIndex()-1];
    }
    else
    {
        int nbMax = getResult().toInt() + getResult().toInt()/2;
        int nbMin = getResult().toInt() - getResult().toInt()/2;
        propo = rollDice(nbMin, nbMax);
    }

    if(propo < m_min_values[m_levelGame->getIndex()-1])
    {
        propo = m_min_values[m_levelGame->getIndex()-1];
    }
    return QString::number(propo);
}

/** Setter for the number of propositions also level
 * @brief Calcul::setNumberPropositions
 */
void Calcul::setNumberPropositions()
{
    m_numberPropositions = 4;
    emit numberPropositionsChanged();
}

/** Setter of list levels selectable
 * @brief Calcul::setLevelsSelectable
 */
void Calcul::setLevelsSelectable()
{
    m_listLevelsSelectable.clear();

    for(int indexLevel = 0; indexLevel < m_min_values.size(); indexLevel++)
    {
        if(m_max_values[indexLevel] != m_min_values[indexLevel])
        {
            m_listLevelsSelectable.append(1+indexLevel);
        }
    }
    emit levelsSelectableChanged();
}
