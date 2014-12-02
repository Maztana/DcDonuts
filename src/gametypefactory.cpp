#include "gametypefactory.h"
#include "ressources.h"

#include "additiongamefactory.h"
#include "subtractiongamefactory.h"
#include "multiplicationgamefactory.h"
#include "divisiongamefactory.h"

GameTypeFactory::GameTypeFactory(QObject *parent) :
    QObject(parent)
{
}

/** Creator of different game type
 * @brief makeGameType
 * @param identifiantGameType
 * @return the specific game type
 */
GameType* GameTypeFactory::makeGameType(QList<int> identifiantsGameType)
{
    GameType* gameType = nullptr;
/*
    if(identifiantsGameType.size() > 1)
    {
        gameType = MixedGameFactory::makeSpecificGameType();
        for(int identifiant : identifiantsGameType)
        {
            mixedGame.addGameType(GameTypeFactory::makeGameType(identifiant));
        }
    }
    else
    {
*/
        switch (identifiantsGameType.first()) {
        case ADDITION_MODE:
            gameType = AdditionGameFactory::makeSpecificGameType();
            break;
        case SUBTRACTION_MODE:
            gameType = SubtractionGameFactory::makeSpecificGameType();
            break;
        case MULTIPLICATION_MODE:
            gameType = MultiplicationGameFactory::makeSpecificGameType();
            break;
        case DIVISION_MODE:
            gameType = DivisionGameFactory::makeSpecificGameType();
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
//    }
    return gameType;
}
