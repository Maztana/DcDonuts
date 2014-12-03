#include "subtractiongamefactory.h"

/** Default constructor
 * @brief SubtractionGameFactory::SubtractionGameFactory
 */
SubtractionGameFactory::SubtractionGameFactory()
{
}

/** Subtraction object creator
 * @brief SubtractionGameFactory::makeSpecificGameType
 * @return Subtraction object
 */
Subtraction* SubtractionGameFactory::makeSpecificGameType()
{
    return new Subtraction();
}
