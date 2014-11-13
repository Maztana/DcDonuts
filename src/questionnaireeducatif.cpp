#include "questionnaireeducatif.h"
#include <QDebug>

QString QuestionnaireEducatif::MODE_JEU = "";


QuestionnaireEducatif::QuestionnaireEducatif(Niveau* niveauDuJeu):
    TypeDeJeu(niveauDuJeu)
{
}

QuestionnaireEducatif::~QuestionnaireEducatif()
{
}

const QString& QuestionnaireEducatif::getModeJeu()
{
    return MODE_JEU;
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
