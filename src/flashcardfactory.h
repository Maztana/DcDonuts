#ifndef FLASHCARDFACTORY_H
#define FLASHCARDFACTORY_H

#include "educationalquizfactory.h"
#include "flashcard.h"

class FlashcardFactory : public EducationalQuizFactory
{

public:
    explicit FlashcardFactory();

    static Flashcard* makeSpecificGameType();

};

#endif // FLASHCARDFACTORY_H
