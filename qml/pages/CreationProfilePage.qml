import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    id: dialog
    canAccept: !nameInput.errorHighlight

    acceptDestination: Qt.resolvedUrl("../homepage/Homepage.qml")
    acceptDestinationAction: PageStackAction.Replace
    acceptDestinationReplaceTarget: acceptDestinationInstance


    onAccepted: {
        application.createProfile(nameInput.text)
    }

    DialogHeader {
        defaultAcceptText: qsTr("Accept")
        cancelText: qsTr("Cancel")
    }

    Column{
        anchors.margins: Theme.paddingLarge * 6
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: rowName.width
        Row{
            id:rowName
            anchors.horizontalCenter: parent.horizontalCenter
            width:Screen.width - Theme.paddingLarge * 2

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
