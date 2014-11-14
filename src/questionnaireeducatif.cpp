#include "questionnaireeducatif.h"
#include <QTextStream>
#include <QThread>
#include "mainapplication.h"

QString QuestionnaireEducatif::MODE_JEU = "";
int QuestionnaireEducatif::NB_PROPOSITIONS = 4;


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
/*
void QuestionnaireEducatif::setColor1(QString color)
{
    //color1 = color;
    emit color1Changed();
}

void QuestionnaireEducatif::setColor2(QString color)
{
    //color2 = color;
    emit color2Changed();
}

void QuestionnaireEducatif::setColor3(QString color)
{
    //color3 = color;
    emit color3Changed();
}

void QuestionnaireEducatif::setColor4(QString color)
{
    //color4 = color;
    emit color4Changed();
}
*/
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

void QuestionnaireEducatif::traitResponse(QString response)
{
    //TODO
    int result = questionCourante->getResult();

    if(response.toInt() == result)
    {
        //Réponse correcte
        QTextStream(stdout) << "reponse juste " << result << endl;

        //mise en vert de la réponse
        //setColor("green");
        //add point au profil
    }
    else
    {
        //Réponse fausse

        //mise en rouge de la réponse choisi
        //setColor("red");

        QTextStream(stdout) << "reponse fausse " << response << endl;

        //mise en vert de la réponse vrai
        QTextStream(stdout) << "reponse vrai " << result << endl;
    }

    //QThread::sleep(5);

    //setColor("black");

    //add stat question

    QTextStream(stdout) << "changement question" << endl;
    emit finishTraitResponse();
}
