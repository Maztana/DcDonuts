#include "questionnaireeducatif.h"
#include <QTextStream>
#include <QThread>
#include "mainapplication.h"

QString QuestionnaireEducatif::MODE_JEU = "";


QuestionnaireEducatif::QuestionnaireEducatif(Niveau* niveauDuJeu):
    TypeDeJeu(niveauDuJeu)
{
    connect(this, SIGNAL(finishTraitResponse()), this, SLOT(lancerQuestion()));
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

const QString QuestionnaireEducatif::getColor()
{
    return colorResponse;
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

    emit newQuestion();
}

void QuestionnaireEducatif::traitResponse(QString response)
{
    //TODO
    int result = questionCourante->getResult();

    if(response.toInt() == result)
    {
        //Réponse correcte
        QTextStream(stdout) << "reponse juste " << result << endl;

        //mise en vert de la réponse
        colorResponse = "green";
        emit colorResponseChanged();

        //add point au profil
    }
    else
    {
        //Réponse fausse

        //mise en rouge de la réponse choisi
        colorResponse = "red";
        emit colorResponseChanged();

        QTextStream(stdout) << "reponse fausse " << response << endl;

        //mise en vert de la réponse vrai
        QTextStream(stdout) << "reponse vrai " << result << endl;
    }

    //QThread::sleep(5);

    colorResponse = "black";
    emit colorResponseChanged();

    //add stat question

    QTextStream(stdout) << "changement question" << endl;
    emit finishTraitResponse();
}
