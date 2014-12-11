import QtQuick 2.0
import Sailfish.Silica 1.0


Item{
    property variant textAnswer

    anchors.horizontalCenter: parent.horizontalCenter
    width: line1.width
    height: line1.height + line2.height + scoreLabel.height

    Row{

        id:line1
        anchors.bottom : line2.top
        anchors.margins: Theme.paddingLarge
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
        anchors.bottom : scoreLabel.top
        anchors.bottomMargin: Theme.paddingLarge * 1.5

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

    /*----------------------- Score -----------------------*/
    Label{
        id: scoreLabel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Theme.paddingLarge
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: Theme.fontSizeExtraLarge
        text: "Score: "+ currentProfile.score + " Donut(s)"

        height: Theme.fontSizeLarge
        width: item.width - Theme.paddingLarge * 2
        fontSizeMode: Text.Fit
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }
}
