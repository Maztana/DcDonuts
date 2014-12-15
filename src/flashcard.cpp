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
    ManagerBdd::getInstance().closeDBFlashcard();
}

/** Build a flashcard question
 * @brief Flashcard::buildQuestion
 * @return flashcard's question
 */
Question* Flashcard::buildQuestion()
{
    QList<Question*> firstCards = ManagerBdd::getInstance().getFirstCards();

    int randomIndex = rollDice(0, firstCards.size()-1);
    m_idQuestion = firstCards.at(randomIndex)->getId();

    return firstCards.at(randomIndex);
}

/** Treat response for flashcard
 * @brief Flashcard::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void Flashcard::treatmentAnswer(const int answer)
{
    emit answerGiven();

    ManagerBdd::getInstance().saveResultFlashcard(m_idQuestion, answer);
    launchQuestion();

}

/** Init and load the Db cards
 * @brief Flashcard::initDB
 * @param nameDataBase name of data base
 */
void Flashcard::initDB(QString nameDataBase)
{
    m_levelGame = new Level(nameDataBase);
    ManagerBdd::getInstance().openDBFlashcard(nameDataBase);
    ManagerBdd::getInstance().initLearnTable();
}
