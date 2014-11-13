#ifndef QUESTIONNAIREEDUCATIF_H
#define QUESTIONNAIREEDUCATIF_H

#include "typedejeu.h"
#include "question.h"

class QuestionnaireEducatif : public TypeDeJeu
{
    Q_OBJECT

    Q_PROPERTY(QString question READ getQuestion)
    Q_PROPERTY(QString result READ getResultQuestion)
    Q_PROPERTY(QString proposition READ getPropositionQuestion)

    QList<Question*> questionsDonnees;
    Question* questionCourante;

public:
    explicit QuestionnaireEducatif(Niveau* niveauDuJeu);
    ~QuestionnaireEducatif();

    virtual inline bool isQuestionnaire()const{return true;}

    const QString getLibelleQuestion();
    const QString getResultQuestion();
    const QString getPropositionQuestion();

    virtual Question* getQuestion() = 0;
    Question* getCurrentQuestion();
    const QString& getModeJeu();

protected:
    static QString MODE_JEU;

signals:
    void envoiQuestion(Question*);

public slots:
    void lancerJeu();
    void lancerQuestion();
    void verifyResponse(QString response);

};

#endif // QUESTIONNAIREEDUCATIF_H
