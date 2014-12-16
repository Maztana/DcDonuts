#include "flashcard.h"
#include "managerbdd.h"

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
    /*QTextStream(stdout)<< "dans le build" <<endl;

    QTextStream(stdout)<< s_cpt <<endl;

    QList<Question*> cards;
    int randomIndex;

    if(s_cpt != 5){

        cards = ManagerBdd::getInstance().getFirstCards();

        randomIndex = rollDice(0, cards.size()-1);
        m_idQuestion = cards.at(randomIndex)->getId();

        s_cpt++;

    } else{

        cards = ManagerBdd::getInstance().getOldCards();

        randomIndex = rollDice(0, cards.size()-1);
        m_idQuestion = cards.at(randomIndex)->getId();

        s_cpt = 1;
    }

    return cards.at(randomIndex);*/

    QTextStream(stdout)<< "dans le build" <<endl;

    QList<Question*> cards = ManagerBdd::getInstance().getFirstCards();
    int randomIndex = rollDice(0, cards.size()-1);
    return cards.at(randomIndex);


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
