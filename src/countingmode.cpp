#include "countingmode.h"

/** Constructor
 * @brief CountingMode::CountingMode
 */
CountingMode::CountingMode():
    EducationalQuiz()
{
    m_incremental_score = INCREMENTAL_COUNTING_SCORE;
    /** Easy */
    m_min_values.append(0);
    m_max_values.append(7);
    /** Medium */
    m_min_values.append(0);
    m_max_values.append(10);
    /** Hard */
    m_min_values.append(0);
    m_max_values.append(15);
}

/** Destructor
 * @brief CountingMode::CountingMode
 */
CountingMode::~CountingMode()
{
}

/** Build a question of CountingMode
 * @brief CountingMode::buildQuestion
 * @return CountingMode's question
 */
Question* CountingMode::buildQuestion()
{
    //Générer question
    int operand1 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);

    Question* myQuestion = new Question({QString::number(operand1)}, makeTextQuestion({QString::number(operand1)}));
    return myQuestion;
}

/** Getter of proposition
 * @brief CountingMode::getProposition
 * @return a posible proposition for this question
 */
const QString CountingMode::getProposition()const
{
    int propo = 0;

    if(getResult().toInt() < 4)
    {
        propo = qrand() % 4;
    }
    else
    {
        int nbMax = getResult().toInt() + getResult().toInt()/2;
        int nbMin = getResult().toInt() - getResult().toInt()/2;
        if(nbMax > m_max_values[m_levelGame->getIndex()-1])
        {
            nbMax = m_max_values[m_levelGame->getIndex()-1];
        }
        propo = rollDice(nbMin, nbMax);
    }

    if(propo < 0)
    {
        propo = 0;
    }
    return QString::number(propo);
}


/** Getter result of question
 * @brief CountingMode::getResult
 * @return the result
 */
const QString CountingMode::getResult()const
{
    return m_currentQuestion->getValues().first();
}

/** Getter of question text
 * @brief CountingMode::makeTextQuestion
 * @return the text of question
 */
const QString CountingMode::makeTextQuestion(QList<QString>)const
{
    return tr("How many forms");
}

/** Setter for the number of propositions also level
 * @brief CountingMode::setNumberPropositions
 */
void CountingMode::setNumberPropositions()
{
    m_numberPropositions = 4;
    emit numberPropositionsChanged();
}

/** Setter of list levels selectable
 * @brief CountingMode::setLevelsSelectable
 */
void CountingMode::setLevelsSelectable()
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
