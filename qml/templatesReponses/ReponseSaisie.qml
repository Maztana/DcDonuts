import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    TextField {
        width: parent.width
        inputMethodHints: Qt.ImhFormattedNumbersOnly
        label: "Number input"
        placeholderText: "Type number here"
        horizontalAlignment: textAlignment
        EnterKey.onClicked: parent.focus = true
    }
}
