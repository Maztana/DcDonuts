import QtQuick 2.0
import Sailfish.Silica 1.0

Item
{
    FontLoader{ id: fontDonut; source: "../font/PWYummyDonuts.ttf" }

    width: lettreD.width + morceau1.width
    height: lettreD.height

    Label{
        id: lettreD
        text:qsTr("D")
        font.pixelSize: 150
        font.family: fontDonut.name
    }

    Label{
        id: morceau1
        anchors.left: lettreD.right
        y: lettreD.y + lettreD.height/2 - 45
        text:qsTr("octor")
        font.pixelSize: 50
        font.family: fontDonut.name
    }

    Label{
        id: morceau2
        anchors.left: lettreD.right
        y: lettreD.y + lettreD.height/2 + 10
        text:qsTr("onut")
        font.pixelSize: 50
        font.family: fontDonut.name
    }
}
