#include "addition.h"
#include "ressources.h"

Addition::Addition(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
    defNiveau();
    INCREMENTAL_SCORE = INCREMENTAL_SCORE_ADDITION;
}

Addition::~Addition()
{
}

Question* Addition::nextQuestion()
{
    //Générer question
    int operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    int operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

    Question* maQuestion = new Question(MODE_ADDITION, operande1, operande2);
    return maQuestion;
}

void Addition::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 9;
}
