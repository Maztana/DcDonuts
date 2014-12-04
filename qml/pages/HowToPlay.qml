import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: howtoplay

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height + Theme.paddingLarge


        Column {
            id: column

            width: howtoplay.width
            spacing: Theme.paddingLarge
            PageHeader {
                title: qsTr("Game rules")
            }

            TextEdit{
                id:introQuiz
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeExtraSmall
                color:Theme.primaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("htpIntroText")
                readOnly: true
            }

            TextEdit{
                id:expDifficulties
                x: Theme.paddingLarge
                font.italic: true
                font.pixelSize: Theme.fontSizeTiny
                color:Theme.primaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("htpExpDifficultiesText")
                readOnly: true
            }

            SectionHeader {
                id:calculsection
                text: qsTr("Calculation")
                font.pixelSize: Theme.fontSizeMedium
            }

            TextEdit{
                id:calculationRules
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeSmall
                color:Theme.secondaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("htpCalculationRulesText")
                readOnly: true
            }

            SectionHeader {
                id:flashcardSection
                text: qsTr("Flashcard")
                font.pixelSize: Theme.fontSizeMedium
            }

            TextEdit{
                id:flashcardRules
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeSmall
                color:Theme.secondaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("htpFlashcardRulesText")
                readOnly: true
            }


        }
    }
}


