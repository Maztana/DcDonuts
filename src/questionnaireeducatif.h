#ifndef QUESTIONNAIREEDUCATIF_H
#define QUESTIONNAIREEDUCATIF_H

#include "typedejeu.h"
#include "question.h"

class QuestionnaireEducatif : public TypeDeJeu
{
    Q_OBJECT

    Q_PROPERTY(QString libelleQuestion READ getLibelleQuestion NOTIFY libelleQuestionChanged)
    Q_PROPERTY(QString proposition1 READ getProposition1 NOTIFY proposition1Changed)
    Q_PROPERTY(QString proposition2 READ getProposition2 NOTIFY proposition2Changed)
    Q_PROPERTY(QString proposition3 READ getProposition3 NOTIFY proposition3Changed)
    Q_PROPERTY(QString proposition4 READ getProposition4 NOTIFY proposition4Changed)
    Q_PROPERTY(QString colorRep1 READ getColor1 WRITE setColor1 NOTIFY color1Changed)
    Q_PROPERTY(QString colorRep2 READ getColor2 WRITE setColor2 NOTIFY color2Changed)
    Q_PROPERTY(QString colorRep3 READ getColor3 WRITE setColor3 NOTIFY color3Changed)
    Q_PROPERTY(QString colorRep4 READ getColor4 WRITE setColor4 NOTIFY color4Changed)

    QList<int> listProposition;
    QList<Question*> questionsDonnees;
    Question* questionCourante;

    QString color1;
    QString color2;
    QString color3;
    QString color4;


public:
    explicit QuestionnaireEducatif(Niveau* niveauDuJeu);
    ~QuestionnaireEducatif();

    virtual inline bool isQuestionnaire()const{return true;}

    const QString getLibelleQuestion();
    const QString getProposition1();
    const QString getProposition2();
    const QString getProposition3();
    const QString getProposition4();

    const QString getColor1();
    const QString getColor2();
    const QString getColor3();
    const QString getColor4();

    void setColor1(QString color);
    void setColor2(QString color);
    void setColor3(QString color);
    void setColor4(QString color);

    virtual Question* getQuestion() = 0;
    Question* getCurrentQuestion();
    const QString& getModeJeu();

protected:
    static QString MODE_JEU;
    static int NB_PROPOSITIONS;
    static QString COLOR_INIT;
    static QString COLOR_SELECTION;
    static QString COLOR_TRUE;
    static QString COLOR_FALSE;

private:
    void setListProposition();
    void setColor(int index, QString color);

signals:
    void libelleQuestionChanged();
    void proposition1Changed();
    void proposition2Changed();
    void proposition3Changed();
    void proposition4Changed();
    void color1Changed();
    void color2Changed();
    void color3Changed();
    void color4Changed();

    void finishTraitResponse();

public slots:
    void lancerJeu();
    void lancerQuestion();
    void newQuestion();
    void traitResponse(QString response);

};

#endif // QUESTIONNAIREEDUCATIF_H
