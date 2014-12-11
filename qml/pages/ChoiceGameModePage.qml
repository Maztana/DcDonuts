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

                enabled: model.isLevelSelectable
                onEnabledChanged: {
                    if(!enabled)
                    {
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
                    gameType.initLevelGame(model.indexLevel)
                    gameType.launchGame()

                    if(gameType.isQuiz())
                    {
                        pageStack.push(Qt.resolvedUrl("../pages/GameQuizPage.qml"))
                    }
                    else
                    {
                        //not quiz game type
                    }
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
                z:100

                anchors.fill: columnGamesMode
                onClicked: {
                    drawerLevel.open = false
                }
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
                                if(initGameCalcul())
                                {
                                    drawerLevel.open = true
                                }
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
                            }

                            Switch{
                                id: switchSignMoins
                                icon.source: "qrc:///qml/images/signeMoins.png"
                                width:60
                            }

                            Switch{
                                id: switchSignMult
                                icon.source: "qrc:///qml/images/signeMult.png"
                                width:60
                            }

                            Switch{
                                id: switchSignDiv
                                icon.source: "qrc:///qml/images/signeDiv.png"
                                width:60
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
                            game.initGameType([5])
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
                            game.initGameType([6])
                            drawerLevel.open = true
                        }
                    }
                }

                Row {
                    id: lineMele
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button{
                        text:qsTr("Mixed")
                        onClicked:
                        {
                            game.initGameType([1,2,3,4]/*,5,6]*/)
                            drawerLevel.open = true
                        }
                    }
                }

                Row {
                    id: lineFlashcard
                    anchors.horizontalCenter: parent.horizontalCenter

                    Button{
                        text:qsTr("Flashcard")
                        onClicked:
                        {
                            game.initGameType([7])
                            pageStack.push(Qt.resolvedUrl("../pages/ChoiceFlashcardPage.qml"))
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
            if(gameType.isQuiz())
            {
                if(!gameType.isFlashcard())
                {
                    gameType.initLevelsSelectable()
                    addItems()
                }
            }
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
        listModel.append({"indexLevel": 1, "text": qsTr("Easy"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(gameType.levelsSelectable, 1)})
        listModel.append({"indexLevel": 2, "text": qsTr("Medium"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(gameType.levelsSelectable, 2)})
        listModel.append({"indexLevel": 3, "text": qsTr("Hard"), "image":"qrc:///qml/images/star.png", "isLevelSelectable": contains(gameType.levelsSelectable, 3)})
        listModel.append({"indexLevel": 4, "text": qsTr("Auto"), "image":"qrc:///qml/images/auto.png", "isLevelSelectable": contains(gameType.levelsSelectable, 4)})
    }

    function initGameCalcul()
    {
        var listType = []
        if(switchSignPlus.checked)
        {
            listType.push(1)
        }
        if(switchSignMoins.checked)
        {
            listType.push(2)
        }
        if(switchSignMult.checked)
        {
            listType.push(3)
        }
        if(switchSignDiv.checked)
        {
            listType.push(4)
        }

        if(listType.length > 0)
        {
            game.initGameType(listType)
            return true
        }
        return false;
    }
}
