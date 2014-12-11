import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    id: homepage

    SilicaFlickable{

        anchors.fill:parent

        PullDownMenu{
            MenuItem{
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("../pages/AboutPage.qml"))

            }
            MenuItem{
                text: qsTr("Game rules")
                onClicked: pageStack.push(Qt.resolvedUrl("../pages/HowToPlay.qml"))
            }
        }

        Label{
            id: nameProfile
            text: currentProfile.name
            color: Theme.highlightColor
            truncationMode: TruncationMode.Fade
            width: parent.width / 2
            font.family: Theme.fontFamilyHeading
            font.pixelSize: Theme.fontSizeLarge
            anchors{
                top: parent.top
                left: parent.left
                topMargin: Theme.paddingLarge * 2
                leftMargin: Theme.paddingLarge * 2
            }
        }

        Label{
            id: scoreProfile
            text: currentProfile.score + " Donut(s)"
            truncationMode: TruncationMode.Fade
            width: parent.width / 2
            color: Theme.secondaryHighlightColor
            font.family: Theme.fontFamilyHeading
            font.pixelSize: Theme.fontSizeMedium
            anchors{
                top: nameProfile.bottom
                left: nameProfile.left
            }

            visible:{
                if(currentProfile.name === "")
                {
                    return false
                }
                return true
            }
        }

        IconButton {
            id: logoProfile
            smooth: true
            onClicked: pageStack.push(Qt.resolvedUrl("../pages/ProfileManagerPage.qml"))


            anchors{
                top: parent.top
                right: parent.right
                topMargin: Theme.paddingLarge
                rightMargin: Theme.paddingLarge
            }

            icon{
                width: Theme.iconSizeLarge
                height: logoProfile.icon.width * 0.9
                source: "../images/profils.png"
            }

            Text{
                text: qsTr("Profiles")
                anchors.top: parent.icon.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: Theme.fontFamilyHeading
                font.pixelSize: Theme.fontSizeMedium
                color: Theme.primaryColor
            }
        }

        Title{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: iconDrDonut.top
            anchors.margins: Theme.paddingLarge
        }

        Image{
            id: iconDrDonut
            source:"qrc:///qml/images/drDonut.png"
            width: Theme.itemSizeExtraLarge * 1.8
            height: iconDrDonut.width * 1.2
            anchors{
                horizontalCenter: parent.horizontalCenter
                margins: Theme.paddingLarge
                verticalCenter: parent.verticalCenter
            }
        }

        Button
        {
            id:buttonPlay
            text: qsTr("Play")
            anchors{
                top: iconDrDonut.bottom
                horizontalCenter: parent.horizontalCenter
                margins: Theme.paddingLarge * 2
            }
            onClicked: {
                if(application.launchGame())
                {
                    pageStack.push(Qt.resolvedUrl("../pages/ChoiceGameModePage.qml"))
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
                top: buttonPlay.bottom
                horizontalCenter: parent.horizontalCenter
                margins: Theme.paddingLarge * 2
            }
            onClicked: pageStack.push(Qt.resolvedUrl("../pages/OptionPage.qml"))
        }

    }
}

