import QtQuick 2.0
import Sailfish.Silica 1.0



Item{
    property alias textAnswer1 : ans1.answer
    property alias textAnswer2 : ans2.answer

    anchors.horizontalCenter: parent.horizontalCenter
    width: line.width
    height: line1.height + line2.height
    anchors.margins: Theme.paddingLarge * 2

    Row{
        id: line
        spacing: 20

        ItemAnswer{
            id: ans1
            indexAnswers: 1
        }

        ItemAnswer{
            id: ans2
            indexAnswers: 2
        }
    }
}
