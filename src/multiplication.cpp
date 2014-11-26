#include "multiplication.h"
#include "ressources.h"


/** Constructor
 * @brief Multiplication::Multiplication
 * @param gameLevel the level of game
 */
Multiplication::Multiplication(Level* gameLevel):
    Calcul(gameLevel)
{
    definitionLimitsForLevel();
    s_incremental_score = INCREMENTAL_SCORE_MULTIPLICATION;
}

/** Destructor
 * @brief Multiplication::~Multiplication
 */
Multiplication::~Multiplication()
{
}

Question* Multiplication::buildQuestion()
{
    //Générer question
    int operande1 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;
    int operande2 = qrand() % ((s_number_max + 1) - s_number_min) + s_number_min;

    QList<QString> listValues;
    listValues.append(QString::number(operande1));
    listValues.append(QString::number(operande2));

    Question* maQuestion = new Question(MODE_MULTIPLICATION, listValues);
    return maQuestion;
}

void Multiplication::definitionLimitsForLevel()
{
    s_number_min = 0;
    s_number_max = 9;
}
