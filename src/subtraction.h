#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "calculation.h"

class Subtraction : public Calculation
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

#endif // SOUSTRACTION_H
