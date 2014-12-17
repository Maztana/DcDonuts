import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    SilicaListView {
        anchors.fill: parent
        model: flashcardsListModel

        PullDownMenu {
            MenuItem {
                text: qsTr("Import flashcards")
                onClicked: pageStack.push(Qt.resolvedUrl("../pages/ImportFlashcardPage.qml"))
            }
        }

        header: PageHeader { title: qsTr("Flashcard") }

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: flashcardListItem
            menu:flashcardOptionsMenu
            Label
            {
                id: nameFlashcard
                text: getName()
                anchors.verticalCenter: parent.verticalCenter
            }

            anchors
            {
                left: parent.left
                right: parent.right
                margins: Theme.paddingLarge
            }

            onClicked: {
                //Init name of BDD
                gameType.initDB(modelData)
                gameType.launchGame()

                pageStack.replace(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
            }

            Component {
                id: flashcardOptionsMenu
                ContextMenu {
                    MenuItem {
                        text: qsTr("Reinitialize")
                        onClicked: {

                            application.resetStatsFlashcardProfile(nameFlashcard.text, currentProfile.id)

                        }
                    }
                }
            }
        }
    }
}

