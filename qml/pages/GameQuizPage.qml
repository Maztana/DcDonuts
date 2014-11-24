import QtQuick 2.0
import Sailfish.Silica 1.0
import "../templatesReponses"


Page {
    id: pageJeu

    SilicaFlickable {
        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader {
            title: application.nameProfile
        }

        Label {
            id: level
            text: qsTr("Niveau : ") + game.getLevelName()
            anchors.horizontalCenter: parent.horizontalCenter
            y:100
            font.family: Theme.fontFamilyHeading
        }

        /* --------------------- Question --------------------- */
        Rectangle{
            id :rectangleQuestion
            width: Screen.width-40
            height: 150
            radius: 20
            color: '#F8F8FF'
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: level.bottom
                margins:20
            }

            Text {
                id: descriptionQuestion
                text: question.description + " ?"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter : parent.verticalCenter
                font.pointSize: 40
                font.bold: true
            }
        }
        /*---------------------------------------------------------*/

        /* --------- Bulles ---------- */
        Rectangle{
            id: buble1
            width: 50
            height: 50
            radius: 1000
            x : rectangleQuestion.x + 130
            anchors{
                top:rectangleQuestion.bottom
                margins:10
            }
        }

        Rectangle{
            id: buble2
            width: 30
            height: 30
            radius: 1000
            x: buble1.x + buble1.width
            anchors{
                top:buble1.bottom
                margins:10
            }
        }

        Rectangle{
            id: buble3
            width: 25
            height: 25
            radius: 1000
            x : buble2.x + buble2.width + 15
            anchors{
                top:buble2.bottom
                margins:6
            }
        }
        /* --------------------------- */



        /*------------------- Dr Donut --------------------*/
        Image{
            id: drDonut
            source: "qrc:///qml/images/drDonut.png"
            x: buble3.x + buble3.width + 30
            y: buble1.y
            width:sourceSize.width/2
            height:sourceSize.height/2
        }
        /*-------------------------------------------------*/

        /*------------------- Réponses --------------------*/


        Column{
            id: panelAnswers

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: drDonut.bottom
            width: parent.width


            FourProposals{
                id: answers
                textAnswer1: educationQuiz.proposal1
                textAnswer2: educationQuiz.proposal2
                textAnswer3: educationQuiz.proposal3
                textAnswer4: educationQuiz.proposal4
            }

        }


        /*-------------------------------------------------*/

        /*----------------------- Score -----------------------*/
        Label{
            anchors.top: panelAnswers.bottom
            anchors.margins: 340
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 40
            text: "Score: "+ game.score + " Donuts"
        }
    }
}

