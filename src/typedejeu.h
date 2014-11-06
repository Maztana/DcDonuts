#ifndef TYPEDEJEU_H
#define TYPEDEJEU_H

#include <QObject>
#include "niveau.h"

class TypeDeJeu : public QObject
{
    Q_OBJECT

public:
    explicit TypeDeJeu();

protected:
    Niveau *niveauDuJeu;

protected:
    void setNiveau(Niveau *newNiveau);

signals:

public slots:
    virtual void lancerJeu(Niveau *niveauDuJeu) = 0;

};

#endif // TYPEDEJEU_H
