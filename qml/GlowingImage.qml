
import QtQuick 2.15

import QtGraphicalEffects 1.0

Item {
    id: root

    property string source
    property bool selected: false
    property color color: "#BB2222"

    Image {
        id: image
        anchors.fill: parent
        opacity: 0.5
        source: root.source
        smooth: true
        mipmap: true
        fillMode: Image.PreserveAspectFit
    }

    Glow {
        id: glow
        anchors.fill: image
        visible: root.selected
        radius: image.height * 0.4
        samples: 17
        color: root.color
        source: image
        spread: 0.25
    }
}
