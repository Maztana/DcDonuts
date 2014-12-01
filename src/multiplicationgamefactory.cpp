#include "multiplicationgamefactory.h"

MultiplicationGameFactory::MultiplicationGameFactory()
{
}

Multiplication* MultiplicationGameFactory::makeSpecificGameType()
{
    return new Multiplication();
}
