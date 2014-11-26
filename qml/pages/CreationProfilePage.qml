import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    id: dialog
    canAccept: !nameInput.errorHighlight

    onAccepted: {
        application.createProfile(nameInput.text)
    }

    DialogHeader {
        defaultAcceptText: qsTr("Valider")
        cancelText: qsTr("Annuler")
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
                label: qsTr("Nom")
                placeholderText: qsTr("Tapez votre nom")
                validator: RegExpValidator { regExp: /^[a-zA-Z]{2,}$/ }
                EnterKey.text : "OK"
                EnterKey.onClicked: parent.focus = true

            }
        }
    }
}



