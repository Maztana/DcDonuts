import QtQuick 2.0

Item{

    id:item

    property alias signe : textSigne.text
    property alias taillePolice : textSigne.font.pixelSize
    property alias bold : textSigne.font.bold
    property alias xText : textSigne.x
    property alias yText : textSigne.y

    property bool isClicked : false;

    FontLoader{ id: fontPersoSigne; source: "../font/DESYREL_.ttf" }

    width: parent.width
    height: parent.height

    Image{
        id:fond
        source:"../images/donut.png"
        opacity: 0.2

        height: parent.height -2
        width: height

        anchors{
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }

        MouseArea
        {
            anchors.fill:fond
            onPressed: {
                if(isClicked)
                {
                    isClicked = false
                    fond.opacity = 0.2
                }
                else
                {
                    isClicked = true
                    fond.opacity = 0.55
                }
            }
        }
    }

    Text
    {
        id:textSigne
        font.pixelSize: 64
        font.bold: false
        color: "black"
    }
}
