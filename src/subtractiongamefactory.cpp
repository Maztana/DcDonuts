#include "subtractiongamefactory.h"

SubtractionGameFactory::SubtractionGameFactory()
{
}

Subtraction* SubtractionGameFactory::makeSpecificGameType()
{
    return new Subtraction();
}
