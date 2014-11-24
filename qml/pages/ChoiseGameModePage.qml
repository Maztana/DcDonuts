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
            spacing: 50
            width: parent.width

            PageHeader {
                title: application.nameProfile
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
                        z:100
                        onClicked: {
                            launchCalculGame()
                            pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                        }
                    }

                    Rectangle{
                        id:rectangleBackground
                        color:"white"
                        opacity: 0.15
                        height: rowCalculOperations.height - 30
                        width: rowCalculOperations.width
                        anchors.top: btCalcul.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.margins: -5
                        radius: 20
                    }

                    Row
                    {
                        id: rowCalculOperations
                        anchors.top: rectangleBackground.top
                        anchors.horizontalCenter: parent.horizontalCenter


                        Switch{
                            id: switchSignPlus
                            icon.source: "qrc:///qml/images/signePlus.png"
                            y:-35
                            width:60
                            checked: true
                            onClicked: {
                                buttonGroupChanged(switchSignPlus)
                            }
                        }

                        Switch{
                            id: switchSignMoins
                            icon.source: "qrc:///qml/images/signeMoins.png"
                            y:-35
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSignMoins)
                            }
                        }

                        Switch{
                            id: switchSignMult
                            icon.source: "qrc:///qml/images/signeMult.png"
                            y:-35
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSignMult)
                            }
                        }

                        Switch{
                            id: switchSignDiv
                            icon.source: "qrc:///qml/images/signeDiv.png"
                            y:-35
                            width:60
                            enabled: false
                            visible: false
                            onClicked: {
                                buttonGroupChanged(switchSignDiv)
                            }
                        }
                    }
                }
            }

            Row {
                id: lineEnumeration
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Denombrement")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                }
            }

            Row {
                id: lineColor
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Couleur")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                }
            }

            Row {
                id: lineMele
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Mele")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
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
            game.launchGameType("SOUSTRACTION")
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
