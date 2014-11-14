#include "question.h"

#include <QTextStream>

Question::Question(QString mode, int operande1, int operande2) :
    QObject(0), mode(mode)
{
    //tri des operandes!
    if(!mode.compare("DIVISION"))
    {
        if(operande2 == 0)
        {
            this->operande1 = operande2;
            this->operande2 = operande1;
            QTextStream(stdout) << "division" << endl;
        }
    }
    else if(!mode.compare("SOUSTRACTION"))
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

    if(!mode.compare("ADDITION"))
    {
        result = operande1 + operande2;
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        result = operande1 - operande2;
    }
    else if(!mode.compare("DIVISION"))
    {
        result = operande1 / operande2;
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        result = operande1 * operande2;
    }

    //QTextStream(stdout) << "result -> " << result << endl;
    return result;
}

int Question::getProposition()const
{
    ////////////////////////////////////////////////////////////////////////////////////
    /// \brief propo
    ///
    ///         REVOIR LES RANDOMS DE CHAQUE PROPOSITION
    ///
    /////////////////////////////////////////////////////////////////////////////////////
    int propo = 0;

    if(!mode.compare("ADDITION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        propo = qrand() % (((operande1 -(operande2*2)) + 1) - operande2) + operande2;
    }
    else if(!mode.compare("DIVISION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        propo = qrand() % (((operande1 +(operande2*2)) + 1) - operande2) + operande2;
    }

    //QTextStream(stdout) << "propo -> " << propo << endl;
    return propo;
}

const QString Question::toString()const
{
    QString question = "";

    if(!mode.compare("ADDITION"))
    {
        question =  QString::number(operande1) + " + " + QString::number(operande2) + " = ";
    }
    else if (!mode.compare("SOUSTRACTION"))
    {
        question = QString::number(operande1) + " - " + QString::number(operande2) + " = ";
    }
    else if(!mode.compare("DIVISION"))
    {
        question = QString::number(operande1) + " / " + QString::number(operande2) + " = ";
    }
    else if(!mode.compare("MULTIPLICATION"))
    {
        question = QString::number(operande1) + " x " + QString::number(operande2) + " = ";
    }

    //QTextStream(stdout) << "question -> " << question << endl;
    return question;
}
