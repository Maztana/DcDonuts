#include "divisiongamefactory.h"

/** Constructor
 * @brief DivisionGameFactory::DivisionGameFactory
 */
DivisionGameFactory::DivisionGameFactory()
{
}

/** Division object creator
 * @brief DivisionGameFactory::makeSpecificGameType
 * @return division object
 */
Division* DivisionGameFactory::makeSpecificGameType()
{
    return new Division();
}
