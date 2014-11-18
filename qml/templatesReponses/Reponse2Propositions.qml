import QtQuick 2.0
import Sailfish.Silica 1.0



Item{
    property alias textReponse1 : rep1.rep
    property alias textReponse2 : rep2.rep

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

            ItemReponse{
                id: rep1
                indexRep: 1
            }
        }
        Rectangle{
            id:reponse2

            width: 200
            height:220

            ItemReponse{
                id: rep2
                indexRep: 2
            }
        }
    }
}
