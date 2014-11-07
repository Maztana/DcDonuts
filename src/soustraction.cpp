#include "soustraction.h"

Soustraction::Soustraction()
{
    MODE_JEU = "SOUSTRACTION";
}

Soustraction::~Soustraction()
{
}

Question* Soustraction::getQuestion()
{
    //Générer question
    int operande1 = 0;
    int operande2 = 0;
    while(operande1 == operande2)
    {
        operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
        operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    }

    Question* maQuestion = new Question(MODE_JEU, operande1, operande2);

    return maQuestion;
}

void Soustraction::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 10;
}
