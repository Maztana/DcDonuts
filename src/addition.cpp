#include "addition.h"
#include "ressources.h"

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
    int operande1 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);
    int operande2 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(listValues);
    return maQuestion;
}

/** Getter of proposition
 * @brief Addition::getProposition
 * @return a posible proposition for this question
 */
const QString Addition::getProposition()const
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

/** Getter of question description
 * @brief Addition::getTextQuestion
 * @return the description of question
 */
const QString Addition::getTextQuestion()const
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
            question += " + " + value;
        }
    }
    question += " = ";
    return question;
}
