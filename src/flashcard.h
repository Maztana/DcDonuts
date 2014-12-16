#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "educationalquiz.h"

class Flashcard : public EducationalQuiz
{
    Q_OBJECT


    /** Name data base download */
    //QString m_dbName;
    /** List of cards */
    QList<Question*> m_listCards;

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

private:
    virtual inline void setLevelsSelectable(){}
    virtual void setNumberPropositions(){m_numberPropositions = 1; emit numberPropositionsChanged();}
    virtual void treatmentAnswer(const int);

signals:

public slots:
    /** Getter result of question
     * @brief Flashcard::getResult
     * @return the result
     */
    virtual inline const QString getResult()const{return m_currentQuestion->getValues().first();}
    virtual inline bool isFlashcard(){return true;}
    virtual void initDB(QString nameDataBase);

};

#endif // FLASHCARD_H
