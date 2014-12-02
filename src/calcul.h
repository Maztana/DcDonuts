#ifndef CALCUL_H
#define CALCUL_H

#include "educationalquiz.h"

class Calcul : public EducationalQuiz
{
    Q_OBJECT
public:
    explicit Calcul();
    virtual ~Calcul();

    virtual Question* buildQuestion() = 0;
    int getNbMax();
    int getNbMin();

protected:
    static int s_number_min;
    static int s_number_max;

    virtual void definitionLimitsForLevel() = 0;
    int rollDice(int nbMin, int nbMax)const;

signals:

public slots:

};

#endif // CALCUL_H
