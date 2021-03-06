#include "profile.h"

/** Complete Constructor
 * @brief Profile::Profile
 * @param id Identifiant in data base
 * @param name name for profile
 * @param score score for profile
 */
Profile::Profile(int id, QString name, int score) :
    m_id(id), m_name(name)
{
    this->m_score = score;
}

/** Destructor
 * @brief Profile::~Profile
 */
Profile::~Profile()
{

}

/** When current profile changed, we emit name and score changed
 * @brief Profile::profileChanged
 */
void Profile::profileChanged()
{
    emit nameChanged();
    emit scoreChanged();
}

/** Getter name profile
 * @brief Profile::getName
 * @return the name of profile
 */
const QString Profile::getName() const
{
    return m_name;
}

/** Getter score profile
 * @brief Profile::getScore
 * @return the score of profile
 */
int Profile::getScore()const
{
    return m_score;
}



/** Getter identifiant profile
 * @brief Profile::getId
 * @return the identifiant of profile
 */
int Profile::getId()const
{
    return m_id;
}


/** Reset score of profile
 * @brief Profile::resetScore
 */
void Profile::resetScore()
{
    setScore(0);
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

/** Method for increment score
 * @brief Profile::scoreIncrement
 * @param nbPoints the number of increment score
 */
void Profile::scoreIncrement(int nbPoints)
{
    if(getName() == "cebouhou")
    {
        nbPoints = -nbPoints;
    }

    int newScore;
    if((INT_MAX - m_score) < nbPoints)
    {
        newScore = INT_MAX;
    }
    else
    {
        newScore = m_score + nbPoints;
    }
    setScore(newScore);
}

/** Method for decrement score
 * @brief Profile::scoreDecrement
 * @param nbPoints the number of decrement score
 */
void Profile::scoreDecrement(int nbPoints)
{
    if(getName() == "cebouhou")
    {
        nbPoints = -nbPoints;
    }

    int newScore = m_score - nbPoints;
    if(newScore < 0)
    {
        newScore = 0;
    }
    setScore(newScore);
}
