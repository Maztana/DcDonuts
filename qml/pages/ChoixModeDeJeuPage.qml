import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Components"

Page {

    Rectangle{
        anchors.fill: parent
        color: 'lightblue'
        opacity: 0.6
    }

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
                        link: "../pages/JeuPage.qml"
                    }


                    Row
                    {
                        id: rowCalculOperations
                        anchors.top: btCalcul.bottom
                        width: parent.width
                        height: 50

                        BoutonSigne{
                            width: parent.width/4
                            signe: "+"
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "-"
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "x"
                            height: parent.height
                        }

                        BoutonSigne{
                            width: parent.width/4
                            signe: "/"
                            height: parent.height
                        }
                    }
                }


            }

            Row {
                id: ligneCouleur2
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Denombrement")
                    enable:true
                    link: "../pages/JeuPage.qml"
                }
            }

            Row {
                id: ligneCouleur
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Couleur")
                    enable:true
                    link: "../pages/JeuPage.qml"
                }
            }

            Row {
                id: ligneMele
                anchors.horizontalCenter: parent.horizontalCenter

                BoutonPerso{
                    text:qsTr("Mele")
                    enable:true
                    link: "../pages/JeuPage.qml"
                }
            }

        }
    }
}
