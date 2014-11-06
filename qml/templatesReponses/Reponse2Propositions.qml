import QtQuick 2.0
import Sailfish.Silica 1.0



Item{
    property alias textReponse1 : labelRep1.text
    property alias textReponse2 : labelRep2.text

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
            height:220

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
}
