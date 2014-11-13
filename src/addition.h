#ifndef ADDITION_H
#define ADDITION_H

#include "calcul.h"

class Addition : public Calcul
{
    Q_OBJECT
public:
    explicit Addition(Niveau* niveauDuJeu);
    ~Addition();

    virtual Question* getQuestion();

protected:
    virtual void defNiveau();

signals:

public slots:

};

#endif // ADDITION_H
