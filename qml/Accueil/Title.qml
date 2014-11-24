import QtQuick 2.0
import Sailfish.Silica 1.0

Item
{
    FontLoader{ id: fontDonut; source: "../font/PWYummyDonuts.ttf" }

    width: letterD.width + firstPiece.width
    height: letterD.height

    Label{
        id: letterD
        text:qsTr("D")
        font.pixelSize: 150
        font.family: fontDonut.name
    }

    Label{
        id: firstPiece
        anchors.left: letterD.right
        y: letterD.y + letterD.height/2 - 45
        text:qsTr("octor")
        font.pixelSize: 50
        font.family: fontDonut.name
    }

    Label{
        id: secondPiece
        anchors.left: letterD.right
        y: letterD.y + letterD.height/2 + 10
        text:qsTr("onut")
        font.pixelSize: 50
        font.family: fontDonut.name
    }
}
