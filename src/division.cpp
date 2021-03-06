#include "division.h"

/** Constructor
 * @brief Division::Division
 */
Division::Division():
    Calcul()
{
    m_incremental_score = INCREMENTAL_DIVISION_SCORE;
    /** Easy */
    m_min_values.append(0);
    m_max_values.append(0);
    /** Medium */
    m_min_values.append(0);
    m_max_values.append(9);
    /** Hard */
    m_min_values.append(0);
    m_max_values.append(99);
}

/** Destructor
 * @brief Division::~Division
 */
Division::~Division()
{
}

/** Build a division's question
 * @brief Division::buildQuestion
 * @return a division question
 */
Question* Division::buildQuestion()
{
    //Générer question
    int operand1 = 0;
    int operand2 = 0;
    int mod = 1;
    while(mod != 0)
    {
        operand1 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);
        operand2 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);

        if(operand1 == 0 && operand2 == 0)
        {
            mod = 1;
        }
        else
        {
            if(operand1 < operand2)
            {
                int tmp = operand1;
                operand1 = operand2;
                operand2 = tmp;
            }
            if(operand2 == 0)
            {
                operand2 = 1;
            }
            mod = operand1 % operand2;
        }
    }

    QList<QString> listValues;
    listValues.append(QString::number(operand1));
    listValues.append(QString::number(operand2));

    Question* myQuestion = new Question(listValues, makeTextQuestion(listValues));
    return myQuestion;
}

/** Getter result of question
 * @brief Division::getResult
 * @return the result
 */
const QString Division::getResult()const
{
    bool firstValue = true;
    int result = 0;

    for(QString value : m_currentQuestion->getValues())
    {
        if(firstValue)
        {
            result = value.toInt();
            firstValue = false;
        }
        else
        {
            result = result / value.toInt();
        }
    }
    return QString::number(result);
}

/** Getter of question text
 * @brief Division::makeTextQuestion
 * @return the text of question
 */
const QString Division::makeTextQuestion(QList<QString> values)const
{
    QString question;
    bool isFirstValue = true;

    for(QString value : values)
    {
        if(isFirstValue)
        {
            question = value;
            isFirstValue = false;
        }
        else
        {
            question += " / " + value;
        }
    }
    question += " = ";
    return question;
}
