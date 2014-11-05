import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    FontLoader{ id: fontPerso; source: "../font/PWYummyDonuts.ttf" }

    /*----Fond ----*/
    Rectangle{
        anchors.fill: parent
        color: 'lightblue'
        opacity: 0.6
    }

    SilicaFlickable{

        anchors.fill:parent

        PullDownMenu{
            MenuItem{
                text: qsTr("A propos")
            }
        }

        Text{
            id: nomProfil
            text: qsTr("JOUEUR X")
            font.pixelSize: 28
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

        IconButton {
            id: logoProfil
            smooth: true
            y:30

            anchors{
                right: parent.right
                margins: Theme.paddingLarge
            }

            icon{
                width:80
                height:80
                anchors.top:parent.top
                source: "../images/profils.png"
            }

            Text{
                text: qsTr("Profils")
                anchors.top: parent.icon.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 30
            }
        }

        Titre{
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        BoutonPerso
        {
            text: qsTr("Jouer")

            anchors{
                bottom:boutonOptions.top
                horizontalCenter: parent.horizontalCenter
                margins:130
            }

            link: qsTr("../pages/JeuPage.qml")
        }

        BoutonPerso
        {
            id:boutonOptions
            text: qsTr("Options")

            anchors{
                bottom:parent.bottom
                horizontalCenter: parent.horizontalCenter
                margins:160
            }
        }

    }
}
