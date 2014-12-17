import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    onStatusChanged: addItems()

    SilicaListView {
        property bool canLaunch : true

        id: flashcardsList
        anchors.fill: parent
        model: listModel

        header: PageHeader { title: qsTr("Flashcard") }

        ViewPlaceholder {
            enabled: flashcardsList.count == 0
            text: qsTr("No existing flashcard base")
            hintText: qsTr("Pull down to import")
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Import flashcards")
                onClicked: pageStack.push(Qt.resolvedUrl("../pages/ImportFlashcardPage.qml"))
            }
        }

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: flashcardListItem
            menu:flashcardOptionsMenu

            anchors
            {
                left: parent.left
                right: parent.right
                margins: Theme.paddingLarge
            }

            onClicked: {
                if(flashcardsList.canLaunch)
                {
                    //Init name of BDD
                    gameType.initDB(url, name)
                    gameType.launchGame()

                    pageStack.replace(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                }
            }

            function reset() {
                remorseAction(qsTr("Reinitialization"), function()
                {
                    application.resetStatsFlashcardProfile(nameFlashcard.text, currentProfile.id)
                })
            }

            function remove() {
                flashcardsList.canLaunch = false
                remorseAction(qsTr("Deleting"), function()
                {
                    application.deleteFlashcardFile(index)
                    listModel.remove(index)
                    flashcardsList.canLaunch = true
                })
            }

            Label
            {
                id: nameFlashcard
                text: model.name
                anchors.verticalCenter: parent.verticalCenter
            }

            Component {
                id: flashcardOptionsMenu
                ContextMenu {
                    MenuItem {
                        text: qsTr("Reinitialize")
                        onClicked: {
                            reset()
                        }
                    }
                    MenuItem {
                        text: qsTr("Delete")
                        onClicked: {
                            remove()
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
