#ifndef QUESTIONNAIREEDUCATIF_H
#define QUESTIONNAIREEDUCATIF_H

#include "typedejeu.h"
#include "question.h"

class QuestionnaireEducatif : public TypeDeJeu
{
    Q_OBJECT

    Q_PROPERTY(QString proposition1 READ getProposition1 NOTIFY proposition1Changed)
    Q_PROPERTY(QString proposition2 READ getProposition2 NOTIFY proposition2Changed)
    Q_PROPERTY(QString proposition3 READ getProposition3 NOTIFY proposition3Changed)
    Q_PROPERTY(QString proposition4 READ getProposition4 NOTIFY proposition4Changed)


    QList<int> listProposition;
    QList<Question*> questionsDonnees;
    Question* questionCourante;

    QList<int> listResetColor;


public:
    explicit QuestionnaireEducatif(Niveau* niveauDuJeu);
    ~QuestionnaireEducatif();

    virtual inline bool isQuestionnaire()const{return true;}

    const QString getProposition1();
    const QString getProposition2();
    const QString getProposition3();
    const QString getProposition4();

    virtual Question* nextQuestion() = 0;
    Question* getCurrentQuestion();
    const QString& getModeJeu();

protected:
    static QString MODE_JEU;
    static int NB_PROPOSITIONS;

private:
    void setListProposition();

signals:
    void proposition1Changed();
    void proposition2Changed();
    void proposition3Changed();
    void proposition4Changed();

    void responseTrait();
    void responseTrue(int index);
    void responseFalse(int index);
    void resetResponse(int index);

public slots:
    void lancerJeu();
    void lancerQuestion();
    void newQuestion();
    void traitResponse(int indexResponse);
    void responseReset();

};

#endif // QUESTIONNAIREEDUCATIF_H
