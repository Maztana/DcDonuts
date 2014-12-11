import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    property variant textAnswer
    property bool isTreat : false
    property string textLabel : "???"

    height: parent.height / 3
    width: parent.width
    anchors.fill: parent

    Label{
        id: labelFlashcard
        text: textLabel
        anchors.bottom: evaluationPanel.top
        font.pixelSize: evaluationPanel.open ? Theme.fontSizeMedium : Theme.fontSizeHuge
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: evaluationPanel.open ? Theme.paddingSmall : parent.parent.height / 4
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        onClicked:{
            if(!isTreat)
            {
                labelFlashcard.text = textAnswer[0]
                evaluationPanel.open = true
                isTreat = true
            }
        }
    }

    DockedPanel {
        id: evaluationPanel
        width: parent.width
        height: columnButtons.height + Theme.paddingLarge * 2
        open: false
        dock: Dock.Bottom

        Column{
            id: columnButtons
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: Theme.paddingLarge

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Theme.paddingLarge * 4

                IconButton {
                    id: iconButtonForgotten
                    width: icon.width
                    height: icon.height + textForgotten.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(0)
                        gameType.launchQuestion()
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: iconButtonForgotten.icon.width * 0.8
                        source: "../images/forgotten.png"
                    }

                    Text{
                        id: textForgotten
                        text: qsTr("Forgotten")
                        anchors.top: parent.icon.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.family: Theme.fontFamilyHeading
                        font.pixelSize: Theme.fontSizeMedium
                        color: Theme.primaryColor
                    }
                }

                IconButton {
                    id: iconButtonInAcquisition
                    width: icon.width
                    height: icon.height + textInAcquisition.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(1)
                        gameType.launchQuestion()
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: iconButtonInAcquisition.icon.width * 0.8
                        source: "../images/inAcquisition.png"
                    }

                    Text{
                        id: textInAcquisition
                        text: qsTr("In acquisition")
                        anchors.top: parent.icon.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.family: Theme.fontFamilyHeading
                        font.pixelSize: Theme.fontSizeMedium
                        color: Theme.primaryColor
                    }
                }
            }

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Theme.paddingLarge * 4

                IconButton {
                    id: iconButtonKnown
                    width: icon.width
                    height: icon.height + textKnown.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(2)
                        gameType.launchQuestion()
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: iconButtonKnown.icon.width * 0.8
                        source: "../images/known.png"
                    }

                    Text{
                        id: textKnown
                        text: qsTr("Known")
                        anchors.top: parent.icon.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.family: Theme.fontFamilyHeading
                        font.pixelSize: Theme.fontSizeMedium
                        color: Theme.primaryColor
                    }
                }

                IconButton {
                    id: iconButtonPerfect
                    width: icon.width
                    height: icon.height + textPerfect.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(3)
                        gameType.launchQuestion()
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: iconButtonPerfect.icon.width * 0.8
                        source: "../images/perfect.png"
                    }

                    Text{
                        id: textPerfect
                        text: qsTr("Perfect")
                        anchors.top: parent.icon.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.family: Theme.fontFamilyHeading
                        font.pixelSize: Theme.fontSizeMedium
                        color: Theme.primaryColor
                    }
                }
            }
        }
    }


    Connections{
        target: gameType
        onQuestionChanged: {
            mouseArea.enabled = true
            labelFlashcard.text = textLabel
            evaluationPanel.open = false
            isTreat = false
        }
        onAnswerGiven: mouseArea.enabled = false;
    }
}



