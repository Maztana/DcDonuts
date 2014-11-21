#include "multiplication.h"
#include "Ressources.h"

Multiplication::Multiplication(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
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

    Question* maQuestion = new Question(MODE_MULTIPLICATION, operande1, operande2);

    return maQuestion;
}

void Multiplication::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 9;
}
