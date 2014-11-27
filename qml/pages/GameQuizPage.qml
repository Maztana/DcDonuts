import QtQuick 2.0
import Sailfish.Silica 1.0
import "../templatesAnswers"


Page {
    id: pageJeu

    SilicaFlickable {
        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader {
            title: currentProfile.name
        }

        Label {
            id: level
            text: qsTr("Niveau : ") + game.level
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: Theme.paddingLarge * 4
            anchors.top: parent.top
            font.family: Theme.fontFamilyHeading
        }

        /* --------------------- Question --------------------- */
        Rectangle{
            id :rectangleQuestion
            width: Screen.width-40
            height: 150
            radius: 20
            color: Theme.primaryColor
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: level.bottom
                margins:Theme.paddingMedium * 2
            }

            Text {
                id: descriptionQuestion
                text: question.description + " ?"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter : parent.verticalCenter
                font.pixelSize: Theme.fontSizeHuge
                font.bold: true
            }
        }
        /*---------------------------------------------------------*/

        /* --------- Bulles ---------- */
        Rectangle{
            id: bubble1
            width: drDonut.width/5
            height: bubble1.width
            radius: 1000
            anchors{
                top: rectangleQuestion.bottom
                right: bubble2.left
                topMargin: Theme.paddingSmall
            }
        }

        Rectangle{
            id: bubble2
            width: bubble1.width / 1.5
            height: bubble2.width
            radius: 1000
            anchors{
                verticalCenter: bubble1.bottom
                right: bubble3.left
                margins: Theme.paddingSmall
            }
        }

        Rectangle{
            id: bubble3
            width: bubble2.width / 1.5
            height: bubble3.width
            radius: 1000
            anchors{
                verticalCenter: bubble2.bottom
                right: drDonut.left
                margins: Theme.paddingSmall
            }
        }
        /* --------------------------- */


        /*------------------- Dr Donut --------------------*/
        Image{
            id: drDonut
            source: "qrc:///qml/images/drDonut.png"
            anchors{
                right: rectangleQuestion.right
                top: rectangleQuestion.bottom
                topMargin: Theme.paddingMedium * 4
                rightMargin: Theme.paddingSmall
            }

            width: Theme.iconSizeLarge * 2.2
            height: drDonut.width
        }
        /*-------------------------------------------------*/

        /*------------------- Réponses --------------------*/

        FourPropositions{
            id: answers
            anchors.bottom: scoreLabel.top
            anchors.bottomMargin: Theme.paddingLarge * 3
            textAnswer1: educationQuiz.proposition1
            textAnswer2: educationQuiz.proposition2
            textAnswer3: educationQuiz.proposition3
            textAnswer4: educationQuiz.proposition4
        }

        /*-------------------------------------------------*/

        /*----------------------- Score -----------------------*/
        Label{
            id: scoreLabel
            anchors.bottom: parent.bottom
            anchors.margins: Theme.paddingLarge
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: Theme.fontSizeExtraLarge
            text: "Score: "+ currentProfile.score + " Donut(s)"
        }
    }
}

