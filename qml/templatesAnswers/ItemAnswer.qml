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
            font.pixelSize: Theme.fontSizeHuge
            color: "black"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                educationQuiz.treatAnswer(indexAnswers)
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
        onQuestionChanged: answer.enabled = true
        onAnswerGiven: answer.enabled = false;

        onAnswerRight:{
            if(index === indexAnswers)
            {
                managerValidation(1)
            }
        }
        onAnswerWrong:{
            if(indexWrong === indexAnswers)
            {
                managerValidation(2)
            }
            if(indexRight === indexAnswers)
            {
                managerValidation(1)
            }
        }
        onResetAnswer:{
            if(index === indexAnswers)
            {
                managerValidation(0)
            }
        }
    }

    function managerValidation(indexTreatment)
    {
        switch (indexTreatment){
        case 1:
            answer.state = "green"
            break
        case 2:
            answer.state = "red"
            break
        default:
            answer.state = "white"
            break
        }
    }
}
