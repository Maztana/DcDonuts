import QtQuick 2.0
import QtMultimedia 5.0
import Sailfish.Silica 1.0

Item {

    property alias answer: labelAnswer.text
    property int indexAnswers

    width: 200
    height:100

    Rectangle{
        id:answer
        anchors.fill: parent

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
    }

    Connections{
        target: educationQuiz
        onQuestionChanged: answer.enabled = true
        onAnswerGiven: answer.enabled = false;

        onAnswerRight:{
            if(index !== indexAnswers)
            {
                notSelected()
            }
            else
            {
                answer.color = "Lime"
                answer.opacity = 0.8

                if(application.isSoundActive())
                {
                    soundRight.play()
                }
            }
        }
        onAnswerWrong:{
            if(index !== indexAnswers)
            {
                notSelected()
            }
            else
            {
                answer.color = "OrangeRed"
                answer.opacity = 0.8

                if(application.isSoundActive())
                {
                    soundWrong.play();
                }
            }
        }
        onCorrectedAnswer:{
            reset()
            if(index !== indexAnswers)
            {
                notSelected()
            }
            else
            {
                answer.color = "Lime"
                answer.opacity = 0.8
            }
        }
        onResetAnswer:{
                reset()
        }
    }

    function notSelected()
    {
        answer.color = Theme.secondaryHighlightColor
        answer.opacity = 0.5
    }

    function reset()
    {
        answer.color = "white"
        answer.opacity = 1
    }

    SoundEffect
    {
        id: soundRight
        source: "qrc:///qml/sounds/soundRight.wav"
    }

    SoundEffect
    {
        id: soundWrong
        source: "qrc:///qml/sounds/soundWrong.wav"
    }
}
