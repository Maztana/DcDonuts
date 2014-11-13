import QtQuick 2.0

Item{

    property string signe
    property bool isClicked : false;

    FontLoader{ id: fontPersoSigne; source: "../font/DESYREL_.ttf" }

    width: parent.width
    height: parent.height

    Rectangle{
        id: fond
        width: parent.width
        height: parent.height
        color: "black"
        opacity: 0.15

        MouseArea
        {
            anchors.fill:parent
            onPressed: {
                if(isClicked)
                {
                    isClicked = false
                    fond.opacity = 0.15
                }
                else
                {
                    isClicked = true
                    fond.opacity = 0.35
                }
            }
        }

    }

    Text
    {
        id:textSigne
        text: signe
        font.pixelSize: 48
        font.family: fontPersoSigne.name
        color: "black"
        y: fond.y

        anchors{
            horizontalCenter: fond.horizontalCenter
        }
    }
}
