#ifndef DIVISION_H
#define DIVISION_H

#include "calcul.h"

class Division : public Calcul
{
    Q_OBJECT
public:
    explicit Division(Niveau* niveauDuJeu);
    ~Division();

    virtual Question* nextQuestion();

protected:
    void defNiveau();

signals:

public slots:

};

#endif // DIVISION_H
