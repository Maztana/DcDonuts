#ifndef MULTIPLICATIONGAMEFACTORY_H
#define MULTIPLICATIONGAMEFACTORY_H

#include "gametypefactory.h"
#include "multiplication.h"

class MultiplicationGameFactory : public GameTypeFactory
{
public:
    MultiplicationGameFactory();

    static Multiplication* makeSpecificGameType();
};

#endif // MULTIPLICATIONGAMEFACTORY_H
