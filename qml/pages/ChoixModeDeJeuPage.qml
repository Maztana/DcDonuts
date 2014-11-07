import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Accueil"

Page {
    SilicaFlickable {
        anchors.fill: parent

        contentHeight: column.height

        VerticalScrollDecorator {}

        Column {
            id: column
            spacing: 40
            width: parent.width

            PageHeader {
                title: qsTr("Mode de Jeu")
            }

            Row {
              id: iconButtons
                spacing: Theme.paddingLarge
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top : parent.top
                anchors.margins: 180

               BoutonPerso{

                    text:qsTr("Calcul")

                }


              /* IconButton {
                    icon.source: "image://theme/icon-l-clear"
                }
                IconButton {
                    id: pause
                    icon.source: "image://theme/icon-l-pause"
                    onClicked: iconButtons.playing = false
                    enabled: iconButtons.playing
                }
                IconButton {
                    id: play
                    icon.source: "image://theme/icon-l-play"
                    onClicked: iconButtons.playing = true
                    enabled: !iconButtons.playing
                }*/
            }


            Row {
                spacing: Theme.paddingLarge
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    text: "Call"
                }
                Button {
                    text: "SMS"
                }
            }


            Row {
                spacing: Theme.itemSizeSmall
                anchors.horizontalCenter: parent.horizontalCenter
                Switch {
                    icon.source: "image://theme/icon-l-shuffle"
                   // enabled: false
                }
                Switch {
                    icon.source: "image://theme/icon-l-repeat"
                }
                Switch {
                    icon.source: "image://theme/icon-l-share"
                    onCheckedChanged: { busy = true; busyTimer.start() }
                    Timer {
                        id: busyTimer
                        interval: 4200
                        onTriggered: parent.busy = false
                    }
                }
            }

        }
    }
}
