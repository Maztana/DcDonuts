#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <QString>

// Data base
const QString PATH_DATA_BASE = "drdonut.db.sqlite";

/*
// Game Mode
enum EnumGameType {
    MODE_ADDITION = 1,
    MODE_SUBTRACTION = 2,
    MODE_MULTIPLICATION = 3,
    MODE_DIVISION = 4,
    MODE_COUNTING = 5,
    MODE_COLOR = 6,
    MODE_MELE = 7,
    MODE_FLASHCARD = 8
};
*/

const QString MODE_FLASHCARD = "FLASHCARD";
const QString MODE_MELE = "ALL";
const QString MODE_COUNTING = "COUNTING";
const QString MODE_COLOR = "COLOR";
const QString MODE_ADDITION = "ADDITION";
const QString MODE_SUBTRACTION = "SUBTRACTION";
const QString MODE_MULTIPLICATION = "MULTIPLICATION";
const QString MODE_DIVISION = "DIVISION";


// Score points
const int INCREMENTAL_SCORE_ADDITION = 1;
const int INCREMENTAL_SCORE_SUBTRACTION = 1;
const int INCREMENTAL_SCORE_MULTIPLICATION = 2;
const int INCREMENTAL_SCORE_DIVISION = 2;

#endif // RESSOURCES_H
