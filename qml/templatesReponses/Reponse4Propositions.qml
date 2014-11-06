import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    anchors.horizontalCenter: parent.horizontalCenter
    width: ligne1.width

    anchors.top: parent.top
    anchors.margins: 90

    Row{

        id:ligne1
        anchors.top : parent.top
        spacing: 20
        Rectangle{
            id:reponse1

            width: 200
            height:100

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
        anchors.top : ligne1.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter

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
        Rectangle{
            id:reponse4

            width: 200
            height:100

            MouseArea{
                anchors.fill: parent
                onClicked: console.log("reponse 4")
            }
        }
    }

}
