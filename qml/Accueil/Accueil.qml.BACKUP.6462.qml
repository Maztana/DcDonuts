import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    /*----Fond ----*/
    Rectangle{
        anchors.fill: parent
        color: 'lightblue'
        opacity: 0.6
    }

    SilicaFlickable{
        anchors.fill:parent

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

            Label{
                text: qsTr("Profils")
                anchors.top: parent.icon.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 30
            }
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

            link: qsTr("../pages/JeuPage.qml")
        }

    }
}
