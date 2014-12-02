#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "calcul.h"

class Multiplication : public Calcul
{
    Q_OBJECT
public:
    explicit Multiplication();
    ~Multiplication();

    virtual Question* buildQuestion();

protected:
    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString getTextQuestion()const;

private:

signals:

public slots:

};

#endif // MULTIPLICATION_H
