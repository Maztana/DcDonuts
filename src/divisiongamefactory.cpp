#include "divisiongamefactory.h"

DivisionGameFactory::DivisionGameFactory()
{
}

Division* DivisionGameFactory::makeSpecificGameType()
{
    return new Division();
}
