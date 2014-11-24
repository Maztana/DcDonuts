import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    id: homepage

    SilicaFlickable{

        anchors.fill:parent

        PullDownMenu{
            MenuItem{
                text: qsTr("A propos")
            }
        }

        Label{
            id: nameProfile
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
            id: logoProfile
            smooth: true
            y:30
            //opacity: 0.3
            onClicked: pageStack.push(Qt.resolvedUrl("../pages/ProfileManagerPage.qml"))

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

        Title{
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
                bottom:buttonOptions.top
                horizontalCenter: parent.horizontalCenter
                margins:60
            }
            onClicked: {
                if(application.launchGame())
                {
                    pageStack.push(Qt.resolvedUrl("../pages/ChoiseGameModePage.qml"))
                }
                else
                {
                    pageStack.push(Qt.resolvedUrl("../pages/ProfileManagerPage.qml"))
                }
            }
        }

        Button
        {
            id:buttonOptions
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

