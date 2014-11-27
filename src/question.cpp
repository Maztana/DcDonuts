#include "question.h"
#include "ressources.h"

#include <QTextStream>

/** Constructor question with game mode and the operandes
 * @brief Question::Question
 * @param gameMode the mode of the game for this question
 * @param firstOperande the first operand
 * @param secondOperande the second operand
 */
Question::Question(const QString& gameMode, QList<QString> listValues) :
    QObject(0), m_gameMode(gameMode), m_listValues(listValues)
{
    //test en attente remaniment propositions
    //m_firstOperande = listValues[0].toInt();
    //m_secondOperande = listValues[1].toInt();
    ///////////////////////////////////////////////
}

/** Getter for result of question
 * @brief Question::getResult
 * @return the result
 */
QString Question::getResult()const
{
    QString result = "";

    if(!m_gameMode.compare(MODE_COLOR))
    {
        // MAKE result COLOR
    }
    else if (!m_gameMode.compare(MODE_COUNTING))
    {
        // MAKE result MODE_DENOMBREMENT
    }
    else if(!m_gameMode.compare(MODE_FLASHCARD))
    {
        //MAKE result MODE_FLASHCARD
    }
    else
    {
        result = QString::number(getResultCalcul());
    }
    return result;
}

/** Getter of proposition
 * @brief Question::getProposition
 * @return a posible proposition for this question
 */
QString Question::getProposition()const
{
    QString proposition = "";

    if(!m_gameMode.compare(MODE_COLOR))
    {
        // MAKE PROPOSition COLOR
    }
    else if (!m_gameMode.compare(MODE_COUNTING))
    {
        // MAKE PROPOSition MODE_DENOMBREMENT
    }
    else if(!m_gameMode.compare(MODE_FLASHCARD))
    {
        //MAKE PROPOSition MODE_FLASHCARD
    }
    else
    {
        proposition = getPropositionCalcul();
    }

    return proposition;
}


/** Getter of question description
 * @brief Question::getDescription
 * @return the description of question
 */
QString Question::getTextQuestion()const
{
    QString question /*= QString::number(m_firstOperande)*/;
    bool isFirstValue = true;

    for(QString value : m_listValues)
    {
        if(isFirstValue)
        {
            question = value;
            isFirstValue = false;
        }
        else
        {
            if(!m_gameMode.compare(MODE_ADDITION))
            {
                question += " + ";
            }
            else if (!m_gameMode.compare(MODE_SUBTRACTION))
            {
                question += " - ";
            }
            else if(!m_gameMode.compare(MODE_DIVISION))
            {
                question += " / ";
            }
            else if(!m_gameMode.compare(MODE_MULTIPLICATION))
            {
                question += " x ";
            }
            question += value;
        }
    }
    question += " = ";
    QTextStream(stdout) << question << endl;
    return question;
}


/** Roll a dice between nbMin and nbMax
 * @brief Question::rollDice
 * @param nbMax number max
 * @param nbMin number min
 * @return a random number between nbMin and nbMax
 */
int Question::rollDice(int nbMax, int nbMin)const
{
    return qrand() % (((nbMax) + 1) - nbMin) + nbMin;
}


/** Getter for calcul result of question
 * @brief Question::getResultCalcul
 * @return the result
 */
int Question::getResultCalcul()const
{
    bool firstValue = true;
    int result = 0;

    for(QString value : m_listValues)
    {
        if(firstValue)
        {
            result = value.toInt();
            firstValue = false;
        }
        else
        {
            if(!m_gameMode.compare(MODE_ADDITION))
            {
                result += value.toInt();
            }
            else if (!m_gameMode.compare(MODE_SUBTRACTION))
            {
                result -= value.toInt();
            }
            else if(!m_gameMode.compare(MODE_DIVISION))
            {
                result = result / value.toInt();
            }
            else if(!m_gameMode.compare(MODE_MULTIPLICATION))
            {
                result = result * value.toInt();
            }
        }
    }
    return result;
}


/** Getter of proposition for calcul
 * @brief Question::getPropositionCalcul
 * @return a posible proposition for this question
 */
QString Question::getPropositionCalcul()const
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///         REVOIR LES RANDOMS DE CHAQUE PROPOSITION
    ///
    /////////////////////////////////////////////////////////////////////////////////////
    int propo = 0;
    QList<int> values;
    bool isFirstValue = true;
    int nbMin = 0;
    int nbMax = 0;
    bool isRandomable = false;

    if(!m_gameMode.compare(MODE_ADDITION) || !m_gameMode.compare(MODE_SUBTRACTION))
    {
        nbMax = getResult().toInt() + getResult().toInt()/2;
        nbMin = getResult().toInt() - getResult().toInt()/2;
        isRandomable = true;
    }
    else if(!m_gameMode.compare(MODE_DIVISION))
    {
        //nbMax = qrand() % (((m_firstOperande + 1) + 1) - (m_firstOperande - 1)) + (m_firstOperande - 1);
        //nbMin = qrand() % (((m_secondOperande + 1) + 1) - (m_secondOperande - 1)) + (m_secondOperande - 1);
    }
    else if(!m_gameMode.compare(MODE_MULTIPLICATION))
    {
        QTextStream(stdout) << m_listValues[0] << " " << m_listValues[1] << endl;
        values.append(m_listValues[0].toInt() + rollDice(-2, 2));
        //qrand() % (((m_firstOperande + 1) + 1) - (m_firstOperande - 1)) + (m_firstOperande - 1);
        values.append(m_listValues[1].toInt() + rollDice(-2, 2));
        //qrand() % (((m_secondOperande + 1) + 1) - (m_secondOperande - 1)) + (m_secondOperande - 1);
    }

    /*if(nbMax < nbMin)
    {
        int tmp = nbMax;
        nbMax = nbMin;
        nbMin = tmp;
    }*/

    if(!isRandomable)
    {
        if(!m_gameMode.compare(MODE_DIVISION))
        {
            if(nbMin == 0)
            {
                nbMin = 1;
            }
            propo = nbMax / nbMin;
            QTextStream(stdout) << nbMax << " / " << nbMin << " = " << propo << endl;
        }
        else if(!m_gameMode.compare(MODE_MULTIPLICATION))
        {
            for(int value : values)
            {
                if(isFirstValue)
                {
                    propo = value;
                    isFirstValue = false;
                }
                else
                {
                    QTextStream(stdout) << propo << "*" << value << endl;
                    propo = propo * value;
                }
            }
            //propo = nbMax * nbMin;
        }

    }
    else
    {
        if(getResult().toInt() < 4)
        {
            propo = qrand() % 4;
        }
        else
        {
            propo = rollDice(nbMax, nbMin);
        }
    }

    if(propo < 0)
    {
        propo = 0;
    }

    return QString::number(propo);
}
