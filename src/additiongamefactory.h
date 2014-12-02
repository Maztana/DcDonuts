#ifndef ADDITIONGAMEFACTORY_H
#define ADDITIONGAMEFACTORY_H

#include "gametypefactory.h"
#include "addition.h"

class AdditionGameFactory : public GameTypeFactory
{
public:
    AdditionGameFactory();

    static Addition* makeSpecificGameType();
};

#endif // ADDITIONGAMEFACTORY_H
