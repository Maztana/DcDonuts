#ifndef COUNTINGMODE_H
#define COUNTINGMODE_H

#include "educationalquiz.h"

class CountingMode : public EducationalQuiz
{
    Q_OBJECT

public:
    explicit CountingMode();
    virtual ~CountingMode();

    virtual Question* buildQuestion();

    virtual const QString getProposition()const;
    virtual const QString makeTextQuestion(QList<QString> values)const;

protected:
    /** Min values list */
    QList<int> m_min_values;
    /** Max values list */
    QList<int> m_max_values;

    virtual void setNumberPropositions();

private:
    virtual void treatmentAnswer(const int indexAnswer);
    virtual void setLevelsSelectable();

public slots:
    virtual const QString getResult()const;
    virtual inline bool isCounting(){return true;}
};

#endif // COUNTINGMODE_H
