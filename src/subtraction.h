#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "calcul.h"

class Subtraction : public Calcul
{
    Q_OBJECT
public:
    explicit Subtraction();
    ~Subtraction();

    virtual Question* buildQuestion();

protected:
    virtual const QString getProposition()const;
    virtual const QString makeTextQuestion(QList<QString> values)const;

private:

signals:

public slots:
    virtual const QString getResult()const;

};

#endif // SUBTRACTION_H
