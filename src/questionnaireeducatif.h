#ifndef QUESTIONNAIREEDUCATIF_H
#define QUESTIONNAIREEDUCATIF_H

#include "typedejeu.h"
#include "question.h"

class QuestionnaireEducatif : public TypeDeJeu
{
    Q_OBJECT

    QList<Question*> questionsDonnees;
    Question* questionCourante;

public:
    explicit QuestionnaireEducatif(Niveau* niveauDuJeu);
    ~QuestionnaireEducatif();

    virtual Question* getQuestion() = 0;
    const QString& getModeJeu();

protected:
    virtual void defNiveau() = 0;
    static QString MODE_JEU;

signals:
    void envoiQuestion(Question*);

public slots:
    void lancerJeu(Niveau *niveauDuJeu);
    void lancerQuestion();

};

#endif // QUESTIONNAIREEDUCATIF_H
