import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    //Qpro setpro
    property string name: value
    Rectangle {
        id: rectangle

        width: 447
        height: 297
        color: "#ffffff"
        anchors.fill: parent

        Column {
            id: column
            width: 218
            height: 178
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: username
                padding: 5
                text: qsTr("Username")
            }

            TextField {
                id: textFielduser
                text: qsTr("")
            }
            Label {
                id: password
                padding: 5
                text: qsTr("Password")
            }

            TextField {
                id: textpass
                text: qsTr("")
            }
        }

        Button {
            id: button
            x: 209
            y: 279
            text: qsTr("Login")
        }

        Button {
            id: button1
            x: 313
            y: 279
            text: qsTr("Cancel")
        }


    }

}
