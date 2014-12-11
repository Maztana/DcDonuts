#include "flashcardfactory.h"

FlashcardFactory::FlashcardFactory() :
    EducationalQuizFactory()
{
}

/** Addition object creator
 * @brief FlashcardFactory::makeSpecificGameType
 * @return Addition object
 */
Flashcard* FlashcardFactory::makeSpecificGameType()
{
    return new Flashcard();
}
