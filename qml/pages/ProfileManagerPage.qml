import QtQuick 2.0
import Sailfish.Silica 1.0

Page{
    id:profileManager

    SilicaListView {

        id: profilesList
        anchors.fill: parent
        model: listModel

        header: PageHeader{ title:qsTr("Joueurs") }


        ViewPlaceholder {
            enabled: profilesList.count == 0
            text: qsTr("Aucun profil")
            hintText: qsTr("Pull down pour ajouter")
        }

        PullDownMenu {

            MenuItem {
                text: qsTr("Créer un joueur")
                enabled: false
            }

            MenuItem {
                text: qsTr("Importer un joueur")
                enabled: false
            }

        }

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: listItem
            menu: profileOptionsMenu

            function remove() {
                remorseAction(qsTr("Suppression"), function() { listModel.remove(index) })
            }


            ItemProfile{
                id: itemProfile
                ident: model.ident
                name:model.name
                score: model.score

            }

            Component {
                id: profileOptionsMenu
                ContextMenu {
                    MenuItem {
                        text: qsTr("Réinitialiser")
                        enabled: false
                    }
                    MenuItem {
                        text: qsTr("Supprimer")
                        enabled: false
                        onClicked: remove()
                    }
                    MenuItem {
                        text: qsTr("Exporter")
                        enabled: false
                    }
                }
            }
        }
    }

    ListModel {
        id: listModel
    }

    onPageContainerChanged: addItems()

    function addItems() {

        var nbProfiles = application.getNbProfiles()

        for(var i = 0; i < nbProfiles; i++)
        {
            var id = application.allId[i];
            var name = application.getNameProfileById(id)
            var score = application.getScoreProfileById(id)
            listModel.append({"ident":id, "name": name, "score":score + " Donuts"})
        }

    }


}
