#include "profile.h"

/** Constructor complet
 * @brief Profile::Profile
 * @param id Identifiant in data base
 * @param name name for profile
 * @param score score for profile
 */
Profile::Profile(int id, QString name, int score)
{
    this->m_id=id;
    this->m_nom=name;
    this->m_score=score;
}

/** Destructor
 * @brief Profile::~Profile
 */
Profile::~Profile()
{

}

/** Getter name profile
 * @brief Profile::getName
 * @return the name of profile
 */
const QString Profile::getName() const
{
    return m_nom;
}

/** Getter score profile
 * @brief Profile::getScore
 * @return the score of profile
 */
int Profile::getScore()const
{
    return m_score;
}

/** Set score
 * @brief Profile::setScore
 * @param nbPoint
 */
void Profile::setScore(int nbPoint)
{
    m_score = nbPoint;
    emit scoreChanged();
}

/** Getter identifiant profile
 * @brief Profile::getId
 * @return the identifiant of profile
 */
int Profile::getId()const
{
    return m_id;
}

/** Method for increment score
 * @brief Profile::incrementScore
 * @param nbPoints the number of increment score
 */
void Profile::scoreIncrement(int nbPoints)
{
    int newScore = m_score + nbPoints;
    setScore(newScore);
}

/** Method for decrement score
 * @brief Profile::decrementScore
 * @param nbPoints the number of decrement score
 */
void Profile::scoreDecrement(int nbPoints)
{
    int newScore = m_score - nbPoints;
    if(newScore < 0)
    {
        newScore = 0;
    }
    setScore(newScore);
}

/** Reset score of profile
 * @brief Profile::resetScore
 */
void Profile::resetScore()
{
    setScore(0);
}

/** When current profile changed, we emit name and score changed */
void Profile::profileChanged()
{
    emit nameChanged();
    emit scoreChanged();
}

