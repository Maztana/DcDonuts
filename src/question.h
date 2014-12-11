#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    /** All values for this question */
    QList<QString> m_listValues;
    /** Text question */
    QString m_textQuestion;

public:
    explicit Question(QList<QString> listValues, QString textQuestion);
    ~Question();

    const QList<QString> getValues()const{return m_listValues;}
    const QString getTextQuestion()const{return m_textQuestion;}

signals:

public slots:

};

#endif // QUESTION_H
