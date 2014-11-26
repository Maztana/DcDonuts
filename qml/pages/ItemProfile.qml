import QtQuick 2.0
import Sailfish.Silica 1.0

Item{

    property int ident
    property alias name : nameLabel.text
    property alias score : scoreLabel.text

    Label {
        id: nameLabel
        x:Theme.paddingLarge
        font.capitalization: Font.Capitalize
        font.pixelSize: Theme.fontSizeLarge
    }

    Label {
        id:scoreLabel
        anchors.top: nameLabel.bottom
        x:Theme.paddingLarge
        font.pixelSize: Theme.fontSizeExtraSmall
    }
}
