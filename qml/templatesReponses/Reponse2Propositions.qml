import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    anchors.horizontalCenter: parent.horizontalCenter
    width: ligne.width
    anchors.top: parent.top
    anchors.margins: 90

    Row{
        id: ligne
        spacing: 20

        Rectangle{
            id:reponse1

            width: 200
            height:220

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 1")
            }
        }
        Rectangle{
            id:reponse2

            width: 200
            height:220

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 2")
            }
        }
    }
}
