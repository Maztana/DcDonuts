import QtQuick 2.0
import Sailfish.Silica 1.0

Item {

    property alias rep: labelRep.text

    anchors.centerIn: parent
    anchors.fill: parent

    Label{
        id: labelRep
        anchors.centerIn: parent

        font.bold: true
        font.pixelSize: 60
        color: "black"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(labelRep.text)
            questionnaireEducatif.traitResponse(labelRep.text)
        }
    }
}
