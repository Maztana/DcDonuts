import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    id: dialog
    canAccept: !nameInput.errorHighlight

    onAccepted: {
        application.createProfile(nameInput.text)
    }

    DialogHeader {
        defaultAcceptText: qsTr("Accept")
        cancelText: qsTr("Cancel")
    }

    Column{
        anchors.fill : parent
        Row{
            id:rowName
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: Theme.paddingLarge * 6
            width:parent.width - Theme.paddingLarge * 2

            TextField{
                id:nameInput
                width:parent.width
                label: qsTr("Name")
                placeholderText: qsTr("Enter your name")
                validator: RegExpValidator { regExp: /^([a-zA-ZÀ-ÿ]+((-|\ )?[a-zA-ZÀ-ÿ]+)+)$/ }
                inputMethodHints: Qt.ImhNoPredictiveText
                EnterKey.text : "OK"
                EnterKey.onClicked: parent.focus = true
            }
        }
    }
}



