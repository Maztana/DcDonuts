#include "subtraction.h"
#include "ressources.h"

#include <QTextStream>

/** Constructor
 * @brief Subtraction::Subtraction
 * @param gameLevel the level game
 */
Subtraction::Subtraction():
    Calcul()
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_SUBTRACTION;
}

/** Destructor
 * @brief Subtraction::~Subtraction
 */
Subtraction::~Subtraction()
{
}

Question* Subtraction::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    if(operande1 < operande2)
    {
        int tmp = operande1;
        operande1 = operande2;
        operande2 = tmp;
    }

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(MODE_SUBTRACTION, listValues);
    return maQuestion;
}

void Subtraction::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 14;
}

/** Getter of proposition
 * @brief Subtraction::getProposition
 * @return a posible proposition for this question
 */
const QString Subtraction::getProposition()const
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
 * @brief Subtraction::getResult
 * @return the result
 */
const QString Subtraction::getResult()const
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
            result -= value.toInt();
        }
    }
    return QString::number(result);
}

/** Getter of question description
 * @brief Addition::getDescription
 * @return the description of question
 */
const QString Subtraction::getTextQuestion()const
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
            question += " - " + value;
        }
    }
    question += " = ";
    return question;
}

