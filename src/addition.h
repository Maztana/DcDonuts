#ifndef ADDITION_H
#define ADDITION_H

#include "calcul.h"

class Addition : public Calcul
{
    Q_OBJECT
public:
    explicit Addition();
    ~Addition();

    virtual Question* buildQuestion();

protected:
    virtual void definitionLimitsForLevel();

    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString getTextQuestion()const;

signals:

public slots:

};

#endif // ADDITION_H
