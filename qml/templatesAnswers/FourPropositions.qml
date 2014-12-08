import QtQuick 2.0
import QtMultimedia 5.0
import Sailfish.Silica 1.0


Item{
    property variant textAnswer

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
            answer: textAnswer[0]
        }

        ItemAnswer{
            id: ans2
            indexAnswers: 2
            answer: textAnswer[1]
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
            answer: textAnswer[2]
        }

        ItemAnswer{
            id: ans4
            indexAnswers: 4
            answer: textAnswer[3]
        }
    }
}
