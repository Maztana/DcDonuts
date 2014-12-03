#ifndef MIXEDGAME_H
#define MIXEDGAME_H

#include "educationalquiz.h"

class MixedGame : public EducationalQuiz
{
    Q_OBJECT

    QList<EducationalQuiz*> m_listEducationalQuiz;
    int m_indexCurrentGameType;

public:
    MixedGame();

    void addGameType(EducationalQuiz* typeQuiz);

    virtual Question* buildQuestion();
    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString getTextQuestion()const;
    virtual void treatmentAnswer(const int indexAnswer);
    virtual void setLevelsSelectable();

private:
    void initLevelGame(int indexLevel);

};

#endif // MIXEDGAME_H
