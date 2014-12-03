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

protected:
    /** Min values list */
    static QList<int> s_min_values;
    /** Max values list */
    static QList<int> s_max_values;

    int rollDice(int nbMin, int nbMax)const;
    virtual void treatmentAnswer(const int indexAnswer);

private:
    virtual void setNumberPropositions(int indexLevel);
    virtual void setLevelsSelectable();

signals:

public slots:

};

#endif // CALCUL_H
