#include "addition.h"
#include "ressources.h"


/** Constructor
 * @brief Addition::Addition
 * @param gameLevel the level of game
 */
Addition::Addition(Level* gameLevel):
    Calculation(gameLevel)
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_ADDITION;
}

/** Destructor
 * @brief Addition::~Addition
 */
Addition::~Addition()
{
}

Question* Addition::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    Question* maQuestion = new Question(MODE_ADDITION, operande1, operande2);
    return maQuestion;
}

void Addition::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 9;
}
