import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    id:aboutpage

    SilicaFlickable{

        anchors.fill: parent

        VerticalScrollDecorator {}

        PageHeader{
            title: qsTr("A propos")
        }
       TextEdit{
            id:description
            x: Theme.paddingLarge
            anchors.topMargin: Theme.paddingLarge * 6
            anchors.top: parent.top
            text: qsTr("L’application Dr Donut est un jeu éducatif destiné aux enfants. Il a pour but de les faire progresser dans des domaines courants, tout en s’amusant !")
            color: Theme.secondaryColor
            wrapMode: TextEdit.WordWrap
            width:parent.width - 2 * Theme.paddingLarge
            readOnly: true
        }

        TextEdit{
            id: iut
            x: Theme.paddingLarge
            anchors.topMargin: Theme.paddingLarge * 2
            anchors.top: description.bottom
            text: qsTr("Projet réalisé à")+" IUT d’Aubière , Université Clermont I, "+qsTr("FRANCE.")
            color: Theme.secondaryColor
            font.italic: true
            wrapMode: TextEdit.WordWrap
            width:parent.width - 2 * Theme.paddingLarge
            readOnly: true
        }

        TextEdit{
            id: projectmanager
            x: Theme.paddingLarge
            anchors.topMargin: Theme.paddingLarge * 2
            anchors.top: iut.bottom
            text: qsTr("Chef de Projet")+": M. DELOBEL François"
            color: Theme.highlightColor
            wrapMode: TextEdit.WordWrap
            width:parent.width - 2 * Theme.paddingLarge
            readOnly: true
        }

        TextEdit{
            id: devteam
            x: Theme.paddingLarge
            anchors.topMargin: Theme.paddingLarge
            anchors.top: projectmanager.bottom
            text: qsTr("Développeurs") + ": MIZOULE-THABOURIN Etienne, BEUVELET Quentin, MACAISNE Mélanie."
            color: Theme.highlightColor
            wrapMode: TextEdit.WordWrap
            width:parent.width - 2 * Theme.paddingLarge
            readOnly: true
        }
    }

}
