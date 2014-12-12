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

        width: parent.width - Theme.paddingSmall * 2
        height: Screen.height/4

        color: 'black';
        opacity: 0.85;

        Label {
            id: infoLabel
            color: Theme.highlightColor
            anchors.centerIn: parent
            width: parent.width - Theme.paddingLarge * 4
            height: parent.height / 2

            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontSizeHuge
            fontSizeMode: Text.Fit
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
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
