import QtQuick 2.0
import Sailfish.Silica 1.0


Page{
    onStatusChanged: addItems()
    id:profileManager

    SilicaListView {

        id: profilesList
        anchors.fill: parent
        model: listModel

        header: PageHeader{ title:qsTr("Players") }

        ViewPlaceholder {
            enabled: profilesList.count == 0
            text: qsTr("No existing players")
            hintText: qsTr("Pull down to add")
        }

        PullDownMenu {

            MenuItem {
                text: qsTr("Create a new player")
                onClicked: pageStack.push(Qt.resolvedUrl("CreationProfilePage.qml"))
            }

            MenuItem {
                text: qsTr("Import a player")
                enabled: false
            }
        }

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: listItem
            menu: profileOptionsMenu

            onClicked:
            {
                application.changeCurrentProfile(itemprofile.ident)
                pageStack.pop()
            }

            function remove() {
                remorseAction(qsTr("Deleting"), function()
                {
                    listModel.remove(index)
                    application.deleteProfile(itemprofile.ident)
                })
            }

            function reset() {
                remorseAction(qsTr("Reinitialization"), function()
                {
                    application.resetProfile(itemprofile.ident)
                    addItems()
                })
            }


            ItemProfile{
                id:itemprofile
                ident: model.ident
                name:model.name
                score: model.score
            }

            Component {
                id: profileOptionsMenu
                ContextMenu {
                    MenuItem {
                        text: qsTr("Reinitialize")
                        onClicked: {
                            reset()
                        }
                    }
                    MenuItem {
                        text: qsTr("Delete")
                        onClicked:{
                            remove()
                        }
                    }
                    MenuItem {
                        text: qsTr("Export")
                        enabled: false
                    }
                }
            }
        }
    }

    InfoBanner{
        id:infoBanner
        anchors.verticalCenter: parent.verticalCenter;
    }

    ListModel {
        id: listModel
    }

    function addItems() {

        listModel.clear();

        var nbProfiles = application.getNbProfiles()

        for(var i = 0; i < nbProfiles; i++)
        {
            var id = application.allId[i];
            var name = application.getNameProfileById(id)
            var score = application.getScoreProfileById(id)
            listModel.append({"ident": id, "name": name, "score":score + " Donut(s)"})
        }
    }

    Component.onCompleted: infoBanner.displayMsg(qsTr("msgNoProfile"))
}
