#ifndef GAMETYPEFACTORY_H
#define GAMETYPEFACTORY_H

#include <QObject>

#include "educationalquiz.h"

class EducationalQuizFactory : public QObject
{
    Q_OBJECT
public:
    explicit EducationalQuizFactory(QObject *parent = 0);

    static EducationalQuiz* makeGames(QList<int> identifiantsGameType);
    static EducationalQuiz* makeGameType(int identifiantGameType);

signals:

public slots:

};

#endif // GAMETYPEFACTORY_H
