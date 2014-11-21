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

SOURCES += src/dr-donut.cpp \
    src/mainapplication.cpp \
    src/profil.cpp \
    src/typedejeu.cpp \
    src/questionnaireeducatif.cpp \
    src/calcul.cpp \
    src/partie.cpp \
    src/niveau.cpp \
    src/question.cpp \
    src/addition.cpp \
    src/soustraction.cpp \
    src/multiplication.cpp \
    src/division.cpp \
    src/managerbdd.cpp

OTHER_FILES += qml/dr-donut.qml \
    qml/cover/CoverPage.qml \
    rpm/dr-donut.changes.in \
    rpm/dr-donut.spec \
    rpm/dr-donut.yaml \
    translations/*.ts \
    dr-donut.desktop \
    qml/Accueil/Accueil.qml \
    qml/pages/JeuPage.qml \
    images/drDonut.png \
    qml/templatesReponses/Reponse4Propositions.qml \
    qml/templatesReponses/Reponse3Propositions.qml \
    qml/templatesReponses/Reponse2Propositions.qml \
    qml/templatesReponses/ReponseSaisie.qml \
    qml/Accueil/Titre.qml \
    qml/pages/ChoixModeDeJeuPage.qml \
    qml/Components/BoutonPerso.qml \
    qml/Components/BoutonSigne.qml \
    qml/Components/PageCustom.qml \
    qml/pages/ChoixDifficulteePage.qml \
    qml/templatesReponses/ItemReponse.qml
    qml/templatesReponses/ItemReponse.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/dr-donut-de.ts

HEADERS += \
    src/mainapplication.h \
    src/profil.h \
    src/typedejeu.h \
    src/questionnaireeducatif.h \
    src/calcul.h \
    src/partie.h \
    src/niveau.h \
    src/question.h \
    src/addition.h \
    src/soustraction.h \
    src/multiplication.h \
    src/division.h \
    src/managerbdd.h

RESOURCES += \
    resources.qrc

QT += sql

