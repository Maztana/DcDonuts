#ifndef ADDITIONGAMEFACTORY_H
#define ADDITIONGAMEFACTORY_H

#include "educationalquizfactory.h"
#include "addition.h"

class AdditionGameFactory : public EducationalQuizFactory
{
public:
    AdditionGameFactory();

    static Addition* makeSpecificGameType();
};

#endif // ADDITIONGAMEFACTORY_H
