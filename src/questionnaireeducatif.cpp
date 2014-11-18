#include "questionnaireeducatif.h"
#include <QTextStream>
#include <QtQml>
#include <QThread>
#include "mainapplication.h"

QString QuestionnaireEducatif::MODE_JEU = "";
int QuestionnaireEducatif::NB_PROPOSITIONS = 4;


QuestionnaireEducatif::QuestionnaireEducatif(Niveau* niveauDuJeu):
    TypeDeJeu(niveauDuJeu)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

QuestionnaireEducatif::~QuestionnaireEducatif()
{
    questionCourante = NULL;
    qDeleteAll(questionsDonnees);
}

const QString QuestionnaireEducatif::getProposition1()
{
    return QString::number(listProposition.at(0));
}

const QString QuestionnaireEducatif::getProposition2()
{
    return QString::number(listProposition.at(1));
}

const QString QuestionnaireEducatif::getProposition3()
{
    return QString::number(listProposition.at(2));
}

const QString QuestionnaireEducatif::getProposition4()
{
    return QString::number(listProposition.at(3));
}

Question* QuestionnaireEducatif::getCurrentQuestion()
{
    return questionCourante;
}

const QString& QuestionnaireEducatif::getModeJeu()
{
    return MODE_JEU;
}

void QuestionnaireEducatif::setListProposition()
{
    listProposition.clear();

    int result = questionCourante->getResult();
    int propo = questionCourante->getResult();

    int index = qrand() % ((NB_PROPOSITIONS) - 0) + 0;

    for(int i=1; i < NB_PROPOSITIONS; i++)
    {
        while(propo == result || listProposition.contains(propo))
        {
            propo = questionCourante->getProposition();
        }
        listProposition.append(propo);
    }
    listProposition.insert(index, result);
}

void QuestionnaireEducatif::lancerJeu()
{
    //Lancer interface de questionnaire
    lancerQuestion();
}

void QuestionnaireEducatif::lancerQuestion()
{
    emit responseTrait();

    questionCourante = this->nextQuestion();
    questionsDonnees.append(questionCourante);
    MainApplication::q_view->rootContext()->setContextProperty("question", questionCourante);

    setListProposition();
    newQuestion();
}

void QuestionnaireEducatif::newQuestion()
{
    emit proposition1Changed();
    emit proposition2Changed();
    emit proposition3Changed();
    emit proposition4Changed();
}

void QuestionnaireEducatif::traitResponse(int indexResponse)
{
    emit responseTrait();

    listResetColor.clear();
    int result = questionCourante->getResult();
    int indexResult = listProposition.indexOf(result);

    //Gestion du résultat
    if(listProposition.at(indexResponse-1) == result)
    {
        //Réponse correcte
        emit responseTrue(indexResponse);

        //add point au profil
    }
    else
    {
        //Réponse fausse
        emit responseFalse(indexResponse);
        emit responseTrue(indexResult + 1);

        listResetColor.append(indexResult + 1);
    }

    listResetColor.append(indexResponse);
    //add stat question
}

void QuestionnaireEducatif::responseReset()
{
    for(int index : listResetColor)
    {
        emit resetResponse(index);
    }
}
