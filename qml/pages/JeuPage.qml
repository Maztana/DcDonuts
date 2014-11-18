import QtQuick 2.0
import Sailfish.Silica 1.0
import "../templatesReponses"
import "../Components"


Page {
    id: pageJeu

    SilicaFlickable {
        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader {
            title: application.nameProfil
        }

        Label {
            id: niveau
            text: qsTr("Niveau : ") + partie.niveau
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
                top: niveau.bottom
                margins:20
            }

            Text {
                id: libelleQuestion
                text: question.libelle + " ?"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter : parent.verticalCenter
                font.pointSize: 40
                font.bold: true
            }
        }
        /*---------------------------------------------------------*/

        /* --------- Bulles ---------- */
        Rectangle{
            id: bulle1
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
            id: bulle2
            width: 30
            height: 30
            radius: 1000
            x: bulle1.x + bulle1.width
            anchors{
                top:bulle1.bottom
                margins:10
            }
        }

        Rectangle{
            id: bulle3
            width: 25
            height: 25
            radius: 1000
            x : bulle2.x + bulle2.width + 15
            anchors{
                top:bulle2.bottom
                margins:6
            }
        }
        /* --------------------------- */



        /*------------------- Dr Donut --------------------*/
        Image{
            id: drDonut
            source: "qrc:///qml/images/drDonut.png"
            x: bulle3.x + bulle3.width + 30
            y: bulle1.y
            width:sourceSize.width/2
            height:sourceSize.height/2
        }
        /*-------------------------------------------------*/

        /*------------------- Réponses --------------------*/


        Column{
            id: panelReponse

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: drDonut.bottom
            width: parent.width

            /*ReponseSaisie
            {

            }*/

            Reponse4Propositions{
                id: responses
                textReponse1: questionnaireEducatif.proposition1
                textReponse2: questionnaireEducatif.proposition2
                textReponse3: questionnaireEducatif.proposition3
                textReponse4: questionnaireEducatif.proposition4
            }

        }


        /*-------------------------------------------------*/

        /*----------------------- Score -----------------------*/
        Label{
            anchors.top: panelReponse.bottom
            anchors.margins: 340
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 40
            text: "Score: "+ partie.score + " Donuts"

        }
    }
}

