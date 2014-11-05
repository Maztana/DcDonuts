import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    Row{

        anchors.bottom: ligne2.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 20
        spacing: 20
        Rectangle{
            id:reponse1

            width: 200
            height:100

            color: 'blue'

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 1")
            }

        }

        Rectangle{
            id:reponse2
            width: 200
            height:100

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 2")
            }
        }
    }

    Row{
        id: ligne2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 110
        spacing: 20

        Rectangle{
            id:reponse3

            width: 200
            height:100

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 3")
            }
        }

    }

}
