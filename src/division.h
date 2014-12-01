#ifndef DIVISION_H
#define DIVISION_H

#include "calcul.h"

class Division : public Calcul
{
    Q_OBJECT
public:
    explicit Division();
    ~Division();

    virtual Question* buildQuestion();

protected:
    virtual void definitionLimitsForLevel();

    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString getTextQuestion()const;

signals:

public slots:

};

#endif // DIVISION_H
