#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT

    /** All values for this question */
    QList<QString> m_listValues;

public:
    explicit Question(QList<QString> listValues);
    ~Question();

    const QList<QString> getValues()const;

signals:

public slots:

};

#endif // QUESTION_H
