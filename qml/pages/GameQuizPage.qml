import QtQuick 2.0
import Sailfish.Silica 1.0
import "../templatesAnswers"

Page {
    id: pageJeu

    function loadAnswers(nbPropositions)
    {
        if(gameType.isQuiz())
        {
            var obj
            if(gameType.isFlashcard())
            {
                obj = 'import "../templatesAnswers"; import Sailfish.Silica 1.0; Flashcard {id: answers; anchors.bottom: parent.bottom; textAnswer: gameType.propositions}';
            }
            else
            {
                obj = 'import "../templatesAnswers"; import Sailfish.Silica 1.0; FourPropositions {id: answers; anchors.bottom: parent.bottom; textAnswer: gameType.propositions}';
            }
            Qt.createQmlObject(obj, pageJeu, "dynamicAnswers");
        }
    }

    SilicaFlickable {
        anchors.fill: parent
        id:sf

        VerticalScrollDecorator {}

        PageHeader {
            title: currentProfile.name
        }

        Label {
            id: level
            text: {
                if(gameType.isFlashcard())
                {
                    gameType.level
                }
                else
                {
                    qsTr("Level : ") + gameType.level
                }
            }
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
                text: gameType.textQuestion + " ?"
                anchors.centerIn: parent
                height: rectangleQuestion.height - Theme.paddingLarge * 2
                width: rectangleQuestion.width - Theme.paddingLarge * 2

                font.pixelSize: Theme.fontSizeHuge
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
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
                topMargin: Theme.paddingMedium * 2
                rightMargin: Theme.paddingSmall
            }
            width: Theme.iconSizeLarge * 2
            height: drDonut.width * 1.2
        }
        /*-------------------------------------------------*/

        /*---------------------------------- Image correction ----------------------------------*/
        Image{
            id:imgreponse
            state: "default"
            anchors{
                verticalCenter: drDonut.verticalCenter
                right: bubble1.left
                topMargin: Theme.paddingMedium * 2
                rightMargin: Theme.paddingSmall
            }
            opacity:1

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
                        ScriptAction{
                            script:{gameType.answersCorrected()}
                        }
                    }
                },
                Transition {
                    from: "default"
                    to: "right"
                    SequentialAnimation{
                        NumberAnimation{ property: "rotation"; duration: 1200; easing.type: Easing.OutQuad  }
                        ScriptAction{
                            script:{imgreponse.state = "default"}
                        }
                    }
                },
                Transition {
                    from: "wrong"
                    to: "right"
                    SequentialAnimation{
                        NumberAnimation{ property: "rotation"; duration: 1200; easing.type: Easing.OutQuad  }
                        ScriptAction{
                            script:{imgreponse.state = "default"}
                        }
                    }
                },
                Transition {
                    from: "right"
                    to: "default"
                    SequentialAnimation{
                        ScriptAction{
                            script:{gameType.launchQuestion()}
                        }
                    }
                }
            ]
        }
        /*----------------------------------------------------------------------------------------------------*/

        /*------------------- Réponses --------------------*/
        Component.onCompleted: {
            loadAnswers(gameType.numberPropositions);
        }
        /*-------------------------------------------------*/
    }

    Connections{
        target: gameType
        onAnswerRight: imgreponse.state = "right"
        onAnswerWrong: imgreponse.state = "wrong"
        onCorrectedAnswer: imgreponse.state = "right"
    }
}

