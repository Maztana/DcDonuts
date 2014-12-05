#include "mixedgamefactory.h"

/** Default consutructor
 * @brief MixedGameFactory::MultiplicationGameFactory
 */
MixedGameFactory::MixedGameFactory()
{
}

/** Mixed object creator
 * @brief MixedGameFactory::makeSpecificGameType
 * @return Mixed object
 */
MixedEducationalQuiz* MixedGameFactory::makeSpecificGameType()
{
    return new MixedEducationalQuiz();
}
