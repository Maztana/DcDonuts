#ifndef DIVISION_H
#define DIVISION_H

#include "calcul.h"

class Division : public Calcul
{
    Q_OBJECT
public:
    explicit Division(Level* m_gameLevel);
    ~Division();

    virtual Question* buildQuestion();

protected:
    void definitionLimitsForLevel();

signals:

public slots:

};

#endif // DIVISION_H
