import QtQuick 2.0
import Sailfish.Silica 1.0

Item {

    property alias answer: labelAnswer.text
    property int indexAnswers

    width: 200
    height:100

    Rectangle{
        id:answer
        anchors.fill: parent
        state: "white"

        Label{
            id: labelAnswer
            anchors.centerIn: parent

            font.bold: true
            font.pixelSize: 60
            color: "black"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                educationQuiz.traitAnswer(indexAnswers)
            }
        }

        states:[
            State
            {
                name:"white"
                PropertyChanges { target:answer; color:"white"}
            },
            State
            {
                name:"green"
                PropertyChanges { target:answer; color:"green"}
            },
            State
            {
                name:"red"
                PropertyChanges { target:answer; color:"red"}
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
                        script:educationQuiz.answersReset()
                    }
                }
            },
            Transition {
                from: "green"
                to: "white"
                SequentialAnimation{
                    ColorAnimation {duration: 600 }
                    ScriptAction{
                        script:educationQuiz.launchQuestion()
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
        target: educationQuiz
        onAnswerTrait:
        {
            if(answer.enabled === true)
            {
                answer.enabled = false
            }
            else
            {
                answer.enabled = true
            }
        }
        onAnswerRight:{
            if(index === indexAnswers)
            {
                changeColor("green")
            }
        }
        onAnswerWrong:{
            if(index === indexAnswers)
            {
                changeColor("red")
            }
        }
        onResetAnswer:{
            if(index === indexAnswers)
            {
                changeColor("white")
            }
        }
    }

    function changeColor(nameColor)
    {
        answer.state = nameColor
    }
}
