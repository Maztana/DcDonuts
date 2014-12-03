#include "division.h"
#include "ressources.h"

/** Constructor
 * @brief Division::Division
 */
Division::Division():
    Calcul()
{
    s_incremental_score = INCREMENTAL_DIVISION_SCORE;
    /** Easy */
    s_min_values.append(0);
    s_max_values.append(0);
    /** Medium */
    s_min_values.append(0);
    s_max_values.append(9);
    /** Hard */
    s_min_values.append(0);
    s_max_values.append(99);
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
        operand1 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);
        operand2 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);

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

    Question* maQuestion = new Question(listValues);
    return maQuestion;
}

/** Getter of proposition
 * @brief Division::getProposition
 * @return a posible proposition for this question
 */
const QString Division::getProposition()const
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
        propo = rollDice(nbMin, nbMax);
    }

    if(propo < 0)
    {
        propo = 0;
    }
    return QString::number(propo);
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
 * @brief Addition::getTextQuestion
 * @return the text of question
 */
const QString Division::getTextQuestion()const
{
    QString question;
    bool isFirstValue = true;

    for(QString value : m_currentQuestion->getValues())
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
