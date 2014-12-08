#ifndef MIXEDGAMEFACTORY_H
#define MIXEDGAMEFACTORY_H

#include "educationalquizfactory.h"
#include "mixededucationalquiz.h"

class MixedGameFactory : public EducationalQuizFactory
{

public:
    explicit MixedGameFactory();

    static MixedEducationalQuiz* makeSpecificGameType();

};

#endif // MIXEDGAMEFACTORY_H
