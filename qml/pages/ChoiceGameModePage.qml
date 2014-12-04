import QtQuick 2.0
import Sailfish.Silica 1.0

Page {

    id: pageChoiceMode

    Drawer {
        id: drawerLevel
        onOpenChanged: addItems()

        anchors.fill: parent
        dock: Dock.Top

        background: SilicaListView {
            anchors.fill: parent
            model: listModel

            header: PageHeader { title: qsTr("Level") }


            VerticalScrollDecorator {}

            delegate: ListItem {
                id: listItem

                enabled: model.enabled

                LevelItem{
                    indexLevel: model.indexLevel
                    text:model.text
                    image:model.image
                }

                onClicked: {
                    educationQuiz.initLevelGame(model.indexLevel)
                    pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    drawerLevel.open = false
                }

            }
        }

        SilicaFlickable {

            anchors.fill: parent
            contentHeight: columnGamesMode.height
            contentWidth: parent.width

            VerticalScrollDecorator {}

            MouseArea {
                enabled: drawerLevel.open
                anchors.fill: columnGamesMode
                onClicked: drawerLevel.open = false
            }

            Column {
                id: columnGamesMode
                spacing: Theme.paddingLarge * 2
                width: parent.width
                enabled: !drawerLevel.opened

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
                            text:qsTr("Calculation")
                            z: 100
                            onClicked: {
                                launchCalculGame()
                                drawerLevel.open = true
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
                        text:qsTr("Counting")
                        enabled:false
                        onClicked:
                        {
                            game.launchGameType([5])
                            drawerLevel.open = true
                        }
                    }
                }

                Row {
                    id: lineColor
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button{
                        text:qsTr("Color")
                        enabled:false
                        onClicked:
                        {
                            game.launchGameType([6])
                            drawerLevel.open = true
                        }
                    }
                }

                Row {
                    id: lineMele
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button{
                        text:qsTr("Mixed")
                        enabled:false
                        onClicked:
                        {
                            game.launchGameType([1,2,3,4,5,6,7])
                            drawerLevel.open = true
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
                            game.launchGameType([7])
                            drawerLevel.open = true
                        }
                    }
                }

            }
        }
    }

    ListModel {
        id: listModel
    }

    function addItems() {
        listModel.clear()
        listModel.append({"indexLevel": 1, "text": qsTr("Easy"), "image":"qrc:///qml/images/star.png","enabled": true})
        listModel.append({"indexLevel": 2, "text": qsTr("Medium"), "image":"qrc:///qml/images/star.png","enabled": true})
        listModel.append({"indexLevel": 3, "text": qsTr("Hard"), "image":"qrc:///qml/images/star.png","enabled": true})
        listModel.append({"indexLevel": 4, "text": qsTr("Auto"), "image":"qrc:///qml/images/auto.png","enabled": false})
    }

    function launchCalculGame()
    {
        if(switchSignPlus.checked)
        {
            game.launchGameType([1])
        }
        else if(switchSignMoins.checked)
        {
            game.launchGameType([2])
        }
        else if(switchSignMult.checked)
        {
            game.launchGameType([3])
        }
        else if(switchSignDiv.checked)
        {
            game.launchGameType([4])
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
