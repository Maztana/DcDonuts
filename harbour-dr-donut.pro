# The name of application
TARGET = harbour-dr-donut

CONFIG += sailfishapp
CONFIG += c++11

SOURCES += \
    src/mainapplication.cpp \
    src/question.cpp \
    src/addition.cpp \
    src/multiplication.cpp \
    src/division.cpp \
    src/managerbdd.cpp \
    src/profile.cpp \
    src/game.cpp \
    src/level.cpp \
    src/gametype.cpp \
    src/educationalquiz.cpp \
    src/subtraction.cpp \
    src/calcul.cpp \
    src/additiongamefactory.cpp \
    src/subtractiongamefactory.cpp \
    src/multiplicationgamefactory.cpp \
    src/divisiongamefactory.cpp \
    src/jsonmanager.cpp \
    src/language.cpp \
    src/mixedgamefactory.cpp \
    src/mixededucationalquiz.cpp \
    src/dr-donut.cpp \
    src/educationalquizfactory.cpp \
    src/flashcard.cpp \
    src/flashcardfactory.cpp \
    src/countingmode.cpp \
    src/countinggamefactory.cpp \
    src/urlitemmodel.cpp

OTHER_FILES += \
    translations/*.ts \
    images/drDonut.png \
    qml/Accueil/Homepage.qml \
    qml/Accueil/Title.qml \
    qml/cover/Cover.qml \
    qml/pages/GameQuizPage.qml \
    qml/templatesReponses/ItemAnswer.qml \
    qml/templatesReponses/TwoProposals.qml \
    qml/templatesReponses/ThreeProposals.qml \
    qml/templatesReponses/FourProposals.qml \
    qml/homepage/Homepage.qml \
    qml/homepage/Title.qml \
    qml/templatesAnswers/ItemAnswer.qml \
    qml/pages/ProfileManagerPage.qml \
    qml/pages/ChoiceGameModePage.qml \
    qml/templatesAnswers/FourPropositions.qml \
    qml/pages/CreationProfilePage.qml \
    qml/pages/ItemProfile.qml \
    qml/pages/AboutPage.qml \
    qml/pages/HowToPlay.qml \
    qml/pages/LevelItem.qml \
    qml/pages/OptionPage.qml \
    qml/pages/InfoBanner.qml \
    qml/harbour-dr-donut.qml \
    rpm/harbour-dr-donut.changes.in \
    rpm/harbour-dr-donut.yaml \
    rpm/harbour-dr-donut.spec \
    harbour-dr-donut.desktop \
    qml/templatesAnswers/Flashcard.qml \
    qml/pages/ChoiceFlashcardPage.qml \
    qml/pages/FormDisplay.qml \
    qml/*.js \
    qml/pages/ImportFlashcardPage.qml

CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/harbour-dr-donut-fr.ts \
                translations/harbour-dr-donut.ts

HEADERS += \
    src/mainapplication.h \
    src/question.h \
    src/addition.h \
    src/multiplication.h \
    src/division.h \
    src/managerbdd.h \
    src/ressources.h \
    src/profile.h \
    src/game.h \
    src/level.h \
    src/gametype.h \
    src/educationalquiz.h \
    src/subtraction.h \
    src/calcul.h \
    src/additiongamefactory.h \
    src/subtractiongamefactory.h \
    src/multiplicationgamefactory.h \
    src/divisiongamefactory.h \
    src/language.h \
    src/jsonmanager.h \
    src/mixedgamefactory.h \
    src/mixededucationalquiz.h \
    src/educationalquizfactory.h \
    src/flashcard.h \
    src/flashcardfactory.h \
    src/countingmode.h \
    src/countinggamefactory.h \
    src/urlitemmodel.h

RESOURCES += \
    resources.qrc

QT += sql

db_flashcard.path = /usr/share/${TARGET}/db
db_flashcard.files = db/*.db

INSTALLS += db_flashcard
