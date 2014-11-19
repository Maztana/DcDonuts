#include "question.h"
#include "Ressources.h"

#include <QTextStream>
#include <QDateTime>

Question::Question(const QString& mode, int operande1, int operande2) :
    QObject(0), mode(mode)
{
    qsrand(QDateTime::currentDateTime().toTime_t());

    //tri des operandes!
    if(!mode.compare(MODE_DIVISION))
    {
        if(operande2 == 0)
        {
            this->operande1 = operande2;
            this->operande2 = operande1;
            QTextStream(stdout) << "division" << endl;
        }
    }
    else if(!mode.compare(MODE_SOUSTRACTION))
    {
        if(operande1 < operande2)
        {
            this->operande1 = operande2;
            this->operande2 = operande1;
            QTextStream(stdout) << "soustraction" << endl;
        }
    }
    else
    {
        this->operande1 = operande1;
        this->operande2 = operande2;
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
        QTextStream(stdout) << "result -> " << result << endl;
    }
    else if(!mode.compare(MODE_DIVISION))
    {
        result = operande1 / operande2;
        QTextStream(stdout) << "result -> " << result << endl;
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

    if(!mode.compare(MODE_ADDITION))
    {
        propo = qrand() % (((operande1 + 3 +(operande2*2)) + 1) - operande2-operande1) + operande2+operande1;
    }
    else if (!mode.compare(MODE_SOUSTRACTION))
    {
        propo = qrand() % (((operande1 + 3 +(operande2*2)) + 1) - operande2-operande1) + operande2+operande1;
        QTextStream(stdout) << "propo -> " << propo << endl;
    }
    else if(!mode.compare(MODE_DIVISION))
    {
        propo = qrand() % (((operande1 + 3 +(operande2*2)) + 1) - operande2-operande1) + operande2+operande1;
        QTextStream(stdout) << "propo -> " << propo << endl;
    }
    else if(!mode.compare(MODE_MULTIPLICATION))
    {
        propo = qrand() % (((operande1 + 3 +(operande2*2)) + 1) - operande2-operande1) + operande2+operande1;
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
