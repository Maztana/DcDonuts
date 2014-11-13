import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Components"

PageCustom {

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

                    BoutonPerso{
                        id: btCalcul
                        text:qsTr("Calcul")
                        link: "../pages/ChoixDifficulteePage.qml"
                        z:100
                    }

                    Rectangle{
                        color:"black"
                        opacity: 0.15
                        height: rowCalculOperations.height + 30
                        width: rowCalculOperations.width
                        anchors.top : btCalcul.bottom
                        anchors.margins: -27
                        radius: 20
                    }


                    Row
                    {
                        id: rowCalculOperations
                        anchors.top : btCalcul.bottom
                        width: parent.width
                        height: 60

                        BoutonSigne{
                            width: parent.width/4
                            signe: "+"
                            yText: -11
                            xText: 23
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "-"
                            yText: -42
                            xText: 23
                            taillePolice: 100
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "x"
                            taillePolice: 40
                            bold:true
                            yText: 2
                            xText: 29
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "÷"
                            yText: -11
                            xText: 23
                            height: parent.height
                        }
                    }
                }


            }

            Row {
                id: ligneDenombrement
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Denombrement")
                    enable:false
                    link: "../pages/ChoixDifficulteePage.qml"
                }
            }

            Row {
                id: ligneCouleur
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Couleur")
                    enable:false
                    link: "../pages/ChoixDifficulteePage.qml"
                }
            }

            Row {
                id: ligneMele
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Mele")
                    enable:false
                    link: "../pages/ChoixDifficulteePage.qml"
                }
            }

        }
    }
}
