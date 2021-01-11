import QtQuick 2.5
import QtGraphicalEffects 1.0

Item {
//    Rectangle {
//        anchors.fill: parent
//        color: "blue"
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
        text: "I roll"
    }

    Column {
        id: dicesColumn
        anchors.top: text.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Repeater {
            id: dicesRepeater
            model: 4
            MouseArea {
                id: dicesMouseArea

                property bool selected: false

                width: parent.width
                height: parent.height / dicesRepeater.count

                onClicked: dicesMouseArea.selected = !dicesMouseArea.selected

                Image {
                    id: image
                    anchors.margins: parent.height * 0.075
                    anchors.fill: parent
                    visible: !dicesMouseArea.selected
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/blueability.png"
                }

                Glow {
                    id: glow
                    anchors.fill: image
                    visible: dicesMouseArea.selected
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
