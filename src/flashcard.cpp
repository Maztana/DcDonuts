#include "flashcard.h"
#include "managerbdd.h"
#include "game.h"

int Flashcard::s_cpt = 1;

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
    QList<Question*> cards;
    int randomIndex;

    if(s_cpt != 5)
	{
        cards = ManagerBdd::getInstance().getFirstCards(Game::getIdCurrentProfile());

        randomIndex = rollDice(0, cards.size()-1);
        m_idQuestion = cards.at(randomIndex)->getId();

        s_cpt++;
    } 
	else
	{
        cards = ManagerBdd::getInstance().getOldCards(Game::getIdCurrentProfile());

        randomIndex = rollDice(0, cards.size()-1);
        m_idQuestion = cards.at(randomIndex)->getId();

        s_cpt = 1;
    }
    return cards.at(randomIndex);
}

/** Treat response for flashcard
 * @brief Flashcard::treatmentAnswer
 * @param indexAnswer the index of answer
 */
void Flashcard::treatmentAnswer(const int answer)
{
    emit answerGiven();

    ManagerBdd::getInstance().saveResultFlashcard(m_idQuestion, answer, Game::getIdCurrentProfile());
    launchQuestion();
}

/** Init and load the Db cards
 * @brief Flashcard::initDB
 * @param nameDataBase name of data base
 */
void Flashcard::initDB(QString url, QString name)
{
    m_levelGame = new Level(name);
    ManagerBdd::getInstance().openDBFlashcard(url);
    ManagerBdd::getInstance().initLearnTable(Game::getIdCurrentProfile());
}
