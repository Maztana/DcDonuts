# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = dr-donut

CONFIG += sailfishapp
CONFIG += c++11

SOURCES += src/dr-donut.cpp \
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
    src/calculation.cpp \
    src/subtraction.cpp

OTHER_FILES += qml/dr-donut.qml \
    rpm/dr-donut.changes.in \
    rpm/dr-donut.spec \
    rpm/dr-donut.yaml \
    translations/*.ts \
    dr-donut.desktop \
    images/drDonut.png \
    qml/Accueil/Homepage.qml \
    qml/Accueil/Title.qml \
    qml/cover/Cover.qml \
    qml/pages/ChoiseLevelPage.qml \
    qml/pages/ChoiseGameModePage.qml \
    qml/pages/GameQuizPage.qml \
    qml/templatesReponses/ItemAnswer.qml \
    qml/templatesReponses/TwoProposals.qml \
    qml/templatesReponses/ThreeProposals.qml \
    qml/templatesReponses/FourProposals.qml \
    qml/templatesReponses/Seizure.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/dr-donut-de.ts

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
    src/calculation.h \
    src/subtraction.h

RESOURCES += \
    resources.qrc

QT += sql

