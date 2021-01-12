
import QtQuick 2.15

import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

import Datamodels 1.0

Window {
    visible: true
    width: 480
    height: 800
    title: qsTr("Ghost Stories Simulator")
    color: "black"

    ColumnLayout {
        anchors.fill: parent

        Image {
            source: "qrc:/images/logo.png"
            fillMode: Image.PreserveAspectFit

            Layout.topMargin: parent.height * 0.05
            Layout.preferredHeight: parent.height * 0.25
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            TaoistView {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            DiceView {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            ResistanceView {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
        Text {
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 22
            text: qsTr("You shall not pass")

            Layout.preferredHeight: parent.height * 0.1
            Layout.fillWidth: true
        }
    }
}
