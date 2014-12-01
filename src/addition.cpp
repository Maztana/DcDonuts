#include "addition.h"
#include "ressources.h"

/** Constructor
 * @brief Addition::Addition
 * @param gameLevel the level of game
 */
Addition::Addition():
    Calcul()
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_ADDITION;
}

/** Destructor
 * @brief Addition::~Addition
 */
Addition::~Addition()
{
}

Question* Addition::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(MODE_ADDITION, listValues);
    return maQuestion;
}

void Addition::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 14;
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
 * @brief Addition::getDescription
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
