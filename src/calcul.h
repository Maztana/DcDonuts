#ifndef CALCUL_H
#define CALCUL_H

#include "questionnaireeducatif.h"

class Calcul : public QuestionnaireEducatif
{
    Q_OBJECT
public:
    explicit Calcul();
    ~Calcul();

    virtual Question* getQuestion() = 0;

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


//////////////////////////////ALGO GENERATEUR ADDITION ET SOUSTRACTION////////////////////////////////////////////////////////
/*
 *              Random de deux chiffres entre 0 et NB-MAX
 *
 *              si la réponse < 0 on inverse les chiffres
 *
 *              renvoi de la question et du résultat
 *
 *              envoi de 1 à 3 autres réponses comprise entre [ chiffreMin et ChiffreMax + (chiffreMin x2)]
 *                                                      exclu de la valeur résultat
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
