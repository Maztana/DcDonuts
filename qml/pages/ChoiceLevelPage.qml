import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    SilicaFlickable {

        anchors.fill: parent

        VerticalScrollDecorator {}

        Column {
            id: columnDifficulte
            spacing: Theme.paddingLarge * 2
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter

            PageHeader {
                Label {
                    id: nameProfile
                    text: currentProfile.name
                    font.pixelSize: Theme.fontSizeLarge
                    color: Theme.highlightColor
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.margins: Theme.paddingLarge
                }
                Label{
                    id: scoreProfile
                    text: currentProfile.score + " Donut(s)"
                    color: Theme.secondaryHighlightColor
                    font.family: Theme.fontFamilyHeading
                    font.pixelSize: Theme.fontSizeMedium
                    anchors{
                        top: nameProfile.bottom
                        right: nameProfile.right
                    }
                }
            }

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
