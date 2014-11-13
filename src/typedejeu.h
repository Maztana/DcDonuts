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

protected:
    Niveau *niveauDuJeu;

    void setNiveau(Niveau *newNiveau);

signals:

public slots:
    virtual void lancerJeu() = 0;

};

#endif // TYPEDEJEU_H
