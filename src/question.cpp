#include "question.h"
#include "ressources.h"

/** Constructor question with the operandes
 * @brief Question::Question
 * @param listValues list of values
 */
Question::Question(QList<QString> listValues, QString textQuestion) :
    QObject(0), m_listValues(listValues), m_textQuestion(textQuestion)
{
}

/** Destructor
 * @brief Question::~Question
 */
Question::~Question()
{
}
