#include "subtraction.h"
#include "ressources.h"

#include <QTextStream>

/** Constructor
 * @brief Subtraction::Subtraction
 * @param gameLevel the level game
 */
Subtraction::Subtraction(Level* gameLevel):
    Calculation(gameLevel)
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_SUBTRACTION;
}

/** Destructor
 * @brief Subtraction::~Subtraction
 */
Subtraction::~Subtraction()
{
}

Question* Subtraction::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    if(operande1 < operande2)
    {
        int tmp = operande1;
        operande1 = operande2;
        operande2 = tmp;
    }

    Question* maQuestion = new Question(MODE_SUBTRACTION, operande1, operande2);
    return maQuestion;
}

void Subtraction::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 9;
}
