#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "calcul.h"

class Soustraction : public Calcul
{
    Q_OBJECT
public:
    explicit Soustraction();
    ~Soustraction();

    virtual Question* getQuestion();

protected:
    void defNiveau();

signals:

public slots:

};

#endif // SOUSTRACTION_H
