#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "educationalquiz.h"
#include "urlitemmodel.h"

class Flashcard : public EducationalQuiz
{
    Q_OBJECT

    /** id of current question */
     int m_idQuestion;
    /** counter of questions */
     static int s_cpt;

public:
    explicit Flashcard();
    virtual ~Flashcard();

    const QList<QString> getPropositions();

    virtual Question* buildQuestion();

    /** Getter of proposition
     * @brief Flashcard::getProposition
     * @return a posible proposition for this question
     */
    virtual inline const QString getProposition()const{return "";}

    /** Getter of question text
     * @brief Flashcard::makeTextQuestion
     * @return the text of question
     */
    virtual inline const QString makeTextQuestion(QList<QString>)const{return "";}

protected:
    virtual void setNumberPropositions(){m_numberPropositions = 1; emit numberPropositionsChanged();}

private:
    virtual inline void setLevelsSelectable(){}
    virtual void treatmentAnswer(const int);

public slots:
    /** Getter result of question
     * @brief Flashcard::getResult
     * @return the result
     */
    virtual inline const QString getResult()const{return m_currentQuestion->getValues().first();}
    virtual inline bool isFlashcard(){return true;}
    virtual void initDB(QString url, QString name);

};

#endif // FLASHCARD_H
