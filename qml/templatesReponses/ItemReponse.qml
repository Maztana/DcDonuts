import QtQuick 2.0
import Sailfish.Silica 1.0

Item {

    property alias rep: labelRep.text
    property int indexRep
    property alias color : reponse.color

    width: 200
    height:100

    Rectangle{
        id:reponse
        anchors.fill: parent
        state: "white"

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
                questionnaireEducatif.traitResponse(indexRep)
            }
        }

        states:[
            State
            {
                name:"white"
                PropertyChanges { target:reponse; color:"white"}
            },
            State
            {
                name:"green"
                PropertyChanges { target:reponse; color:"green"}
            },
            State
            {
                name:"red"
                PropertyChanges { target:reponse; color:"red"}
            }
        ]

        transitions:[
            Transition {
                from: "white"
                to: "red"
                SequentialAnimation{
                    ColorAnimation {duration: 400 }
                }
            },
            Transition {
                from: "white"
                to: "green"
                SequentialAnimation{
                    ColorAnimation {duration: 400 }
                    ScriptAction{
                        script:questionnaireEducatif.responseReset()
                    }
                }
            },
            Transition {
                from: "green"
                to: "white"
                SequentialAnimation{
                    ColorAnimation {duration: 600 }
                    ScriptAction{
                        script:questionnaireEducatif.lancerQuestion()
                    }
                }
            },
            Transition {
                from: "red"
                to: "white"
                SequentialAnimation{
                    ColorAnimation {duration: 600 }
                }
            }
        ]
    }

    Connections{
        target: questionnaireEducatif
        onResponseTrait:
        {
            if(reponse.enabled === true)
            {
                console.log(reponse.enabled)
                reponse.enabled = false
            }
            else
            {
                console.log(reponse.enabled)
                reponse.enabled = true
            }
        }
        onResponseTrue:{
            if(index === indexRep)
            {
                console.log(index)
                changeColor("green")
            }
        }
        onResponseFalse:{
            if(index === indexRep)
            {
                console.log(index)
                changeColor("red")
            }
        }
        onResetResponse:{
            if(index === indexRep)
            {
                console.log(index)
                changeColor("white")
            }
        }
    }

    function changeColor(nameColor)
    {
        console.log(nameColor + " " + indexRep)
        reponse.state = nameColor
    }
}
