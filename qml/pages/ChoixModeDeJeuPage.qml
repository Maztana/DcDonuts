import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Components"

Page {

    id: page

    SilicaFlickable {

        anchors.fill: parent
        contentHeight: colonneModeJeux.height
        contentWidth: parent.width

        VerticalScrollDecorator {}

        Column {
            id: colonneModeJeux
            spacing: 50
            width: parent.width

            PageHeader {
                title: application.nameProfil
            }

            Row {
                id: ligneCalcul
                anchors.horizontalCenter: parent.horizontalCenter

                Item{
                    width: btCalcul.width
                    height: btCalcul.height + rowCalculOperations.height

                    Button{
                        id: btCalcul
                        text:qsTr("Calcul")
                        z:100
                        onClicked: {
                            lancementJeuCalcul()
                            pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                        }
                    }

                    Rectangle{
                        id:rectangleFond
                        color:"white"
                        opacity: 0.15
                        height: rowCalculOperations.height - 30
                        width: rowCalculOperations.width
                        anchors.top: btCalcul.bottom
                        anchors.margins: -5
                        radius: 20
                    }

                    Row
                    {
                        id: rowCalculOperations
                        anchors.top: rectangleFond.top

                        Switch{
                            id: switchSignePlus
                            icon.source: "qrc:///qml/images/signePlus.png"
                            y:-35
                            width:60
                            checked: true
                            onClicked: {
                                buttonGroupChanged(switchSignePlus)
                            }
                        }

                        Switch{
                            id: switchSigneMoins
                            icon.source: "qrc:///qml/images/signeMoins.png"
                            y:-35
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSigneMoins)
                            }
                        }

                        Switch{
                            id: switchSigneMult
                            icon.source: "qrc:///qml/images/signeMult.png"
                            y:-35
                            width:60
                            onClicked: {
                                buttonGroupChanged(switchSigneMult)
                            }
                        }

                        Switch{
                            id: switchSigneDiv
                            icon.source: "qrc:///qml/images/signeDiv.png"
                            y:-35
                            width:60
                            enabled: false
                            visible: false
                            onClicked: {
                                buttonGroupChanged(switchSigneDiv)
                            }
                        }
                    }
                }
            }

            Row {
                id: ligneDenombrement
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Denombrement")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }
            }

            Row {
                id: ligneCouleur
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Couleur")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }
            }

            Row {
                id: ligneMele
                anchors.horizontalCenter: parent.horizontalCenter

                Button{
                    text:qsTr("Mele")
                    enabled:false
                    onClicked: pageStack.push(Qt.resolvedUrl("../pages/JeuPage.qml"))
                }
            }

        }
    }

    function lancementJeuCalcul()
    {
        if(switchSignePlus.checked)
        {
            game.launchTypeJeu("ADDITION")
        }
        else if(switchSigneMoins.checked)
        {
            game.launchTypeJeu("SOUSTRACTION")
        }
        else if(switchSigneMult.checked)
        {
            game.launchTypeJeu("MULTIPLICATION")
        }
        else if(switchSigneDiv.checked)
        {
            game.launchTypeJeu("DIVISION")
        }
    }

    function buttonGroupChanged(switchClicked)
    {
        if(switchClicked !== switchSignePlus)
        {
            switchSignePlus.checked = false
        }
        if(switchClicked !== switchSigneMoins)
        {
            switchSigneMoins.checked = false
        }
        if(switchClicked !== switchSigneMult)
        {
            switchSigneMult.checked = false
        }
        if(switchClicked !== switchSigneDiv)
        {
            switchSigneDiv.checked = false
        }
        switchClicked.checked = true
    }
}
