
import QtQuick 2.15

import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0

import Datamodels 1.0

Item {
    ColumnLayout {
        anchors.fill: parent

        Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "white"
            text: qsTr("I am")
            font.pixelSize: 22

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: taoisView

            model: taoistModel
            delegate: Item {
                id: wrapper

                property real size: Math.min(height, width) * 0.8

                height: parent.height / taoisView.count
                width: parent.width

                AbstractButton {
                    id: taoistButton

                    property TaoistItem taoistItem: model.object

                    anchors.centerIn: parent
                    height: wrapper.size
                    width: wrapper.size

                    text: index
                    checked: taoistButton.taoistItem.selected

                    contentItem: Item {
                        Image {
                            id: image
                            anchors.fill: parent
                            source: taoistButton.taoistItem.image
                            smooth: true
                            mipmap: true
                            fillMode: Image.PreserveAspectFit
                        }

                        Glow {
                            id: glow
                            anchors.fill: image
                            visible: taoistButton.taoistItem.selected
                            radius: image.height * 0.3
                            samples: 17
                            color: "#1B84BD"
                            source: image
                            spread: 0.125

                        }
                    }

                    onClicked: taoistButton.taoistItem.onClicked()
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
