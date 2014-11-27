#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "calcul.h"

class Subtraction : public Calcul
{
    Q_OBJECT
public:
    explicit Subtraction(Level* gameLevel);
    ~Subtraction();

    virtual Question* buildQuestion();

protected:
    void definitionLimitsForLevel();

signals:

public slots:

};

#endif // SUBTRACTION_H
