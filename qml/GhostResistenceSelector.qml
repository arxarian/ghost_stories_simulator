import QtQuick 2.5
import QtGraphicalEffects 1.0

Item {
//    Rectangle {
//        anchors.fill: parent
//        color: "steelblue"
//    }
    Text {
        id: text
        height: parent.height * 0.1
        anchors.left: parent.left
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 22
        color: "white"
        text: "I fight"
    }

    Column {
        id: resistenceColumn
        anchors.top: text.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Repeater {
            id: resistenceRepeater
            model: 4
            MouseArea {
                id: resistenceMouseArea

                property bool selected: false

                width: parent.width
                height: parent.height / resistenceRepeater.count

                onClicked: resistenceMouseArea.selected = !resistenceMouseArea.selected

                Image {
                    id: image
                    anchors.margins: parent.height * 0.075
                    anchors.fill: parent
                    visible: !resistenceMouseArea.selected
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/blueability.png"
                }

                Glow {
                    id: glow
                    anchors.fill: image
                    visible: resistenceMouseArea.selected
                    radius: image.height * 0.15
                    samples: 17
                    color: "white"
                    source: image
                    spread: 0.125

                    SequentialAnimation {
                        running: true
                        loops: Animation.Infinite
                        NumberAnimation {
                            target: glow
                            property: "spread"
                            duration: 2000
                            from: 0.1
                            to: 0.4
                        }
                        NumberAnimation {
                            target: glow
                            property: "spread"
                            duration: 2000
                            from: 0.4
                            to: 0.1
                        }
                    }

                }
            }

        }
    }
}
