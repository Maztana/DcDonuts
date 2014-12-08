#ifndef MULTIPLICATIONGAMEFACTORY_H
#define MULTIPLICATIONGAMEFACTORY_H

#include "educationalquizfactory.h"
#include "multiplication.h"

class MultiplicationGameFactory : public EducationalQuizFactory
{
public:
    MultiplicationGameFactory();

    static Multiplication* makeSpecificGameType();
};

#endif // MULTIPLICATIONGAMEFACTORY_H
