import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    IconButton {
        id: logoProfil
        width: 50
        height: 100
        smooth: true

        anchors{
            right: parent.right
            margins: Theme.paddingLarge
        }

        icon{
            width:50
            height:50
            anchors.top:parent.top
            source: "../images/profils.png"
        }

        Label{
            text: qsTr("Profils")
            anchors.top: parent.icon.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 22
        }
    }

    BoutonPerso
    {
        text: qsTr("Jouer")

        anchors{
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }

        link: qsTr("../pages/JeuPage.qml")
    }
}
