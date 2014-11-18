#include "questionnaireeducatif.h"
#include <QTextStream>
#include <QThread>
#include "mainapplication.h"

QString QuestionnaireEducatif::MODE_JEU = "";
int QuestionnaireEducatif::NB_PROPOSITIONS = 4;
QString QuestionnaireEducatif::COLOR_INIT = "black";
QString QuestionnaireEducatif::COLOR_SELECTION = "blue";
QString QuestionnaireEducatif::COLOR_TRUE = "green";
QString QuestionnaireEducatif::COLOR_FALSE = "red";


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

const QString QuestionnaireEducatif::getColor1()
{
    return color1;
}

const QString QuestionnaireEducatif::getColor2()
{
    return color2;
}

const QString QuestionnaireEducatif::getColor3()
{
    return color3;
}

const QString QuestionnaireEducatif::getColor4()
{
    return color4;
}

void QuestionnaireEducatif::setColor1(QString color)
{
    color1 = color;
    emit color1Changed();
}

void QuestionnaireEducatif::setColor2(QString color)
{
    color2 = color;
    emit color2Changed();
}

void QuestionnaireEducatif::setColor3(QString color)
{
    color3 = color;
    emit color3Changed();
}

void QuestionnaireEducatif::setColor4(QString color)
{
    color4 = color;
    emit color4Changed();
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
    questionCourante = this->getQuestion();
    questionsDonnees.append(questionCourante);

    setListProposition();
    newQuestion();
}

void QuestionnaireEducatif::newQuestion()
{
    emit libelleQuestionChanged();
    emit proposition1Changed();
    emit proposition2Changed();
    emit proposition3Changed();
    emit proposition4Changed();
}

void QuestionnaireEducatif::setColor(int index, QString color)
{
    switch (index) {
    case 0:
        setColor1(color);
        break;
    case 1:
        setColor2(color);
        break;
    case 2:
        setColor3(color);
        break;
    case 3:
        setColor4(color);
        break;
    }
}

void QuestionnaireEducatif::traitResponse(QString response)
{
    int result = questionCourante->getResult();
    int indexRep = listProposition.indexOf(response.toInt());
    int indexResult = listProposition.indexOf(result);

    //Gestion de la sélection
    setColor(indexRep, COLOR_SELECTION);

    //Gestion du résultat
    if(response.toInt() == result)
    {
        //Réponse correcte
        setColor(indexRep, COLOR_TRUE);

        //add point au profil
        emit incrementScore(1);
    }
    else
    {
        //Réponse fausse
        setColor(indexRep, COLOR_FALSE);
        setColor(indexResult, COLOR_TRUE);

        setColor(indexResult, COLOR_INIT);
    }

    setColor(indexRep, COLOR_INIT);

    //add stat question


    emit finishTraitResponse();
}
