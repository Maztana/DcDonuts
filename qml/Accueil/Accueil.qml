import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Components"

Page{
    id: pageAccueil

    //FontLoader{ id: fontDonut; source: "../font/PWYummyDonuts.ttf" }

    SilicaFlickable{

        anchors.fill:parent

        PullDownMenu{
            MenuItem{
                text: qsTr("A propos")
            }
        }

        Label{
            id: nameProfil
            text: application.nameProfile
            color: Theme.highlightColor
            font.bold: true
            font.pixelSize: 28
            x:50
            anchors{
                top: parent.top
                margins: 50
            }
        }

        IconButton {
            id: logoProfil
            smooth: true
            y:30
            opacity: 0.3

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
                color:"white"
            }
        }



        Titre{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: iconDrDonut.top
            anchors.margins: 30
        }

        Image{
            id: iconDrDonut
            source:"qrc:///qml/images/drDonut.png"
            width: sourceSize.width/2
            height: sourceSize.height/2
            anchors{
                horizontalCenter: parent.horizontalCenter
                margins:60
                bottom: buttonPlay.top
            }
        }

        Button
        {
            id:buttonPlay
            text: qsTr("Jouer")
            anchors{
                bottom:boutonOptions.top
                horizontalCenter: parent.horizontalCenter
                margins:60
            }
            onClicked: {
                if(application.launchGame())
                {
                    pageStack.push(Qt.resolvedUrl("../pages/ChoixModeDeJeuPage.qml"))
                }
                else
                {
                    pageStack.push(Qt.resolvedUrl("../pages/GestionProfils.qml"))
                }
            }
        }

        Button
        {
            id:boutonOptions
            text: qsTr("Options")

            anchors{
                bottom:parent.bottom
                horizontalCenter: parent.horizontalCenter
                margins:130
            }
            enabled: false
        }

    }
}

