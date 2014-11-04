import QtQuick 2.0

Item
{
    property alias text : textBouton.text
    property string link

    Rectangle
    {
        id:fond
        color: "#F6C577"
        width:textBouton.width
        height:textBouton.height + 20
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            anchors{
                fill:parent
            }

            onClicked: pageStack.push(Qt.resolvedUrl(link))
        }
    }

    Text
    {
        id:textBouton
        font.pixelSize: 32
        wrapMode: Text.WordWrap
        anchors.verticalCenter: parent.verticalCenter
        color:"black"
    }

}
