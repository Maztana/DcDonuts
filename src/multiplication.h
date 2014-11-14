#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "calcul.h"

class Multiplication : public Calcul
{
    Q_OBJECT
public:
    explicit Multiplication(Niveau* niveauDuJeu);
    ~Multiplication();

    virtual Question* getQuestion();

protected:
    void defNiveau();

signals:

public slots:

};

#endif // MULTIPLICATION_H
