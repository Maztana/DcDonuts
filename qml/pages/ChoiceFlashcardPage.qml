import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    onStatusChanged: addItems()
    SilicaListView {
        anchors.fill: parent
        model: listModel

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
                text: model.name
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
                gameType.initDB(url, name)
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
                    MenuItem {
                        text: qsTr("Delete")
                        onClicked: {
                                application.deleteFlashcardFile(index)
                                listModel.remove(index)
                        }
                    }
                }
            }
        }
    }

    ListModel {
        id: listModel
    }

    function addItems() {

        listModel.clear();

        var flashcards = application.getListFlashcards();

        for(var i = 0; i < flashcards.length; i++)
        {
            var url = flashcards[i].getUrl()
            var name = flashcards[i].getName()
            listModel.append({"url": url, "name": name})
        }
    }
}

