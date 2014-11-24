#include "question.h"
#include "ressources.h"

#include <QTextStream>
#include <QDateTime>

/** Constructor question with game mode and the operandes
 * @brief Question::Question
 * @param gameMode the mode of the game for this question
 * @param firstOperande the first operand
 * @param secondOperande the second operand
 */
Question::Question(const QString& gameMode, int firstOperande, int secondOperande) :
    QObject(0), m_gameMode(gameMode), m_firstOperande(firstOperande), m_secondOperande(secondOperande)
{
    //qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Getter for result of question
 * @brief Question::getResult
 * @return the result
 */
QString Question::getResult()const
{
    QString result = 0;

    if(!m_gameMode.compare(MODE_ADDITION))
    {
        result = QString::number(m_firstOperande + m_secondOperande);
    }
    else if (!m_gameMode.compare(MODE_SUBTRACTION))
    {
        result = QString::number(m_firstOperande - m_secondOperande);
    }
    else if(!m_gameMode.compare(MODE_DIVISION))
    {
        result = QString::number(m_firstOperande / m_secondOperande);
    }
    else if(!m_gameMode.compare(MODE_MULTIPLICATION))
    {
        result = QString::number(m_firstOperande * m_secondOperande);
    }

    return result;
}

/** Getter of proposition
 * @brief Question::getProposal
 * @return a posible proposition for this question
 */
QString Question::getProposal()const
{
    QString proposal = "";

    if(!m_gameMode.compare(MODE_COLOR))
    {
        // MAKE PROPOSAL COLOR
    }
    else if (!m_gameMode.compare(MODE_ENUMERATION))
    {
        // MAKE PROPOSAL MODE_DENOMBREMENT
    }
    else if(!m_gameMode.compare(MODE_FLASHCARD))
    {
        //MAKE PROPOSAL MODE_FLASHCARD
    }
    else
    {
        proposal = getProposalCalculation();
    }

    return proposal;
}

/** Getter of proposition for calculation
 * @brief Question::getProposalCalculation
 * @return a posible proposition for this question
 */
QString Question::getProposalCalculation()const
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///         REVOIR LES RANDOMS DE CHAQUE PROPOSITION
    ///
    /////////////////////////////////////////////////////////////////////////////////////
    int propo = 0;
    int nbMin = 0;
    int nbMax = 0;
    bool isRandomable = false;

    if(!m_gameMode.compare(MODE_ADDITION))
    {
        nbMax = m_firstOperande + 3 +(m_secondOperande*2);
        nbMin = m_secondOperande-m_firstOperande;
        isRandomable = true;
    }
    else if (!m_gameMode.compare(MODE_SUBTRACTION))
    {
        nbMax = m_firstOperande + 3;
        nbMin = m_firstOperande- 3 - (m_secondOperande*2);
        isRandomable = true;
    }
    else if(!m_gameMode.compare(MODE_DIVISION))
    {
        nbMax = qrand() % (((m_firstOperande + 1) + 1) - (m_firstOperande - 1)) + (m_firstOperande - 1);
        nbMin = qrand() % (((m_secondOperande + 1) + 1) - (m_secondOperande - 1)) + (m_secondOperande - 1);
    }
    else if(!m_gameMode.compare(MODE_MULTIPLICATION))
    {
        nbMax = qrand() % (((m_firstOperande + 1) + 1) - (m_firstOperande - 1)) + (m_firstOperande - 1);
        nbMin = qrand() % (((m_secondOperande + 1) + 1) - (m_secondOperande - 1)) + (m_secondOperande - 1);
    }

    if(nbMax < nbMin)
    {
        int tmp = nbMax;
        nbMax = nbMin;
        nbMin = tmp;
    }

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
            propo = nbMax * nbMin;
        }
        if(getResult().toInt() < 3)
        {
            propo = qrand() % 4;
        }
    }
    else
    {
        propo = qrand() % (((nbMax) + 1) - nbMin) + nbMin;
    }

    if(propo < 0)
    {
        propo = 0;
    }
    return QString::number(propo);
}

/** Getter of question description
 * @brief Question::getDescription
 * @return the description of question
 */
QString Question::getDescription()const
{
    QString question = QString::number(m_firstOperande);

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

    question += QString::number(m_secondOperande) + " = ";

    return question;
}
