import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import kunal 1.0
import QtQml 2.12
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Integrating C++ With Qml")

    SomeClass{
        id: myClass
    }

    //with target Connections with parenthises
    Connections {
        target: myClass
        onSomeVarChanged: myLabel.text = myClass.getSomeVar()
    }

    Button{
        id: myButton
        anchors.centerIn: parent
        text: "Click Me!"

//        onClicked: classA.callMe() //using ContectProperty
//        onClicked: myClass.callMe() //using qmlRegisterType
//        onClicked: myClass.anotherFunction() //using Q_Invokable
//        onClicked: myClass.setSomeVar("ABC") // without target Connections without parenthises
                onClicked: myClass.setSomeVar("ABC") //with target Connections with parenthises

    }

    Text {
        id: myLabel
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 24
//        text: myClass.someVar
        text: myClass.getSomeVar()//Connections reqiurd
    }
}
