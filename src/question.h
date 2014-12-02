#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    /** The game mode for this question */
    const QString& m_gameMode;
    /** All values for this question */
    QList<QString> m_listValues;
    /** The first operande */
    //int m_firstOperande;
    /** The second operand */
    //int m_secondOperande;

public:
    explicit Question(const QString& gameMode, QList<QString> listValues);

    const QString getTextQuestion()const;
    const QList<QString> getValues()const;

signals:

public slots:

};

#endif // QUESTION_H
