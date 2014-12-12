import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    SilicaListView {
        anchors.fill: parent
        model: flashcardsListModel

        header: PageHeader { title: qsTr("Flashcard") }

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: flashcardListItem
            Label
            {
                text: modelData
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
                gameType.initDB(modelData + ".db")
                gameType.launchGame()

                pageStack.replace(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
            }
        }
    }
}
