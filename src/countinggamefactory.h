#ifndef COUNTINGGAMEFACTORY_H
#define COUNTINGGAMEFACTORY_H

#include "educationalquizfactory.h"
#include "countingmode.h"

class CountingGameFactory : public EducationalQuizFactory
{
public:
    CountingGameFactory();

    static CountingMode* makeSpecificGameType();
};

#endif // COUNTINGGAMEFACTORY_H
