#ifndef DIVISION_H
#define DIVISION_H

#include "calcul.h"

class Division : public Calcul
{
    Q_OBJECT
public:
    explicit Division();
    ~Division();

    virtual Question* getQuestion();

protected:
    void defNiveau();

signals:

public slots:

};

#endif // DIVISION_H
