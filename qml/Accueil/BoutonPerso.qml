import QtQuick 2.0

Item
{
    property alias text : textBouton.text

    property bool enable : true
    property string link

    width: fond.width
    height: fond.height

    FontLoader{ id: fontPerso; source: "../font/PWYummyDonuts.ttf" }

        Image
        {
            id:fond
            source:"../images/BoutonArrondi.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            width:textBouton.width + 50
            height:textBouton.height + 45

            opacity: enable ? 1 : 0.5

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
                anchors.fill:{
                    if(enable)
                    {
                        parent
                    }
                }

                onClicked: pageStack.push(Qt.resolvedUrl(link))
            }
        }
}


