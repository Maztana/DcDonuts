import QtQuick 2.0

Item
{
    property alias text : textBouton.text
    property string link

    FontLoader{ id: fontPerso; source: "../font/PWYummyDonuts.ttf" }

        Image
        {
            id:fond
            source:"../images/BoutonArrondi.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            width:textBouton.width + 50
            height:textBouton.height + 45

            Text
            {
                id:textBouton
                font.pixelSize: 48
                font.family:fontPerso.name
                wrapMode: Text.WordWrap
                y: fond.height/2 - height/2 + 5
                anchors.horizontalCenter: parent.horizontalCenter
                color:"black"
            }

            MouseArea{
                anchors {
                    fill:parent
                }
                onClicked: pageStack.push(Qt.resolvedUrl(link))
            }
        }
}
