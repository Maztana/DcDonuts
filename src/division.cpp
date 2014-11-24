#include "division.h"
#include "ressources.h"


/** Constructor
 * @brief Division::Division
 * @param gameLevel the level of game
 */
Division::Division(Level* gameLevel):
    Calculation(gameLevel)
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_DIVISION;
}

/** Destructor
 * @brief Division::~Division
 */
Division::~Division()
{
}

Question* Division::buildQuestion()
{
    //Générer question
    int operande1 = 0;
    int operande2 = 0;
    int mod = 1;
    while(mod != 0)
    {
        operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
        operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

        if(operande1 == 0 && operande2 == 0)
        {
            mod = 1;
        }
        else
        {
            if(operande1 < operande2)
            {
                int tmp = operande1;
                operande1 = operande2;
                operande2 = tmp;
            }
            mod = operande1 % operande2;
        }
    }

    Question* maQuestion = new Question(MODE_DIVISION, operande1, operande2);
    return maQuestion;
}

void Division::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 9;
}
