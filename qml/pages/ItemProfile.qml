import QtQuick 2.0
import Sailfish.Silica 1.0

Item{

    property int ident
    property alias name : nameLabel.text
    property alias score : scoreLabel.text

    Label {
        id: nameLabel
        x:Theme.paddingLarge
        //text: model.name
        font.capitalization: Font.Capitalize
    }

    Label {
        id:scoreLabel
        anchors.top: nameLabel.bottom
        x:Theme.paddingLarge
        //text: model.score
        font.pixelSize: 22
    }
}
