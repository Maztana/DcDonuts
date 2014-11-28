import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    property alias textAnswer1 : ans1.answer
    property alias textAnswer2 : ans2.answer
    property alias textAnswer3 : ans3.answer
    property alias textAnswer4 : ans4.answer

    anchors.horizontalCenter: parent.horizontalCenter
    width: line1.width
    height: line1.height + line2.height
    anchors.margins: Theme.paddingLarge * 2

    Row{

        id:line1
        anchors.top : parent.top
        spacing: Theme.paddingLarge

        ItemAnswer{
            id: ans1
            indexAnswers: 1
        }

        ItemAnswer{
            id: ans2
            indexAnswers: 2
        }
    }

    Row{
        id: line2
        anchors.top : line1.bottom
        anchors.margins: Theme.paddingLarge

        spacing: Theme.paddingLarge

        ItemAnswer{
            id: ans3
            indexAnswers: 3
        }

        ItemAnswer{
            id: ans4
            indexAnswers: 4
        }
    }
}
