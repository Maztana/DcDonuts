#include "questionnaireeducatif.h"
#include <QDebug>

QString QuestionnaireEducatif::MODE_JEU = "";


QuestionnaireEducatif::QuestionnaireEducatif()
{
}

QuestionnaireEducatif::~QuestionnaireEducatif()
{
    if(niveauDuJeu != 0)
    {
        delete(niveauDuJeu);
    }
}

void QuestionnaireEducatif::lancerJeu(Niveau *niveauDuJeu)
{
    setNiveau(niveauDuJeu);

    //Lancer interface de questionnaire
    lancerQuestion();
}

void QuestionnaireEducatif::lancerQuestion()
{
    questionCourante = this->getQuestion();

    //EMIT
    //envoiQuestion(questionCourante);
    // Envoi de la question vers l'interface //
    // TODO
}
