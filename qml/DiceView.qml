
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
            text: qsTr("I roll")
            font.pixelSize: Layout.preferredHeight * 0.5

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: diceView

            interactive: false
            model: diceModel
            delegate: Item {
                id: wrapper

                property real size: Math.min(height, width) * 0.8

                height: diceView.height / diceView.count
                width: parent.width

                AbstractButton {
                    id: diceButton

                    property DieItem dieItem: model.object

                    anchors.centerIn: parent
                    height: wrapper.size
                    width: wrapper.size

                    checked: diceButton.dieItem.selected
                    visible: diceButton.dieItem.type == DieItem.Extra ? taoistModel.selectedTaoist.power == TaoistItem.StrengthOfTheMountain : true

                    contentItem: GlowingImage {
                        source: diceButton.dieItem.image
                        selected: diceButton.dieItem.selected
                        color: "#DDDDDD"
                    }

                    onClicked: diceButton.dieItem.onClicked()
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
