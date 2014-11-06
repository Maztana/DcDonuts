import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    width: parent.width

    TextField {
        color: "black"
        focus:true
        width: parent.width
        inputMethodHints: Qt.ImhDigitsOnly
        placeholderText: "Entrez votre réponse"
        placeholderColor: "black"
        cursorColor: "black"

        EnterKey.enabled: text.length > 0
        EnterKey.text : "OK"
        EnterKey.onClicked: console.log(text)
    }
}
