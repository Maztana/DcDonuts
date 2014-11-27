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
        font.pixelSize: Theme.fontSizeHuge * 2.5
        font.family: fontDonut.name
    }

    Label{
        id: secondPiece
        anchors.left: letterD.right
        anchors.bottom: letterD.bottom
        anchors.bottomMargin: Theme.paddingSmall
        text:qsTr("onut")
        font.pixelSize: letterD.font.pixelSize / 2
        font.family: fontDonut.name
    }

    Label{
        id: firstPiece
        anchors.left: letterD.right
        anchors.bottom: secondPiece.top
        anchors.bottomMargin: Theme.paddingSmall
        text:qsTr("octor")
        font.pixelSize: secondPiece.font.pixelSize / (firstPiece.text.length + 1) * secondPiece.text.length
        font.family: fontDonut.name
    }
}
