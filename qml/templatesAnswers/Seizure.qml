import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    width: parent.width

    TextField {
        color: Theme.highlightColor
        focus:true
        width: parent.width
        inputMethodHints: Qt.ImhDigitsOnly
        placeholderText: qsTr("Entrez votre réponse")
        placeholderColor: Theme.highlightColor
        cursorColor: Theme.highlightColor

        EnterKey.enabled: text.length > 0
        EnterKey.text : "OK"
        EnterKey.onClicked: console.log(text)
    }
}
