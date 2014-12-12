#include "question.h"
#include "ressources.h"

/** Constructor question with the operandes
 * @brief Question::Question
 * @param listValues list of values
 */
Question::Question(QList<QString> listValues, QString textQuestion, int id) :
    QObject(0), m_listValues(listValues), m_textQuestion(textQuestion), m_id(id)
{
}

/** Destructor
 * @brief Question::~Question
 */
Question::~Question()
{
}
