#include "multiplication.h"

/** Constructor
 * @brief Multiplication::Multiplication
 */
Multiplication::Multiplication():
    Calcul()
{
    m_incremental_score = INCREMENTAL_MULTIPLICATION_SCORE;
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
    int operande1 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);
    int operande2 = rollDice(m_min_values[m_levelGame->getIndex()-1], m_max_values[m_levelGame->getIndex()-1]);

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* myQuestion = new Question(listValues, makeTextQuestion(listValues));
    return myQuestion;
}

/** Getter of proposition
 * @brief Multiplication::getProposition
 * @return a posible proposition for this question
 */
const QString Multiplication::getProposition()const
{
    int propo = m_min_values[m_levelGame->getIndex()-1];
    bool isFirstValue = true;
    QList<int> values;

    for(QString value : m_currentQuestion->getValues())
    {
        values.append(value.toInt() + rollDice(-(getNumberPropositions()/2), getNumberPropositions()/2));
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

    if(propo < m_min_values[m_levelGame->getIndex()-1])
    {
        propo = m_min_values[m_levelGame->getIndex()-1];
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
 * @brief Multiplication::makeTextQuestion
 * @return the text of question
 */
const QString Multiplication::makeTextQuestion(QList<QString> values)const
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
            question += " x " + value;
        }
    }
    question += " = ";
    return question;
}
