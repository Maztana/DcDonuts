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
        width: 300
        height:100

        opacity: enable ? 1 : 0.5

        Text
        {
            id:textBouton
            font.pixelSize: 44
            font.family:fontPerso.name
            anchors.horizontalCenter: parent.horizontalCenter
            y: fond.height/2 - height/2 + 5
            color:"black"

            Component.onCompleted: setWidth()
        }

        MouseArea{
            anchors.fill:{
                if(enable)
                {
                    parent
                }
            }

            onClicked: pageStack.push(Qt.resolvedUrl(link))
            onPressed: {
                fond.opacity = 0.8
            }
            onReleased: {
                fond.opacity = 1
            }
        }
    }

    function setWidth() {
        while(textBouton.width > 270)
        {
            textBouton.font.pixelSize = textBouton.font.pixelSize - 1;
        }
    }
}




