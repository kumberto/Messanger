    import QtQuick 2.0
    import QtQuick.Layouts 1.15
    import QtQuick.Controls 2.15
    Item
    {
        width: 300
        height: 200

        Column
        {
            id: rowLayout
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 5
            height: 50
            spacing: 2

            Rectangle
            {
               width: parent.width
               height: 50
               color: "#00ff00"

                TextInput {
                    id: textInputNickName
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            listModel.append({ textList: textInput.text })
                        }
                    }
                }
            }

    //        // Область с TextInput
            Rectangle
            {
                width: parent.width
                height: 50
                color: "#00ff00"

                TextInput {
                    id: textInputPassword
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    /* По нажатию клавиши Enter передаём информацию
                     * из TextInput в элемент ListView
                     * */
                    Keys.onPressed: {
                        // 16777220 - код клавиши Enter
                        if(event.key === 16777220){
                            listModel.append({ textList: textInput.text })
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
                height: 50
                anchors.horizontalCenter : parent.horizontalCenter
                Button
                {
                    id: button
                    text: qsTr("добавить")

                    onClicked: {
                        listModel.append({ textList: textInputNickName.text + " " + textInputPassword.text })
                    }
                }
            }
        }
    }
