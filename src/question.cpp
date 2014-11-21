#include "question.h"
#include "ressources.h"

#include <QTextStream>
#include <QDateTime>

Question::Question(const QString& mode, int operande1, int operande2) :
    QObject(0), mode(mode)
{
    qsrand(QDateTime::currentDateTime().toTime_t());

    //tri des operandes!
    this->operande1 = operande1;
    this->operande2 = operande2;

    if(!mode.compare(MODE_SOUSTRACTION))
    {
        if(operande1 < operande2)
        {
            this->operande1 = operande2;
            this->operande2 = operande1;
        }
    }
}

int Question::getResult()const
{
    int result = 0;

    if(!mode.compare(MODE_ADDITION))
    {
        result = operande1 + operande2;
    }
    else if (!mode.compare(MODE_SOUSTRACTION))
    {
        result = operande1 - operande2;
    }
    else if(!mode.compare(MODE_DIVISION))
    {
        result = operande1 / operande2;
    }
    else if(!mode.compare(MODE_MULTIPLICATION))
    {
        result = operande1 * operande2;
    }

    return result;
}

int Question::getProposition()const
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///         REVOIR LES RANDOMS DE CHAQUE PROPOSITION
    ///
    /////////////////////////////////////////////////////////////////////////////////////
    int propo = 0;
    int nbMin = 0;
    int nbMax = 0;
    bool isRandomable = false;

    if(!mode.compare(MODE_ADDITION))
    {
        nbMax = operande1 + 3 +(operande2*2);
        nbMin = operande2-operande1;
        isRandomable = true;
    }
    else if (!mode.compare(MODE_SOUSTRACTION))
    {
        nbMax = operande1 + 3;
        nbMin = operande1- 3 - (operande2*2);
        isRandomable = true;
    }
    else if(!mode.compare(MODE_DIVISION))
    {
        nbMax = qrand() % (((operande1 + 1) + 1) - (operande1 - 1)) + (operande1 - 1);
        nbMin = qrand() % (((operande2 + 1) + 1) - (operande2 - 1)) + (operande2 - 1);
    }
    else if(!mode.compare(MODE_MULTIPLICATION))
    {
        nbMax = qrand() % (((operande1 + 1) + 1) - (operande1 - 1)) + (operande1 - 1);
        nbMin = qrand() % (((operande2 + 1) + 1) - (operande2 - 1)) + (operande2 - 1);
    }
    if(nbMax < nbMin)
    {
        int tmp = nbMax;
        nbMax = nbMin;
        nbMin = tmp;
    }

    if(!isRandomable)
    {
        if(!mode.compare(MODE_DIVISION))
        {
            if(nbMin == 0)
            {
                nbMin = 1;
            }
            propo = nbMax / nbMin;
            QTextStream(stdout) << nbMax << " / " << nbMin << " = " << propo << endl;
        }
        else if(!mode.compare(MODE_MULTIPLICATION))
        {
            propo = nbMax * nbMin;
        }
        if(getResult() < 3)
        {
            propo = qrand() % 4;
        }
    }
    else
    {
        propo = qrand() % (((nbMax) + 1) - nbMin) + nbMin;
    }

    if(propo < 0)
    {
        propo = 0;
    }
    return propo;
}

QString Question::getLibelle()const
{
    QString question = QString::number(operande1);

    if(!mode.compare(MODE_ADDITION))
    {
        question += " + ";
    }
    else if (!mode.compare(MODE_SOUSTRACTION))
    {
        question += " - ";
    }
    else if(!mode.compare(MODE_DIVISION))
    {
        question += " / ";
    }
    else if(!mode.compare(MODE_MULTIPLICATION))
    {
        question += " x ";
    }

    question += QString::number(operande2) + " = ";

    return question;
}
