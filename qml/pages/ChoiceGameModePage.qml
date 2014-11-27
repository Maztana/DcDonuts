import QtQuick 2.0
import Sailfish.Silica 1.0

Page {

    id: pageChoiseMode

    SilicaFlickable {

        anchors.fill: parent
        contentHeight: columnGamesMode.height
        contentWidth: parent.width

        VerticalScrollDecorator {}



        Column {
            id: columnGamesMode
            spacing: Theme.paddingLarge * 2
            width: parent.width

            PageHeader {
                Label {
                    id: nameProfile
                    text: currentProfile.name
                    font.pixelSize: Theme.fontSizeLarge
                    color: Theme.highlightColor
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.margins: Theme.paddingLarge
                }
                Label{
                    id: scoreProfile
                    text: currentProfile.score + " Donut(s)"
                    color: Theme.secondaryHighlightColor
                    font.family: Theme.fontFamilyHeading
                    font.pixelSize: Theme.fontSizeMedium
                    anchors{
                        top: nameProfile.bottom
                        right: nameProfile.right
                    }
                }
            }

            Row {
                id: lineCalcul
                anchors.horizontalCenter: parent.horizontalCenter

                Item{
                    width: btCalcul.width
                    height: btCalcul.height + (rowCalculOperations.height / 2)

                    Button{
                        id: btCalcul
                        text:qsTr("Calcul")
                        z: 100
                        onClicked: {
                            launchCalculGame()
                            pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                        }
                    }

                    Rectangle{
                        id:rectangleBackground
                        color:Theme.secondaryColor
                        opacity: 0.15
                        height: rowCalculOperations.height - 30
                        width: rowCalculOperations.width
                        anchors.top: btCalcul.bottom
                        anchors.topMargin: -Theme.paddingMedium
                        anchors.horizontalCenter: parent.horizontalCenter
                        radius: 20
                    }

                    Row
                    {
                        id: rowCalculOperations
                        anchors.bottom: rectangleBackground.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottomMargin: Theme.paddingSmall

                        Switch{
                            id: switchSignPlus
                            icon.source: "qrc:///qml/images/signePlus.png"
                            width:60
                            checked: true
                            onClicked: {
                                buttonGroupChanged(switchSignPlus)
                            }
                        }

                        Switch{
                            id: switchSignMoins
                            icon.source: "qrc:///qml/images/signeMoins.png"
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSignMoins)
                            }
                        }

                        Switch{
                            id: switchSignMult
                            icon.source: "qrc:///qml/images/signeMult.png"
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSignMult)
                            }
                        }

                        Switch{
                            id: switchSignDiv
                            icon.source: "qrc:///qml/images/signeDiv.png"
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSignDiv)
                            }
                        }
                    }
                }
            }

            Row {
                id: lineCounting
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Denombrement")
                    enabled:false
                    onClicked:
                    {
                        game.launchGameType("COUNTING")
                        pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    }
                }
            }

            Row {
                id: lineColor
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Couleur")
                    enabled:false
                    onClicked:
                    {
                        game.launchGameType("COLOR")
                        pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    }
                }
            }

            Row {
                id: lineMele
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Mele")
                    enabled:false
                    onClicked:
                    {
                        game.launchGameType("ALL")
                        pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    }
                }
            }

            Row {
                id: lineFlashcard
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Flashcard")
                    enabled:false
                    onClicked:
                    {
                        game.launchGameType("FLASHCARD")
                        pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    }
                }
            }

        }
    }

    function launchCalculGame()
    {
        if(switchSignPlus.checked)
        {
            game.launchGameType("ADDITION")
        }
        else if(switchSignMoins.checked)
        {
            game.launchGameType("SUBTRACTION")
        }
        else if(switchSignMult.checked)
        {
            game.launchGameType("MULTIPLICATION")
        }
        else if(switchSignDiv.checked)
        {
            game.launchGameType("DIVISION")
        }
    }

    function buttonGroupChanged(switchClicked)
    {
        if(switchClicked !== switchSignPlus)
        {
            switchSignPlus.checked = false
        }
        if(switchClicked !== switchSignMoins)
        {
            switchSignMoins.checked = false
        }
        if(switchClicked !== switchSignMult)
        {
            switchSignMult.checked = false
        }
        if(switchClicked !== switchSignDiv)
        {
            switchSignDiv.checked = false
        }
        switchClicked.checked = true
    }
}
