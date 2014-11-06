#ifndef QUESTIONNAIREEDUCATIF_H
#define QUESTIONNAIREEDUCATIF_H

#include "typedejeu.h"
#include "question.h"

class QuestionnaireEducatif : public TypeDeJeu
{
    Q_OBJECT

    QList<Question> questionsDonnees;

public:
    explicit QuestionnaireEducatif();

    virtual Question* getQuestion() = 0;

signals:

public slots:
    void lancerJeu(Niveau *niveauDuJeu);

};

#endif // QUESTIONNAIREEDUCATIF_H
