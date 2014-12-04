import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    Drawer {
        id: drawer

        anchors.fill: parent
        dock: Dock.Bottom

        background: SilicaListView {
            anchors.fill: parent
            model: languagesListModel

            VerticalScrollDecorator {}

            delegate: ListItem {
                id: listItem

                Label {
                    x: Theme.paddingLarge
                    text:getLabel()
                    anchors.verticalCenter: parent.verticalCenter
                    color: listItem.highlighted ? Theme.highlightColor : Theme.primaryColor
                }

                onClicked: {
                    drawer.open = false;
                    application.changeLanguage(getIso());
                    infoBanner.displayMsg(qsTr("languageChangedMessage"))
                }
            }
        }

        SilicaFlickable {
            anchors.fill: parent

            contentHeight: column.height + Theme.paddingLarge

            VerticalScrollDecorator {}

            MouseArea {
                enabled: drawer.open
                anchors{
                    top: parent.top
                    left: parent.left
                }
                width: parent.width
                height: page.height

                onClicked: drawer.open = false
            }

            Column {
                id: column
                spacing: Theme.paddingLarge
                width: parent.width
                enabled: !drawer.opened

                PageHeader { title: qsTr("Options") }

                Button {
                    text: qsTr("Language")
                    onClicked: drawer.open = true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        InfoBanner{
            id:infoBanner
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
