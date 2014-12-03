import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: pageChoiceMode

    Drawer {
        id: drawerLevel

        anchors.fill: parent
        dock: Dock.Top

        background: SilicaListView {
            anchors.fill: parent
            model: listModel

            header: PageHeader { title: qsTr("Level") }

            VerticalScrollDecorator {}

            delegate: ListItem {
                id: listItem

                //property alias colorLevel: levelItem.color

                enabled: model.isLevelSelectable
                onEnabledChanged: {
                    console.log("je suis rien")
                    if(!enabled)
                    {
                        console.log("je suis pas enable")
                        levelItem.opacity = 0.4
                        levelItem.color = Theme.highlightColor
                    }
                }

                LevelItem{
                    id: levelItem
                    indexLevel: model.indexLevel
                    text:model.text
                    image:model.image
                    opacity: 1
                    color: Theme.primaryColor
                }

                onClicked: {
                    educationQuiz.initLevelGame(model.indexLevel)
                    educationQuiz.launchGame()
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
                            text:qsTr("Calcul")
                            z: 100
                            onClicked: {
                                initGameCalcul()
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
                        text:qsTr("Denombrement")
                        enabled:false
                        onClicked:
                        {
                            game.initGameType([5])
                            drawerLevel.open = true
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
                            game.initGameType([6])
                            drawerLevel.open = true
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
                            game.initGameType([1,2,3,4,5,6,7])
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
                            game.initGameType([7])
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

    Connections{
        target: game
        onGameTypeChanged: {
            educationQuiz.initLevelsSelectable()
            addItems()
        }
    }

    function contains(list, elementSearched) {
        var index = list.length;
        while (index--) {
            if (list[index] === elementSearched) {
                return true;
            }
        }
        return false;
    }

    function addItems() {
        listModel.clear()
        listModel.append({"indexLevel": 1, "text": qsTr("Easy"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(educationQuiz.levelsSelectable, 1)})
        listModel.append({"indexLevel": 2, "text": qsTr("Medium"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(educationQuiz.levelsSelectable, 2)})
        listModel.append({"indexLevel": 3, "text": qsTr("Hard"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(educationQuiz.levelsSelectable, 3)})
    }

    function initGameCalcul()
    {
        if(switchSignPlus.checked)
        {
            game.initGameType([1])
        }
        else if(switchSignMoins.checked)
        {
            game.initGameType([2])
        }
        else if(switchSignMult.checked)
        {
            game.initGameType([3])
        }
        else if(switchSignDiv.checked)
        {
            game.initGameType([4])
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
