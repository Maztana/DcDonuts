import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    SilicaFlickable {

        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader {
            title: application.nameProfile
        }

        Column {
            id: columnDifficulte
            spacing: 50
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: lineEasy
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Facile")
                    enabled:false
                    //onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }

            }

            Row {
                id: lineMedium
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Moyen")
                    enabled:false
                    //onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }

            }

            Row {
                id: lineDifficult
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Difficile")
                    enabled:false
                    //onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))

                }
            }

            Row {
                id: lineAutomatique
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Auto")
                    enabled:false
                    //onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }
            }

        }
    }
}
