import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    property alias textReponse1 : rep1.rep
    property alias textReponse2 : rep2.rep
    property alias textReponse3 : rep3.rep

    anchors.horizontalCenter: parent.horizontalCenter
    width: ligne1.width

    anchors.top: parent.top
    anchors.margins: 90

    Row{

        id:ligne1
        anchors.top : parent.top
        spacing: 20

        ItemReponse{
            id: rep1
            indexRep: 1
        }

        ItemReponse{
            id: rep2
            indexRep: 2
        }
    }

    Row{
        id: ligne2
        anchors.top: ligne1.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        ItemReponse{
            id: rep3
            indexRep: 3
        }
    }
}
