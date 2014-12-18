import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    id: pageChoiceFlashcard
    onStatusChanged: addItems()

    SilicaListView {

        id: flashcardsList
        anchors.fill: parent
        model: listModel

        property bool canLaunch : true

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

            /* Active Transition */
            function activeTransition() {
                flashcardsList.canLaunch = true
                pageChoiceFlashcard.backNavigation = true
                pageChoiceFlashcard.canNavigateForward = true
            }

            /* Desactive Transition */
            function deactiveTransition() {
                pageChoiceFlashcard.backNavigation = false
                pageChoiceFlashcard.canNavigateForward = false
                flashcardsList.canLaunch = false
            }

            /* Reset an BDD */
            function reset() {
                remorse.execute(flashcardListItem, qsTr("Reinitialization"), function()
                {
                    application.resetStatsFlashcardProfile(flashcardListItem.text, currentProfile.id)
                    activeTransition()
                })
            }

            /* Remove an item */
            function remove() {
                remorse.execute(flashcardListItem, qsTr("Deleting"), function()
                {
                    application.deleteFlashcardFile(index)
                    listModel.remove(index)
                    activeTransition()
                })
            }

            RemorseItem{
                id:remorse

                onCanceled: activeTransition()
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
                            deactiveTransition()
                            reset()
                        }
                    }
                    MenuItem {
                        text: qsTr("Delete")
                        visible: {
                            var reg = new RegExp("^\/usr\/share\/harbour-dr-donut\/db\/.*")
                            if(reg.test(model.url))
                            {
                                return false
                            }
                            else
                            {
                                return true
                            }
                        }
                        onClicked: {
                            deactiveTransition()
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
