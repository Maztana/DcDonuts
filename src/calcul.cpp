#include "calcul.h"

// Déclaration statique
int Calcul::NB_MAX = 0;
int Calcul::NB_MIN = 0;
///////////////////////

Calcul::Calcul() :
    QuestionnaireEducatif()
{
}

Calcul::~Calcul()
{

}

int Calcul::getNbMax()
{
    return NB_MAX;
}

int Calcul::getNbMin()
{
    return NB_MIN;
}
