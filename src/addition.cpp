#include "addition.h"

/** Constructor
 * @brief Addition::Addition
 */
Addition::Addition():
    Calcul()
{
    m_incremental_score = INCREMENTAL_ADDITION_SCORE;
    /** Easy */
    m_min_values.append(0);
    m_max_values.append(9);
    /** Medium */
    m_min_values.append(0);
    m_max_values.append(99);
    /** Hard */
    m_min_values.append(0);
    m_max_values.append(9999);
}

/** Destructor
 * @brief Addition::~Addition
 */
Addition::~Addition()
{
}

/** Build a question of addition
 * @brief Addition::buildQuestion
 * @return addition's question
 */
Question* Addition::buildQuestion()
{
    //Générer question
    int operand1 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);
    int operand2 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);

    QList<QString> listValues;
    listValues.append(QString::number(operand1));
    listValues.append(QString::number(operand2));

    Question* myQuestion = new Question(listValues, makeTextQuestion(listValues));
    return myQuestion;
}


/** Getter result of question
 * @brief Addition::getResult
 * @return the result
 */
const QString Addition::getResult()const
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
            result += value.toInt();
        }
    }
    return QString::number(result);
}

/** Getter of question text
 * @brief Addition::makeTextQuestion
 * @return the text of question
 */
const QString Addition::makeTextQuestion(QList<QString> values)const
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
            question += " + " + value;
        }
    }
    question += " = ";
    return question;
}
