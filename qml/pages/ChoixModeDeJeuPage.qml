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
                title: qsTr("Mode de Jeu")
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
                            if(text === qsTr("Calcul"))
                            {
                                application.lancerPartie();
                            }
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
                        }

                        Switch{
                            id: switchSigneMoins
                            icon.source: "qrc:///qml/images/signeMoins.png"
                            y:-35
                            width:60
                        }

                        Switch{
                            id: switchSigneMult
                            icon.source: "qrc:///qml/images/signeMult.png"
                            y:-35
                            width:60
                        }

                        Switch{
                            id: switchSigneDiv
                            icon.source: "qrc:///qml/images/signeDiv.png"
                            y:-35
                            width:60
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
}
