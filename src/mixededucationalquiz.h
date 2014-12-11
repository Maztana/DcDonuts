#ifndef MIXEDGAME_H
#define MIXEDGAME_H

#include "educationalquiz.h"

class MixedEducationalQuiz : public EducationalQuiz
{
    Q_OBJECT
    /** list of all edicational quiz */
    QList<EducationalQuiz*> m_listEducationalQuiz;
    /** current game */
    EducationalQuiz* m_currentGameType;

public:
    explicit MixedEducationalQuiz();
    virtual ~MixedEducationalQuiz();

    void addGameType(EducationalQuiz* typeQuiz);
    virtual Question* buildQuestion();

    virtual const QString getProposition()const;
    virtual const QString getResult()const;
    virtual const QString getTextQuestion()const;


protected:
    virtual void setListPropositions();
    virtual void setLevelsSelectable();
    virtual void setNumberPropositions();

private:
    virtual void treatmentAnswer(const int indexAnswer);
    void initLevelGame(int indexLevel);


public slots:
    virtual void launchQuestion();
    void rightAnswer(int indexAnswer);
    void scoreIncrement(int incrementalScore);
    void wrongAnswer(int indexAnswer);
    void scoreDecrement(int decrementalScore);

};

#endif // MIXEDGAME_H
