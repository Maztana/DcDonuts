#include "additiongamefactory.h"

/** Constructor
 * @brief AdditionGameFactory::AdditionGameFactory
 */
AdditionGameFactory::AdditionGameFactory()
{
}

/** Addition object creator
 * @brief AdditionGameFactory::makeSpecificGameType
 * @return Addition object
 */
Addition* AdditionGameFactory::makeSpecificGameType()
{
    return new Addition();
}
