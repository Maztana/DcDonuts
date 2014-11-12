#include "addition.h"

Addition::Addition()
{
    MODE_JEU = "ADDITION";
}

Addition::~Addition()
{
}

Question* Addition::getQuestion()
{
    //Générer question
    int operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    int operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

    Question* maQuestion = new Question(MODE_JEU, operande1, operande2);

    return maQuestion;
}

void Addition::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 10;
}
