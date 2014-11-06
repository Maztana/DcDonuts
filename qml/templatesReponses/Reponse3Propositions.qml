import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    property alias textReponse1 : labelRep1.text
    property alias textReponse2 : labelRep2.text
    property alias textReponse3 : labelRep3.text

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

            Label{
                id: labelRep1
                anchors.centerIn: parent

                font.bold: true
                font.pixelSize: 60
                color: "black"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: console.log(labelRep1.text)
            }

        }

        Rectangle{
            id:reponse2
            width: 200
            height:100

            Label{
                id: labelRep2
                anchors.centerIn: parent

                font.bold: true
                font.pixelSize: 60
                color: "black"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: console.log(labelRep2.text)
            }
        }
    }

    Row{
        id: ligne2
        anchors.top: ligne1.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Rectangle{
            id:reponse3

            width: 200
            height:100

            Label{
                id: labelRep3
                anchors.centerIn: parent

                font.bold: true
                font.pixelSize: 60
                color: "black"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: console.log(labelRep3.text)
            }
        }

    }

}
