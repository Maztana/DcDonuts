#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "educationalquiz.h"

class Flashcard : public EducationalQuiz
{
    Q_OBJECT

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
    /** Getter result of question
     * @brief Flashcard::getResult
     * @return the result
     */
    virtual inline const QString getResult()const{return m_currentQuestion->getValues().first();}
    /** Getter of question text
     * @brief Flashcard::getTextQuestion
     * @return the text of question
     */
    virtual inline const QString makeTextQuestion(QList<QString>)const{return m_textQuestion;}///////faire le chargement en bdd de la question

private:
    /** Text question dowload */
    QString m_textQuestion;

    virtual inline void setLevelsSelectable(){}
    virtual void setNumberPropositions(){m_numberPropositions = 1; emit numberPropositionsChanged();}
    virtual void treatmentAnswer(const int);

signals:

public slots:
    virtual inline bool isFlashcard(){return true;}

};

#endif // FLASHCARD_H
