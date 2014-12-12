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

/** Treat response for classic quiz (no flascard)
 * @brief Calcul::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void Calcul::treatmentAnswer(const int indexAnswer)
{
    if(m_listPropositions.at(indexAnswer-1).toInt() == getResult().toInt())
    {
        emit answerRight(indexAnswer);
        emit incrementScore(this->m_incremental_score * 2);
    }
    else
    {
        emit answerWrong(indexAnswer);
        emit decrementScore(this->m_incremental_score);
    }
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
