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

    const QString getProposition()const;

protected:
    /** Min values list */
    QList<int> m_min_values;
    /** Max values list */
    QList<int> m_max_values;

    virtual void setNumberPropositions();

private:
    virtual void setLevelsSelectable();

signals:

public slots:

};

#endif // CALCUL_H
