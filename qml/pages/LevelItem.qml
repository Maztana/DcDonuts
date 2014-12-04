import QtQuick 2.0
import Sailfish.Silica 1.0

Item{
    anchors.fill:parent
    Component.onCompleted: createImages()

    function createImages()
    {
        var obj='import QtQuick 2.0; import Sailfish.Silica 1.0; Image {source:"'+image+'"; height:Theme.iconSizeSmall; width:Theme.iconSizeSmall}';

        if(indexLevel == 4)
        {
          Qt.createQmlObject(obj,row, "dynamicImages");
        }
        else
        {
            for(var i=0; i<indexLevel;i++)
            {
                Qt.createQmlObject(obj,row, "dynamicImages");
            }
        }
    }

    property string image
    property int indexLevel
    property alias text : levelLabel.text
    property alias color: levelLabel.color

    Row{
        id:row
        anchors.centerIn: parent
        spacing: Theme.paddingMedium

        Label{
            id:levelLabel
        }
    }
}
