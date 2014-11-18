#include "multiplication.h"

Multiplication::Multiplication(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
    MODE_JEU = "MULTIPLICATION";
    defNiveau();
}

Multiplication::~Multiplication()
{
}

Question* Multiplication::nextQuestion()
{
    //Générer question
    int operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    int operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

    Question* maQuestion = new Question(MODE_JEU, operande1, operande2);

    return maQuestion;
}

void Multiplication::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 9;
}
