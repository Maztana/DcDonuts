#include "multiplicationgamefactory.h"

/** Default consutructor
 * @brief MultiplicationGameFactory::MultiplicationGameFactory
 */
MultiplicationGameFactory::MultiplicationGameFactory()
{
}

/** Multiplication object creator
 * @brief MultiplicationGameFactory::makeSpecificGameType
 * @return Multiplication object
 */
Multiplication* MultiplicationGameFactory::makeSpecificGameType()
{
    return new Multiplication();
}
