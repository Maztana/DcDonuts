import QtQuick 2.0
import Sailfish.Silica 1.0

Item{

    id:item

    property alias signe : textSigne.icon.source
    property alias xText : textSigne.x
    property alias yText : textSigne.y

    property bool isClicked : false

    width: parent.width
    height: parent.height

    Switch {
        id:textSigne
    }
}
