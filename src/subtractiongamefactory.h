#ifndef SUBTRACTIONGAMEFACTORY_H
#define SUBTRACTIONGAMEFACTORY_H

#include "educationalquizfactory.h"
#include "subtraction.h"

class SubtractionGameFactory : public EducationalQuizFactory
{
public:
    SubtractionGameFactory();


    static Subtraction* makeSpecificGameType();
};

#endif // SUBTRACTIONGAMEFACTORY_H
