#include "subtraction.h"
#include "ressources.h"

#include <QTextStream>

/** Constructor
 * @brief Subtraction::Subtraction
 */
Subtraction::Subtraction():
    Calcul()
{
    s_incremental_score = INCREMENTAL_SUBTRACTION_SCORE;
    /** Easy */
    s_min_values.append(0);
    s_max_values.append(9);
    /** Medium */
    s_min_values.append(0);
    s_max_values.append(99);
    /** Hard */
    s_min_values.append(0);
    s_max_values.append(9999);
}

/** Destructor
 * @brief Subtraction::~Subtraction
 */
Subtraction::~Subtraction()
{
}

/** Build a substraction's question
 * @brief Substraction::buildQuestion
 * @return  substraction question
 */
Question* Subtraction::buildQuestion()
{
    //Générer question
    int operande1 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);
    int operande2 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);

    if(operande1 < operande2)
    {
        int tmp = operande1;
        operande1 = operande2;
        operande2 = tmp;
    }

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(listValues);
    return maQuestion;
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

/** Getter of question text
 * @brief Addition::getTextQuestion
 * @return the text of question
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

