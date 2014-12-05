#ifndef DIVISIONGAMEFACTORY_H
#define DIVISIONGAMEFACTORY_H

#include "gametypefactory.h"
#include "division.h"

class DivisionGameFactory : public EducationalQuizFactory
{
public:
    DivisionGameFactory();

    static Division* makeSpecificGameType();
};

#endif // DIVISIONGAMEFACTORY_H
