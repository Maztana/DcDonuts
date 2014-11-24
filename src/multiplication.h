#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "calculation.h"

class Multiplication : public Calculation
{
    Q_OBJECT
public:
    explicit Multiplication(Level* m_gameLevel);
    ~Multiplication();

    virtual Question* buildQuestion();

protected:
    void definitionLimitsForLevel();

signals:

public slots:

};

#endif // MULTIPLICATION_H
