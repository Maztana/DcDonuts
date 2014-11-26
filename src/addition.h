#ifndef ADDITION_H
#define ADDITION_H

#include "calcul.h"

class Addition : public Calcul
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
