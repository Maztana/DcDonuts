#include "flashcard.h"

/** Constructor
 * @brief Flashcard::Flashcard
 * @param parent
 */
Flashcard::Flashcard() :
    EducationalQuiz()
{
    //setNumberPropositions();
}

/** Destructor
 * @brief Flashcard::~Flashcard
 */
Flashcard::~Flashcard()
{
}

/** Build a question of addition
 * @brief Flashcard::buildQuestion
 * @return addition's question
 */
Question* Flashcard::buildQuestion()
{
    // Load question with bdd
    //chargement de result et text question de flashcard
    //loadQuestion();
    QString result = "result flashcard";
    m_textQuestion = "Type flascard test!";

    Question* myQuestion = new Question({result}, makeTextQuestion({}));
    return myQuestion;
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
}
