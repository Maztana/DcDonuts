#ifndef TYPEDEJEU_H
#define TYPEDEJEU_H

#include <QObject>
#include "niveau.h"

class TypeDeJeu : public QObject
{
    Q_OBJECT

public:
    explicit TypeDeJeu(Niveau* niveauDuJeu);
    ~TypeDeJeu();

    const Niveau& getNiveau();
    virtual inline bool isQuestionnaire()const{return false;}
    static TypeDeJeu* makeTypeJeu(Niveau* niveauDeLaPartie, QString nameJeu);

protected:
    static int INCREMENTAL_SCORE;
    const Niveau *niveauDuJeu;

private:
    static TypeDeJeu* makeTypeCalcul(Niveau* niveauDeLaPartie, QString nameJeu);

signals:
    void incrementScore(int);

public slots:
    virtual void lancerJeu() = 0;

};

#endif // TYPEDEJEU_H
