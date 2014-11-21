import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Components"

Page{

    SilicaFlickable {

        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader {
            title: application.nameProfile
        }

        Column {
            id: colonneDifficulte
            spacing: 50
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: ligneFacile
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    id: btFacile
                    text:qsTr("Facile")
                    link: "../pages/JeuPage.qml"
                }
            }

            Row {
                id: ligneMoyen
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Moyen")
                    enable:false
                    link: "../pages/JeuPage.qml"
                }
            }

            Row {
                id: ligneDifficile
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Difficile")
                    enable:false
                    link: "../pages/JeuPage.qml"
                }
            }

            Row {
                id: ligneAutomatique
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Automatique")
                    enable:false
                    link: "../pages/JeuPage.qml"
                }
            }

        }
    }
}
