#include "question.h"
#include "ressources.h"

/** Constructor question with game mode and the operandes
 * @brief Question::Question
 * @param gameMode the mode of the game for this question
 * @param firstOperande the first operand
 * @param secondOperande the second operand
 */
Question::Question(const QString& gameMode, QList<QString> listValues) :
    QObject(0), m_gameMode(gameMode), m_listValues(listValues)
{
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Faire text question dans chaque type game */
/** Getter of question description
 * @brief Question::getDescription
 * @return the description of question
 */
/*const QString Question::getTextQuestion()const
{
    QString question;
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
    return question;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////


/** Getter of list values for this questions
 * @brief Question::getValues
 * @return the list of values
 */
const QList<QString> Question::getValues()const
{
    return m_listValues;
}
