#include "questionnaireeducatif.h"
#include <QTextStream>

QString QuestionnaireEducatif::MODE_JEU = "";


QuestionnaireEducatif::QuestionnaireEducatif(Niveau* niveauDuJeu):
    TypeDeJeu(niveauDuJeu)
{
}

QuestionnaireEducatif::~QuestionnaireEducatif()
{
    qDeleteAll(questionsDonnees);
    questionCourante = NULL;
}

const QString QuestionnaireEducatif::getLibelleQuestion()
{
    return getCurrentQuestion()->toString();
}

const QString QuestionnaireEducatif::getResultQuestion()
{
    return QString::number(getCurrentQuestion()->getResult());
}

const QString QuestionnaireEducatif::getPropositionQuestion()
{
    return QString::number(getCurrentQuestion()->getProposition());
}

Question* QuestionnaireEducatif::getCurrentQuestion()
{
    return questionCourante;
}

const QString& QuestionnaireEducatif::getModeJeu()
{
    return MODE_JEU;
}

void QuestionnaireEducatif::lancerJeu()
{
    //Lancer interface de questionnaire
    lancerQuestion();
}

void QuestionnaireEducatif::lancerQuestion()
{
    questionCourante = this->getQuestion();
    questionsDonnees.append(questionCourante);

    //EMIT
    //envoiQuestion(questionCourante);
    // Envoi de la question vers l'interface //
    // TODO
}

void QuestionnaireEducatif::verifyResponse(QString response)
{
    //TODO
    QTextStream(stdout) << "l'appel marche" << endl;
}
