import QtQuick 2.0
import Sailfish.Silica 1.0


Item{

    property alias textAnswer1 : ans1.answer
    property alias textAnswer2 : ans2.answer
    property alias textAnswer3 : ans3.answer

    anchors.horizontalCenter: parent.horizontalCenter
    width: line1.width

    anchors.top: parent.top
    anchors.margins: 90

    Row{

        id:line1
        anchors.top : parent.top
        spacing: 20

        ItemReponse{
            id: ans1
            indexAnswers: 1
        }

        ItemReponse{
            id: ans2
            indexAnswers: 2
        }
    }

    Row{
        id: line2
        anchors.top: line1.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        ItemReponse{
            id: ans3
            indexAnswers: 3
        }
    }
}
