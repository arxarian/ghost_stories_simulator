
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
            text: qsTr("I fight")
            font.pixelSize: Layout.preferredHeight * 0.5

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: resistanceView

            interactive: false
            model: resistanceModel
            delegate: Item {
                id: wrapper

                property real size: Math.min(height, width) * 0.8

                height: resistanceView.height / resistanceView.count
                width: parent.width

                AbstractButton {
                    id: resistanceButton

                    property ResistanceItem resistanceItem: model.object

                    anchors.centerIn: parent
                    height: wrapper.size
                    width: wrapper.size

                    checked: resistanceButton.resistanceItem.selected

                    contentItem: GlowingImage {
                        source: resistanceButton.resistanceItem.image
                        selected: resistanceButton.checked
                        color: "#CC1111"
                    }

                    onClicked: resistanceButton.resistanceItem.onClicked()
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
