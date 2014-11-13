import QtQuick 2.0
import Sailfish.Silica 1.0
import dr.donut 1.0

Page{
    id: pageAccueil

    FontLoader{ id: fontPerso; source: "../font/PWYummyDonuts.ttf" }

    /*----Fond ----*/
    Rectangle{
        anchors.fill: parent
        color: 'lightblue'
        opacity: 0.6
    }

    MainApplication {
        id: main_application
        /*
        onRunPartieChanged: {
            console.log("ca marche jusqu'a l'appel")
            //main_application.lancerPartie()
        }
        */
    }

    SilicaFlickable{

        anchors.fill:parent

        PullDownMenu{
            MenuItem{
                text: qsTr("A propos")
                onClicked: console.log("le click marche")
            }
            /*
            MenuItem{
                text: qsTr("Mode de jeu")
                onClicked: pageStack.push(Qt.resolvedUrl("../pages/ChoixModeDeJeuPage.qml"))
            }
            */
        }

        Text{
            id: nomProfil
            text: main_application.nameProfil
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
            }
        }



        Titre{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: iconDrDonut.top
            anchors.margins: 30
        }

        Image{
            id: iconDrDonut
            source:"../images/drDonut.png"
            width: sourceSize.width/2
            height: sourceSize.height/2
            anchors{
                horizontalCenter: parent.horizontalCenter
                margins:60
                bottom: boutonJouer.top
            }
        }

        BoutonPerso
        {
            id:boutonJouer
            text: qsTr("Jouer")
            anchors{
                bottom:boutonOptions.top
                horizontalCenter: parent.horizontalCenter
                margins:60
            }

            value : main_application.runPartie
            link: "../pages/JeuPage.qml"
        }

        BoutonPerso
        {
            id:boutonOptions
            text: qsTr("Options")

            anchors{
                bottom:parent.bottom
                horizontalCenter: parent.horizontalCenter
                margins:130
            }

            enable:false
            link: "../pages/JeuPage.qml"
            value: main_application.runPartie
        }

    }

    Rectangle {
        width: animation.width; height: animation.height + 8

        AnimatedImage { id: animation; source: "../images/animatedimageitem.gif"}

        Rectangle {
            property int frames: animation.frameCount

            width: 4; height: 8
            x: (animation.width - width) * animation.currentFrame / frames
            y: animation.height
            color: "red"
        }
    }
}
