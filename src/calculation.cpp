#include "calculation.h"
#include <QDateTime>

// Déclaration statique
int Calculation::s_number_max = 0;
int Calculation::s_number_min = 0;
///////////////////////

/** Constructor
 * @brief Calculation::Calculation
 * @param gameLevel level of the game
 */
Calculation::Calculation(Level* gameLevel) :
    EducationalQuiz(gameLevel)
{
    //qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Destructor
 * @brief Calculation::~Calculation
 */
Calculation::~Calculation()
{

}

/** Getter of max number limit
 * @brief Calculation::getNbMax
 * @return the limit up
 */
int Calculation::getNbMax()
{
    return s_number_max;
}

/** Getter of the min number limit
 * @brief Calculation::getNbMin
 * @return the limit down
 */
int Calculation::getNbMin()
{
    return s_number_min;
}
