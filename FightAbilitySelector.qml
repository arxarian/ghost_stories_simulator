import QtQuick 2.5
import QtGraphicalEffects 1.0

Item {
//    Rectangle {
//        anchors.fill: parent
//        color: "green"
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
        text: "I am"
    }

    Column {
        id: abilityColumn
        anchors.top: text.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Repeater {
            id: abilityRepeater
            model: 4
            MouseArea {
                id: abilityMouseArea

                property bool selected: false

                width: parent.width
                height: parent.height / abilityRepeater.count

                onClicked: abilityMouseArea.selected = !abilityMouseArea.selected

                Image {
                    id: image
                    anchors.margins: parent.height * 0.075
                    anchors.fill: parent
                    visible: !abilityMouseArea.selected
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/blue_player.png"
                    mipmap: true
                }

                Glow {
                    id: glow
                    anchors.fill: image
                    visible: abilityMouseArea.selected
                    radius: image.height * 0.15
                    samples: 17
                    color: "#1B84BD"
                    source: image
                    spread: 0.125

                    SequentialAnimation {
                        running: abilityMouseArea.selected
                        loops: Animation.Infinite
                        NumberAnimation {
                            target: glow
                            property: "spread"
                            duration: 2000
                            from: 0.2
                            to: 0.5
                        }
                        NumberAnimation {
                            target: glow
                            property: "spread"
                            duration: 2000
                            from: 0.5
                            to: 0.2
                        }
                    }

                }
            }

        }
    }
}
