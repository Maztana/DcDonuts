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
                title: qsTr("Règles du jeu")
            }

            TextEdit{
                id:introQuiz
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeExtraSmall
                color:Theme.primaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("Ensemble de jeux éducatifs permettant d'apprendre en s'amusant. Afin d'y jouer, choisissez un mode de jeu (Calcul, Couleur, etc. ...), puis votre difficulté*.")
                readOnly: true
            }

            TextEdit{
                id:expdifficult
                x: Theme.paddingLarge
                font.italic: true
                font.pixelSize: Theme.fontSizeTiny
                color:Theme.primaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("* Difficulté : 4 difficultés sont disponibles: Facile, Moyen, Difficile et Automatique. Automatique se règle en fonction des résultats du joueur pour être le plus adapté possible à son niveau.")
                readOnly: true
            }

            SectionHeader {
                id:calculsection
                text: qsTr("Calcul")
                font.pixelSize: Theme.fontSizeMedium
            }

            TextEdit{
                id:calculrules
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeSmall
                color:Theme.secondaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("Sélectionnez les opérations sur lesquelles vous souhaitez progresser. Une question sera posée avec un ensemble de propositions de réponses, ou une proposition de saisie (selon la difficulté). Appuyez sur la réponse qui vous semble juste . La correction sera affichée. Si vous donnez une bonne réponse vous cumulerez des donuts, si vous en donnez une mauvaise vous en perdrez.")
                readOnly: true
            }

            SectionHeader {
                id:flashcardsection
                text: qsTr("Flashcard")
                font.pixelSize: Theme.fontSizeMedium
            }

            TextEdit{
                id:flashcardrules
                x: Theme.paddingLarge
                font.pixelSize: Theme.fontSizeSmall
                color:Theme.secondaryColor
                wrapMode: TextEdit.WordWrap
                width: parent.width - 2 * Theme.paddingLarge
                text: qsTr("Sélectionnez la série de flashcard que vous souhaitez. Une question sera posée; une fois que vous pensez avoir la réponse (ou si vous ne trouvez pas), appuyez sur l'écran afin d'afficher la réponse. Des propositions d'auto évaluation vous seront proposées. Choisissez celle qui vous semble la plus adaptée à votre cas. En revanche, ce type de jeu ne permet pas de cumuler des donuts.")
                readOnly: true
            }


        }
    }
}


