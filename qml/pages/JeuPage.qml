import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    SilicaFlickable {
        anchors.fill: parent
        contentWidth: parent.width
        contentHeight: col.height + Theme.paddingSmall

        VerticalScrollDecorator {}

        Column {
            id: col
            spacing: Theme.paddingMedium
            width: parent.width

            PageHeader {
                title: "JOUEUR X"
            }

            Label {
                id: niveau
                text: "Niveau : Facile"
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: Theme.fontFamilyHeading
            }

            /* --------------------- Question --------------------- */
            Rectangle{
                id :rectangleQuestion
                width: parent.width - 4* Theme.paddingLarge
                height: 150
                radius: 20
                color: '#F8F8FF'
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: question
                    text: "1 + 2 = ?"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter : parent.verticalCenter
                    font.pointSize: 40
                    font.bold: true
                }
            }
            /*---------------------------------------------------------*/

            /* --------- Bulles ---------- */
            Rectangle{
                width: 50
                height: 50
                radius: 1000
                x : rectangleQuestion.x + 100
                y : y *0.97

            }

            Rectangle{
                width: 30
                height: 30
                radius: 1000
                x : rectangleQuestion.x + 140
                y : y *0.94
            }

            Rectangle{
                width: 25
                height: 25
                radius: 1000
                x : rectangleQuestion.x + 172
                y : y *0.905
            }
            /* --------------------------- */



            /*------------------- Dr Donut --------------------*/
            Image{

                id: drDonut
                source: "../images/DoctorDonut_terminator.png"
                width: 195
                height: 220

                x: rectangleQuestion.x + rectangleQuestion.width - drDonut.width
                y:y/1.4

            }
            /*-------------------------------------------------*/

            /*------------------- Réponses --------------------*/
            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                Rectangle{
                    id:reponse1

                    width: 200
                    height:100


                    color: 'blue'

                    MouseArea{
                        anchors.fill: parent
                        onClicked: console.log(reponse1.x)
                    }

                }

                Rectangle{
                    id:reponse2
                    width: 200
                    height:100

                    MouseArea{
                        anchors.fill: parent
                        onClicked: console.log(reponse2.x)
                    }

                }
            }

            Row{
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10

                Rectangle{
                    id:reponse3

                    width: 200
                    height:100

                    MouseArea{
                        anchors.fill: parent
                        onClicked: console.log("uyfliyflufl")
                    }

                }
                Rectangle{
                    id:reponse4

                    width: 200
                    height:100

                    MouseArea{
                        anchors.fill: parent
                        onClicked: console.log("uyfliyflufl")
                    }

                }
            }

            /*-------------------------------------------------*/


        }

    }

}
