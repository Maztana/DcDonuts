import QtQuick 2.0
import Sailfish.Silica 1.0

Item{
    anchors.fill:parent
    Component.onCompleted: createImages()

    function createImages() {

        var obj='import QtQuick 2.0; import Sailfish.Silica 1.0; Image {source:"'+image+'"; height:Theme.iconSizeSmall; width:Theme.iconSizeSmall; anchors.verticalCenter:parent.verticalCenter}';

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

    Row{
        anchors.centerIn: parent
        id:row
        spacing: Theme.paddingMedium


        Label{
            id:levelLabel
        }
    }
}
