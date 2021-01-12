
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
            text: qsTr("I fight")
            font.pixelSize: 22

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }

        ListView {
            id: resistanceView

            property real buttonSize: Math.min(resistanceView.width, resistanceView.height / resistanceView.count)

            model: resistanceModel
            delegate: AbstractButton {
                id: resistanceButton

                property ResistanceItem resistanceItem: model.object

                height: resistanceView.buttonSize
                width: resistanceView.buttonSize

                text: index

                contentItem: Text {
                    color: resistanceItem.selected ? "gold" : "red"
                    text: resistanceButton.text
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                onClicked: resistanceItem.onClicked()
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
