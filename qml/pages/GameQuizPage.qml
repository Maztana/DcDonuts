import QtQuick 2.0
import Sailfish.Silica 1.0
import "../templatesAnswers"

Page {
    id: pageJeu

    function loadItemAnswers(nbPropositions)
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

    function loadItemQuestion()
    {
        if(gameType.isCounting())
        {
            descriptionQuestion.state = "descriptionQuestionStateCounting"
            formsDisplay.visible = true;
            var component = Qt.createComponent("FormDisplay.qml");
            if(component.status === Component.Ready)
            {
                component.createObject(formsDisplay, {"numberForms": parseInt(gameType.getResult())})
            }
        }
        else
        {
            descriptionQuestion.state = "descriptionQuestionStateNormal"
            formsDisplay.visible = false;
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
                    qsTr("Level") + " : " + gameType.level
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
                anchors.horizontalCenter: parent.horizontalCenter
                width: rectangleQuestion.width - Theme.paddingLarge * 2

                state: "descriptionQuestionStateNormal"

                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.bold: true

                states: [
                    State {
                        name: "descriptionQuestionStateNormal"
                        PropertyChanges{
                            target: descriptionQuestion
                            height: rectangleQuestion.height - Theme.paddingLarge;
                            font.pixelSize: Theme.fontSizeHuge
                            verticalAlignment: Text.AlignVCenter
                        }
                        AnchorChanges {
                            target: descriptionQuestion
                            anchors.top: undefined
                            anchors.verticalCenter: rectangleQuestion.verticalCenter
                        }
                    },
                    State {
                        name: "descriptionQuestionStateCounting"

                        PropertyChanges{
                            target: descriptionQuestion
                            height: (rectangleQuestion.height - Theme.paddingLarge)/3
                            font.pixelSize: Theme.fontSizeMedium
                            verticalAlignment: 0
                            anchors.margins: Theme.paddingSmall
                        }
                        AnchorChanges {
                            target: descriptionQuestion
                            anchors.verticalCenter: undefined
                            anchors.top:rectangleQuestion.top
                        }
                    }
                ]
            }

            Item{
                id: formsDisplay
                anchors.top: descriptionQuestion.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                width: rectangleQuestion.width - Theme.paddingLarge * 2
                height: rectangleQuestion.height - descriptionQuestion.height - Theme.paddingMedium
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
                            script:{
                                if(gameType.isCounting())
                                {
                                    formsDisplay.children[0].destroy()
                                }
                                gameType.launchQuestion()
                            }
                        }
                    }
                }
            ]
        }
        /*----------------------------------------------------------------------------------------------------*/

        /*------------------- Réponses --------------------*/
        Component.onCompleted: {
            loadItemAnswers(gameType.numberPropositions);
            loadItemQuestion();
        }
        /*-------------------------------------------------*/
    }

    Connections{
        target: gameType
        onAnswerRight: imgreponse.state = "right"
        onAnswerWrong: imgreponse.state = "wrong"
        onCorrectedAnswer: imgreponse.state = "right"
        onQuestionChanged: loadItemQuestion();
    }
}

