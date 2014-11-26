#ifndef ADDITION_H
#define ADDITION_H

#include "calculation.h"

class Addition : public Calculation
{
    Q_OBJECT
public:
    explicit Addition(Level* m_gameLevel);
    ~Addition();

    virtual Question* buildQuestion();

protected:
    virtual void definitionLimitsForLevel();

signals:

public slots:

};

#endif // ADDITION_H
