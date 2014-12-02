#ifndef SUBTRACTIONGAMEFACTORY_H
#define SUBTRACTIONGAMEFACTORY_H

#include "gametypefactory.h"
#include "subtraction.h"

class SubtractionGameFactory : public GameTypeFactory
{
public:
    SubtractionGameFactory();


    static Subtraction* makeSpecificGameType();
};

#endif // SUBTRACTIONGAMEFACTORY_H
