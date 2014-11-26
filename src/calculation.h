#ifndef CALCULATION_H
#define CALCULATION_H

#include "educationalquiz.h"

class Calculation : public EducationalQuiz
{
    Q_OBJECT
public:
    explicit Calculation(Level* gameLevel);
    ~Calculation();

    virtual Question* buildQuestion() = 0;
    int getNbMax();
    int getNbMin();

protected:
    static int s_number_min;
    static int s_number_max;

    virtual void definitionLimitsForLevel() = 0;

signals:

public slots:

};

#endif // CALCULATION_H
