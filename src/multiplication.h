#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "calcul.h"

class Multiplication : public Calcul
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
