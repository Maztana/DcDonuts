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

SOURCES += src/dr-donut.cpp

OTHER_FILES += qml/dr-donut.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/dr-donut.changes.in \
    rpm/dr-donut.spec \
    rpm/dr-donut.yaml \
    translations/*.ts \
    dr-donut.desktop \
    qml/Accueil/Accueil.qml \
    qml/pages/JeuPage.qml \
    images/drDonut.png \
    qml/Accueil/BoutonPerso.qml \
    qml/templatesReponses/Reponse4Propositions.qml \
    qml/templatesReponses/Reponse3Propositions.qml \
    qml/templatesReponses/Reponse2Propositions.qml \
    qml/templatesReponses/ReponseSaisie.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/dr-donut-de.ts

