import QtQuick 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // Слой в котором располагается TextInput и Button
    InitialScreen
    {
        id: rowLayout
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    // Список, в который добавляются элементы с данными из TextInput
    ListView {
        id: listView

        anchors.top: rowLayout.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5
        z: 1 // Расположение ниже, чем слой с TextInput и Button

        // Описание внешнего вида одного элемента в ListView
        delegate: Text {
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: textList // Роль свойства text, в которую будут передаваться данные
        }

        // Модель для представления данных в ListView
        model: ListModel {
            id: listModel
        }
    }
}
