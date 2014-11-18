#include "addition.h"

#include <QTextStream>

Addition::Addition(Niveau* niveauDuJeu):
    Calcul(niveauDuJeu)
{
    MODE_JEU = "ADDITION";
    defNiveau();
}

Addition::~Addition()
{
}

Question* Addition::nextQuestion()
{
    //Générer question
    int operande1 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;
    int operande2 = qrand() % ((NB_MAX + 1) - NB_MIN) + NB_MIN;

    Question* maQuestion = new Question(MODE_JEU, operande1, operande2);


    QTextStream(stdout) << "ope1 -> " << operande1 << endl;
    QTextStream(stdout) << "ope2 -> " << operande2 << endl;

    return maQuestion;
}

void Addition::defNiveau()
{
    NB_MIN = 0;
    NB_MAX = 10;
}
