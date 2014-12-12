#include "countinggamefactory.h"

CountingGameFactory::CountingGameFactory():
    EducationalQuizFactory()
{
}

/** Division object creator
 * @brief CountingGameFactory::makeSpecificGameType
 * @return division object
 */
CountingMode* CountingGameFactory::makeSpecificGameType()
{
    return new CountingMode();
}
