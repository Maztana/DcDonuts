#include "multiplication.h"
#include "ressources.h"


/** Constructor
 * @brief Multiplication::Multiplication
 * @param gameLevel the level of game
 */
Multiplication::Multiplication():
    Calcul()
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_MULTIPLICATION;
}

/** Destructor
 * @brief Multiplication::~Multiplication
 */
Multiplication::~Multiplication()
{
}

Question* Multiplication::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(MODE_MULTIPLICATION, listValues);
    return maQuestion;
}

void Multiplication::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 9;
}

/** Getter of proposition
 * @brief Multiplication::getProposition
 * @return a posible proposition for this question
 */
const QString Multiplication::getProposition()const
{
    int propo = 0;
    bool isFirstValue = true;
    QList<int> values;

    for(QString value : m_currentQuestion->getValues())
    {
        values.append(value.toInt() + rollDice(-2, 2));
    }

    for(int value : values)
    {
        if(isFirstValue)
        {
            propo = value;
            isFirstValue = false;
        }
        else
        {
            propo = propo * value;
        }
    }

    if(propo < 0)
    {
        propo = 0;
    }
    return QString::number(propo);
}


/** Getter result of question
 * @brief Multiplication::getResult
 * @return the result
 */
const QString Multiplication::getResult()const
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
            result = result * value.toInt();
        }
    }
    return QString::number(result);
}

/** Getter of question description
 * @brief Addition::getDescription
 * @return the description of question
 */
const QString Multiplication::getTextQuestion()const
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
            question += " x " + value;
        }
    }
    question += " = ";
    return question;
}
