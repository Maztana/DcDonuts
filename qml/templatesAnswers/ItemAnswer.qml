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
        /*---------------------------------- Image correction ----------------------------------*/
        Image{
            id:imgreponse
            state: "default"
            anchors.centerIn: parent
            opacity:0.4

            states:[
                State
                {
                    name:"default"
                    PropertyChanges { target:imgreponse; source:""}
                },
                State
                {
                    name:"right"
                    PropertyChanges { target:imgreponse; source:"qrc:///qml/images/smiley_good.png"; rotation: 360}
                },
                State
                {
                    name:"wrong"
                    PropertyChanges { target:imgreponse; source:"qrc:///qml/images/smiley_bad.png"; rotation: 360}
                }
            ]
            transitions:[
                Transition {
                    from: "default"
                    to: "wrong"
                    SequentialAnimation{
                        NumberAnimation{ property: "rotation"; duration: 1200; easing.type: Easing.OutQuad  }
                    }
                },
                Transition {
                    from: "default"
                    to: "right"

                    SequentialAnimation{
                        NumberAnimation{ property: "rotation"; duration: 1200; easing.type: Easing.OutQuad  }
                        ScriptAction{
                            script:{educationQuiz.answersReset()}
                        }
                    }
                },
                Transition {
                    from: "right"
                    to: "default"

                    SequentialAnimation{
                        ScriptAction{
                            script:{educationQuiz.launchQuestion()}
                        }
                    }
                },
                Transition {
                    from: "wrong"
                    to: "default"
                }
            ]
        }
        /*----------------------------------------------------------------------------------------------------*/

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
                educationQuiz.traitAnswer(indexAnswers)
            }
        }
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
                changeColor("right")
            }
        }
        onAnswerWrong:{
            if(index === indexAnswers)
            {
                changeColor("wrong")
            }
        }
        onResetAnswer:{
            if(index === indexAnswers)
            {
                changeColor("default")
            }
        }
    }

    function changeColor(etat)
    {
        imgreponse.state = etat
    }
}
