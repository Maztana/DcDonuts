import QtQuick 2.0
import Sailfish.Silica 1.0

Page{

    PageHeader{
        title: qsTr("Add flashcard")
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: Theme.paddingLarge*10
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: Theme.paddingLarge*3

        Text{
            text: qsTr("txtAddFlashcard")
            anchors.horizontalCenter: parent.horizontalCenter
            width: Screen.width - Theme.paddingLarge * 3
            font.pixelSize: Theme.fontSizeMedium
            fontSizeMode: Text.Fit
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            verticalAlignment: Text.AlignVCenter
        }

        Button{
            text: qsTr("Add")
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
