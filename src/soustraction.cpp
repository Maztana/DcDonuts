#include "soustraction.h"
#include "ressources.h"

Soustraction::Soustraction(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
    defNiveau();
    INCREMENTAL_SCORE = INCREMENTAL_SCORE_MULTIPLICATION;
}

Soustraction::~Soustraction()
{
}

Question* Soustraction::nextQuestion()
{
    //Générer question
    int operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    int operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

    Question* maQuestion = new Question(MODE_SOUSTRACTION, operande1, operande2);
    return maQuestion;
}

void Soustraction::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 9;
}
