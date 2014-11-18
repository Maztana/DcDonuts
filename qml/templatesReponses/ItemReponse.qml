import QtQuick 2.0
import Sailfish.Silica 1.0

Item {

    property alias rep: labelRep.text
    property int indexRep

    anchors.centerIn: parent
    anchors.fill: parent

    Label{
        id: labelRep
        anchors.centerIn: parent

        font.bold: true
        font.pixelSize: 60
        color: questionnaireEducatif.colorRep1
        /*{
            if(indexRep == 1)
            {
                console.log("je suis dans couleur 1" + questionnaireEducatif.colorRep1)
                return questionnaireEducatif.colorRep1
            }
            else if(indexRep == 2)
            {
                questionnaireEducatif.colorRep2
            }
            else if(indexRep == 3)
            {
                questionnaireEducatif.colorRep3
            }
            else if(indexRep == 4)
            {
                questionnaireEducatif.colorRep4
            }
        }*/
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(labelRep.text)
            questionnaireEducatif.traitResponse(labelRep.text)
        }
    }
}
