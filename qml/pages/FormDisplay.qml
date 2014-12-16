import QtQuick 2.0
import Sailfish.Silica 1.0
import "../FormsDrawer.js" as FormsDrawer

Canvas {
    property int numberForms;

    id:canvas
    anchors.fill: parent

    onPaint: {
        var context = getContext("2d");

        context.beginPath();
        context.fillStyle = "white"
        context.fillRect(0, 0, width, height);
        context.fill();

        FormsDrawer.drawForms(context, numberForms)
    }
}
