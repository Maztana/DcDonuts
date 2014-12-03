#include "calcul.h"
#include <QDateTime>

#include <QTextStream>

// Déclaration statique
QList<int> Calcul::s_min_values = {0};
QList<int> Calcul::s_max_values = {0};
///////////////////////

/** Constructor
 * @brief Calcul::Calcul
 */
Calcul::Calcul() :
    EducationalQuiz()
{
    s_min_values.clear();
    s_max_values.clear();
}

/** Destructor
 * @brief Calcul::~Calcul
 */
Calcul::~Calcul()
{

}

/** Roll a dice between nbMin and nbMax
 * @brief Question::rollDice
 * @param nbMax number max
 * @param nbMin number min
 * @return a random number between nbMin and nbMax
 */
int Calcul::rollDice(int nbMin, int nbMax)const
{
    return qrand() % (((nbMax) + 1) - nbMin) + nbMin;
}

/** Setter for the number of propositions also level
 * @brief Calcul::setNumberPropositions
 * @param indexLevel the index of the level
 */
void Calcul::setNumberPropositions(int indexLevel)
{
    switch (indexLevel) {
    case 1:
        m_numberPropositions = 2;
        break;
    case 2:
        m_numberPropositions = 3;
        break;
    case 3:
        m_numberPropositions = 4;
        break;
    }

    emit numberPropositionsChanged();
}

/** Setter of list levels selectable
 * @brief Calcul::setLevelsSelectable
 */
void Calcul::setLevelsSelectable()
{
    m_listLevelSelectable.clear();

    for(int indexLevel = 0; indexLevel < s_min_values.size(); indexLevel++)
    {
        if(s_max_values[indexLevel] != s_min_values[indexLevel])
        {
            m_listLevelSelectable.append(1+indexLevel);
        }
    }
}
