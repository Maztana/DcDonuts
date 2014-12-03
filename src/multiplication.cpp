#include "multiplication.h"
#include "ressources.h"


/** Constructor
 * @brief Multiplication::Multiplication
 */
Multiplication::Multiplication():
    Calcul()
{
    s_incremental_score = INCREMENTAL_MULTIPLICATION_SCORE;
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
 * @brief Multiplication::~Multiplication
 */
Multiplication::~Multiplication()
{
}

/** Build a multiplication's question
 * @brief Multiplication::buildQuestion
 * @return  multiplication question
 */
Question* Multiplication::buildQuestion()
{
    //Générer question
    int operande1 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);
    int operande2 = rollDice(s_min_values[m_levelGame->getIndex()-1], s_max_values[m_levelGame->getIndex()-1]);

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(listValues);
    return maQuestion;
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

/** Getter of question text
 * @brief Addition::getTextQuestion
 * @return the text of question
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
