#include "division.h"
#include "ressources.h"

Division::Division(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
    defNiveau();
    INCREMENTAL_SCORE = INCREMENTAL_SCORE_DIVISION;
}

Division::~Division()
{
}

Question* Division::nextQuestion()
{
    //Générer question
    int operande1 = 0;
    int operande2 = 0;
    int mod = 1;
    while(mod != 0)
    {
        operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
        operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

        if(operande1 == 0 && operande2 == 0)
        {
            mod = 1;
        }
        else
        {
            if(operande1 < operande2)
            {
                int tmp = operande1;
                operande1 = operande2;
                operande2 = tmp;
            }
            mod = operande1 % operande2;
        }
    }

    Question* maQuestion = new Question(MODE_DIVISION, operande1, operande2);
    return maQuestion;
}

void Division::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 9;
}
