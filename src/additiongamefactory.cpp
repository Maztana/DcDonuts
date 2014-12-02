#include "additiongamefactory.h"

AdditionGameFactory::AdditionGameFactory()
{
}

Addition* AdditionGameFactory::makeSpecificGameType()
{
    return new Addition();
}
