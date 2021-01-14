
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
            font.pixelSize: Layout.preferredHeight * 0.5

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: taoisView

            interactive: false
            model: taoistModel
            delegate: Item {
                id: wrapper

                property real size: Math.min(height, width) * 0.8

                height: taoisView.height / taoisView.count
                width: parent.width

                AbstractButton {
                    id: taoistButton

                    property TaoistItem taoistItem: model.object

                    anchors.centerIn: parent
                    height: wrapper.size
                    width: wrapper.size

                    checked: taoistButton.taoistItem.selected

                    contentItem: GlowingImage {
                        source: taoistButton.taoistItem.image
                        selected: taoistModel.selectedTaoist === taoistButton.taoistItem
                        color: "#1B84BD"
                    }

                    onClicked: taoistModel.selectedTaoist = taoistButton.taoistItem
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
