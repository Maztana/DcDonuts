import QtQuick 2.0

Item
{
    FontLoader{ id: fontPerso; source: "../font/PWYummyDonuts.ttf" }

    width: lettreD.width + morceau1.width
    height: lettreD.height

    Text{
        id: lettreD
        text:qsTr("D")
        font.pixelSize: 150
        font.family: fontPerso.name
    }

    Text{
        id: morceau1
        anchors.left: lettreD.right
        y: lettreD.y + lettreD.height/2 - 45
        text:qsTr("octor")
        font.pixelSize: 50
        font.family: fontPerso.name
    }

    Text{
        id: morceau2
        anchors.left: lettreD.right
        y: lettreD.y + lettreD.height/2 + 10
        text:qsTr("onut")
        font.pixelSize: 50
        font.family: fontPerso.name
    }
}
