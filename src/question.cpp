#include "question.h"
#include "ressources.h"

/** Constructor question with the operandes
 * @brief Question::Question
 * @param listValues list of values
 */
Question::Question(QList<QString> listValues) :
    QObject(0), m_listValues(listValues)
{
}

/** Getter of list values for this questions
 * @brief Question::getValues
 * @return the list of values
 */
const QList<QString> Question::getValues()const
{
    return m_listValues;
}
