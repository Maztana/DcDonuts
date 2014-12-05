#include "gametypefactory.h"
#include "ressources.h"

#include "mixedgamefactory.h"
#include "additiongamefactory.h"
#include "subtractiongamefactory.h"
#include "multiplicationgamefactory.h"
#include "divisiongamefactory.h"


/** Default constructor
 * @brief GameTypeFactory::GameTypeFactory
 * @param parent
 */
EducationalQuizFactory::EducationalQuizFactory(QObject *parent) :
    QObject(parent)
{
}

/** Creator of different game type
 * @brief makeGames
 * @param identifiantsGameType
 * @return the specific game type
 */
EducationalQuiz* EducationalQuizFactory::makeGames(QList<int> identifiantsGameType)
{
    EducationalQuiz* educationalQuiz = nullptr;

    if(identifiantsGameType.size() > 1)
    {
        MixedEducationalQuiz* mixedQuiz = MixedGameFactory::makeSpecificGameType();
        for(int identifiant : identifiantsGameType)
        {
            mixedQuiz->addGameType(EducationalQuizFactory::makeGameType(identifiant));
        }
        educationalQuiz = mixedQuiz;
    }
    else
    {
        educationalQuiz = EducationalQuizFactory::makeGameType(identifiantsGameType.first());
    }
    return educationalQuiz;
}

/** Creator of different game type
 * @brief makeGameType
 * @param identifiantGameType
 * @return the specific game type
 */
EducationalQuiz* EducationalQuizFactory::makeGameType(int identifiantGameType)
{
    EducationalQuiz* educationalQuiz = nullptr;

    switch (identifiantGameType) {
    case ADDITION_MODE:
        educationalQuiz = AdditionGameFactory::makeSpecificGameType();
        break;
    case SUBTRACTION_MODE:
        educationalQuiz = SubtractionGameFactory::makeSpecificGameType();
        break;
    case MULTIPLICATION_MODE:
        educationalQuiz = MultiplicationGameFactory::makeSpecificGameType();
        break;
    case DIVISION_MODE:
        educationalQuiz = DivisionGameFactory::makeSpecificGameType();
        break;
        ////////////////////////////////////////////////////////////
        /*
      case COUNTING_MODE:
        gameType = CountingGameFactory::makeSpecificGameType();
        break;
    case COLOR_MODE:
        gameType = ColorGameFactory::makeSpecificGameType();
        break;
    case FLASHCARD_MODE:
        gameType = FlashcardGameFactory::makeSpecificGameType();
        break;
        */
        //////////////////////////////////////////////////
    }
    return educationalQuiz;
}
