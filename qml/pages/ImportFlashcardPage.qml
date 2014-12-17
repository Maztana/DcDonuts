import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    PageHeader{
        title: qsTr("Import flashcards")
    }

    TextEdit{
         id: explication
         x: Theme.paddingLarge
         anchors.topMargin: Theme.paddingLarge * 6
         anchors.top: parent.top
         text: qsTr("importFlashExp")
         color: Theme.secondaryColor
         wrapMode: TextEdit.WordWrap
         width:parent.width - 2 * Theme.paddingLarge
         readOnly: true
    }

    Text{
        id: textLiens
        x: Theme.paddingLarge
        anchors.top: explication.bottom
        anchors.topMargin: Theme.paddingLarge * 2
        text: qsTr('importFlashTxtLinks')
        color: Theme.secondaryColor
        font.italic: true
        wrapMode: TextEdit.WordWrap
        width:parent.width - 2 * Theme.paddingLarge
    }
    Text{
        id: lien
        x: Theme.paddingLarge
        anchors.top: textLiens.bottom
        text: '<html><a href="http://anymemo.org/index.php?page=databases">AnyMemo.org</a></html>'
        color: Theme.secondaryColor
        font.italic: true
        wrapMode: TextEdit.WordWrap
        width:parent.width - 2 * Theme.paddingLarge
        onLinkActivated: Qt.openUrlExternally("http://anymemo.org/index.php?page=databases")
    }

}
