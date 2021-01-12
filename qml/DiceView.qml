
import QtQuick 2.15

import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import Datamodels 1.0

Item {
    ColumnLayout {
        anchors.fill: parent

        Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "white"
            text: qsTr("I roll")
            font.pixelSize: 22

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: diceView

            model: diceModel
            delegate: Item {
                id: wrapper

                property real size: Math.min(height, width) * 0.8

                height: parent.height / diceView.count
                width: parent.width

                AbstractButton {
                    id: diceButton

                    property DieItem dieItem: model.object

                    anchors.centerIn: parent
                    height: wrapper.size
                    width: wrapper.size

                    text: index
                    checked: diceButton.dieItem.selected

//                    background: Rectangle {
////                        color: diceButton.dieItem.selected ? "gold" : "white"
//                        radius: height / 2
//                    }

                    indicator: Rectangle {
                        color: "red"
                        radius: height / 2
                    }

                    contentItem: Item {
                        Image {
                            anchors.fill: parent
                            anchors.margins: parent.height * 0.2
                            source: diceButton.dieItem.image
                            fillMode: Image.PreserveAspectFit
                        }
                    }

                    //                    contentItem: Text {
                    //                        color: diceButton.dieItem.selected ? "gold" : "red"
                    //                        text: diceButton.text
                    //                        horizontalAlignment: Text.AlignHCenter
                    //                        verticalAlignment: Text.AlignVCenter
                    //                    }

                    onClicked: diceButton.dieItem.onClicked()
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
