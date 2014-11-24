import QtQuick 2.0
import Sailfish.Silica 1.0



Item{
    property alias textAnswer1 : ans1.answer
    property alias textAnswer2 : ans2.answer

    anchors.horizontalCenter: parent.horizontalCenter
    width: line.width
    anchors.top: parent.top
    anchors.margins: 90

    Row{
        id: line
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
}
