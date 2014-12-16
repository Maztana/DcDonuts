#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <QString>
#include <QTextStream>
#include <QDir>

// Data base
const QString NAME_DATA_BASE = "drdonut.db.sqlite";
const QString PATH_CONFIG = QDir::home().path() + "/.config/harbour-dr-donut";
const QString PATH_LOCAL = QDir::home().path() + "/.local/share/harbour-dr-donut";




// Game Mode
enum EnumGameMode {
    ADDITION_MODE = 1,
    SUBTRACTION_MODE = 2,
    MULTIPLICATION_MODE = 3,
    DIVISION_MODE = 4,
    COUNTING_MODE = 5,
    COLOR_MODE = 6,
    FLASHCARD_MODE = 7
};

// Level type
enum EnumLevelType {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    AUTO = 4
};

// Score points
const int INCREMENTAL_ADDITION_SCORE = 1;
const int INCREMENTAL_SUBTRACTION_SCORE = 1;
const int INCREMENTAL_MULTIPLICATION_SCORE = 2;
const int INCREMENTAL_DIVISION_SCORE = 2;
const int INCREMENTAL_COUNTING_SCORE = 3;

#endif // RESSOURCES_H
