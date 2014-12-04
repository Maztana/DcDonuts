import QtQuick 2.0
import Sailfish.Silica 1.0

DockedPanel {
    id: root

    width: Screen.width
    height: content.height + 2*Theme.paddingSmall
    visible: false

    dock: Dock.Left

    Rectangle {
        id: content
        x: Theme.paddingSmall
        y: Theme.paddingSmall

        width: parent.width - 2*Theme.paddingSmall
        height: Screen.height/4

        color: 'black';
        opacity: 0.85;

        Label {
            id: infoLabel
            color: Theme.highlightColor
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontSizeLarge
            width: parent.width - 2*Screen.width/6
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
        }
    }

    function displayMsg(msg) {
        infoLabel.text = msg
        root.visible = true
        root.show()
        autoClose.start()
    }

    function close()
    {
        root.hide()
        autoClose.stop()
    }

    Timer {
        id: autoClose
        interval: 4000
        running: false
        onTriggered: {
            root.hide()
            stop()
        }
    }
}
