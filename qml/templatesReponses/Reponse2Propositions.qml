import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    Row{
        id: ligne
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 110
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
