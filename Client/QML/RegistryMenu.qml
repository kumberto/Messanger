import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
Item
{
    width: parent.width/2
    height: parent.height/2

    Column
    {
        id: rowLayout
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        spacing: 10

        Row
        {
            width: parent.width
            height: 40

            Rectangle
            {
                height: parent.height
                width: loginText.width
                Text {
                    id: loginText
                    width: rectConfirPasswordLayout.confirPasswordWidth
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("User Name: ")
                }
            }

            Rectangle
            {
                id: textInputLoginRect
                height: parent.height
                width: parent.width
                border.color: "black"
                border.width: 1

                TextInput
                {
                    id: textInputNickName
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            listModel.append({ textList: textInputNickName.text })
                        }
                    }
                }
            }
        }

//        // Область с TextInput
        Row
        {
            id: rectPasswordLayout
            //property alias passwordWidth: passwordText.width
            width: parent.width
            height: 40

            Rectangle
            {
                height: parent.height
                width: passwordText.width
                Text {
                    id: passwordText
                    width: rectConfirPasswordLayout.confirPasswordWidth
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Password: ")
                }
            }

            Rectangle
            {
                id: textInputPasswordRect
                height: parent.height
                width: parent.width
                border.color: "black"
                border.width: 1

                TextInput
                {
                    id: textInputPassword
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    color: "#00ff00"
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            listModel.append({ textList: textInputPassword.text })
                        }
                    }
                }
            }
        }

        Row
        {
            id: rectConfirPasswordLayout
            property alias confirPasswordWidth: confirPasswordText.width
            width: parent.width
            height: 40

            Rectangle
            {
                height: parent.height
                width: confirPasswordText.width
                Text {
                    id: confirPasswordText
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Confir Password:")
                }
            }

            Rectangle
            {
                id: textInputConfirPasswordRect
                height: parent.height
                width: parent.width
                border.color: "black"
                border.width: 1

                TextInput
                {
                    id: textInputConfirPassword
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    color: "#00ff00"
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            //listModel.append({ textList: textInputPassword.text })
                        }
                    }
                }
            }
        }

        Row
        {
            id: rectEmailLayout
            width: parent.width
            height: 40

            Rectangle
            {
                height: parent.height
                width: emailText.width
                Text {
                    id: emailText
                    anchors.verticalCenter: parent.verticalCenter
                    width: rectConfirPasswordLayout.confirPasswordWidth
                    text: qsTr("email: ")
                }
            }

            Rectangle
            {
                id: textInputEmailRect
                height: parent.height
                width: parent.width
                border.color: "black"
                border.width: 1

                TextInput
                {
                    id: textInputEmail
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    color: "#00ff00"
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            listModel.append({ textList: textInputPassword.text })
                        }
                    }
                }
            }
        }
        /* Кнопка, по нажатию которой передаётся информация из
         * textInput в элемент ListView
         * */
        Rectangle
        {
            width: 100
            height: 40
            anchors.horizontalCenter : parent.horizontalCenter
            Button
            {
                id: button
                text: qsTr("Registry")

                onClicked: {
                    listModel.append({ textList: textInputNickName.text + " " + textInputPassword.text })
                }
            }
        }
    }
}
