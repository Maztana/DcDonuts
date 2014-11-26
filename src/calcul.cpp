#include "calcul.h"
#include <QDateTime>

// Déclaration statique
int Calcul::s_number_max = 0;
int Calcul::s_number_min = 0;
///////////////////////

/** Constructor
 * @brief Calcul::Calcul
 * @param gameLevel level of the game
 */
Calcul::Calcul(Level* gameLevel) :
    EducationalQuiz(gameLevel)
{
    //qsrand(QDateTime::currentDateTime().toTime_t());
}

/** Destructor
 * @brief Calcul::~Calcul
 */
Calcul::~Calcul()
{

}

/** Getter of max number limit
 * @brief Calcul::getNbMax
 * @return the limit up
 */
int Calcul::getNbMax()
{
    return s_number_max;
}

/** Getter of the min number limit
 * @brief Calcul::getNbMin
 * @return the limit down
 */
int Calcul::getNbMin()
{
    return s_number_min;
}
