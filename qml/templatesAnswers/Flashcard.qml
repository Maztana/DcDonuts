import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    property variant textAnswer
    property bool isTreat : false
    property string textLabel : qsTr("Show the answer")

    id: item
    height: parent.height / 3
    width: parent.width
    anchors.fill: parent

    Label{
        id: labelFlashcard
        text: textLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: evaluationPanel.top
        anchors.margins: Theme.paddingSmall
        height: evaluationPanel.open ? Theme.fontSizeHuge + Theme.paddingMedium : item.height - evaluationPanel.height - Theme.paddingLarge * 5
        width: item.width - Theme.paddingLarge * 2

        color: Theme.secondaryHighlightColor
        font.pixelSize: Theme.fontSizeHuge
        fontSizeMode: Text.Fit
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        onClicked:{
            if(!isTreat)
            {
                labelFlashcard.color = Theme.primaryColor
                labelFlashcard.font.bold = true
                labelFlashcard.text = textAnswer[0]
                evaluationPanel.open = true
                isTreat = true
            }
        }
    }

    DockedPanel {
        id: evaluationPanel
        width: parent.width
        height: columnButtons.height + Theme.paddingLarge
        open: false
        dock: Dock.Bottom

        Column{
            id: columnButtons
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: Theme.paddingMedium

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: Theme.paddingLarge * 5

                IconButton {
                    id: iconButtonForgotten
                    width: icon.width
                    height: icon.height + textForgotten.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(0)
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: width
                        source: "../images/forgotten.png"
                    }

                    Text{
                        id: textForgotten
                        text: qsTr("Not at all")
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
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: width
                        source: "../images/inAcquisition.png"
                    }

                    Text{
                        id: textInAcquisition
                        text: qsTr("Not still")
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
                spacing: Theme.paddingLarge * 5

                IconButton {
                    id: iconButtonKnown
                    width: icon.width
                    height: icon.height + textKnown.height
                    smooth: true
                    onClicked: {
                        gameType.treatAnswer(2)
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: width
                        source: "../images/known.png"
                    }

                    Text{
                        id: textKnown
                        text: qsTr("Almost")
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
                    }

                    icon{
                        width: Theme.iconSizeLarge
                        height: width
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
            labelFlashcard.color = Theme.secondaryHighlightColor
            labelFlashcard.font.bold = false
            labelFlashcard.text = textLabel
            evaluationPanel.open = false
            isTreat = false
        }
        onAnswerGiven: mouseArea.enabled = false;
    }
}



