#ifndef CALCUL_H
#define CALCUL_H

#include "questionnaireeducatif.h"

class Calcul : public QuestionnaireEducatif
{
    Q_OBJECT
public:
    explicit Calcul(Niveau* niveauDuJeu);
    ~Calcul();

    virtual Question* nextQuestion() = 0;
    int getNbMax();
    int getNbMin();

protected:
    static int NB_MIN;
    static int NB_MAX;

    virtual void defNiveau() = 0;

signals:
    void envoiQuestion(Question*);
    void envoiReponse(int reponse);
    void envoiProposition(QList<int> proposition);

public slots:

};

#endif // CALCUL_H
