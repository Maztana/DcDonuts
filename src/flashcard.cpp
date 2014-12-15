#include "flashcard.h"
#include "managerbdd.h"

/** Constructor
 * @brief Flashcard::Flashcard
 * @param parent
 */
Flashcard::Flashcard() :
    EducationalQuiz()
{
}

/** Destructor
 * @brief Flashcard::~Flashcard
 */
Flashcard::~Flashcard()
{
    qDeleteAll(m_listCards);
}

/** Build a question of addition
 * @brief Flashcard::buildQuestion
 * @return addition's question
 */
Question* Flashcard::buildQuestion()
{
    return m_listCards.at(rollDice(0, m_listCards.size()-1));
}

/** Treat response for classic quiz (no flascard)
 * @brief Flashcard::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void Flashcard::treatmentAnswer(const int)
{
    emit answerGiven();
    // treat auto evaluation of the child
        // 0 forgotten
        // 1 in acquisition
        // 2 known
        // 3 perfect

    launchQuestion();
}

/** Init and load the Db cards
 * @brief Flashcard::initDB
 * @param nameDataBase name of data base
 */
void Flashcard::initDB(QString nameDataBase)
{
    //init the DB
    qDeleteAll(m_listCards);
    m_levelGame = new Level(nameDataBase);
    m_listCards = ManagerBdd::getInstance().loadDbFlashcard(nameDataBase);
}
