import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480
    height: 800
    title: qsTr("Ghost Stories Calculator")
    color: "black"

    ListModel {
        id: chances

        function getChange(type, tao, dices) {
            if(tao > dices) {
                console.info("more tao than dices, return 0");
                return 0;
            }

            for(var chanceIndex = 0; chanceIndex < chances.count; ++chanceIndex)
            {
                var chance = chances.get(chanceIndex);
//                console.log(chance.type, chance.tao, chance.dices)
                if(chance.type === type && chance.tao === tao && chance.dices === dices) {
                    return chance.chance;
                }
            }
                    return 0;
        }

        ListElement {
            type: "other"
            tao: 1
            dices: 1
            chance: 33.3
        }
        ListElement {
            type: "other"
            tao: 1
            dices: 2
            chance: 55.5
        }
        ListElement {
            type: "other"
            tao: 2
            dices: 2
            chance: 11.1
        }
        ListElement {
            type: "other"
            tao: 1
            dices: 3
            chance: 70.3
        }
        ListElement {
            type: "other"
            tao: 2
            dices: 3
            chance: 25.9
        }
        ListElement {
            type: "other"
            tao: 3
            dices: 3
            chance: 3.7
        }
        ListElement {
            type: "other"
            tao: 1
            dices: 4
            chance: 80.2
        }
        ListElement {
            type: "other"
            tao: 2
            dices: 4
            chance: 40.7
        }
        ListElement {
            type: "other"
            tao: 3
            dices: 4
            chance: 11.1
        }
        ListElement {
            type: "other"
            tao: 4
            dices: 4
            chance: 1.2
        }
        ListElement {
            type: "blue"
            tao: 1
            dices: 1
            chance: 55.5
        }
        ListElement {
            type: "blue"
            tao: 1
            dices: 2
            chance: 80.2
        }
        ListElement {
            type: "blue"
            tao: 2
            dices: 2
            chance: 20.9
        }
        ListElement {
            type: "blue"
            tao: 1
            dices: 3
            chance: 91.22
        }
        ListElement {
            type: "blue"
            tao: 2
            dices: 3
            chance: 45.1
        }
        ListElement {
            type: "blue"
            tao: 3
            dices: 3
            chance: 7.2
        }
        ListElement {
            type: "green"
            tao: 1
            dices: 1
            chance: 55.5
        }
        ListElement {
            type: "green"
            tao: 1
            dices: 2
            chance: 80.2
        }
        ListElement {
            type: "green"
            tao: 2
            dices: 2
            chance: 30.8
        }
        ListElement {
            type: "green"
            tao: 1
            dices: 3
            chance: 91.2
        }
        ListElement {
            type: "green"
            tao: 2
            dices: 3
            chance: 58.3
        }
        ListElement {
            type: "green"
            tao: 3
            dices: 3
            chance: 17.1
        }
    }

    Item {
        id: upperSpacer
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * 0.05
    }

    Image {
        id: logo
        // TOOD - adapt the size of image to window's size (there is not fit now)
        anchors.top: upperSpacer.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        source: "qrc:/images/logo.png"
    }

    Item {
        id: spacer
        anchors.top: logo.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * 0.05
    }

    Row {
        anchors.top: spacer.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: chance.top

        FightAbilitySelector {
            id: ability
            height: parent.height
            width: parent.width / 3
        }
        DicesSelector {
            id: dices
            height: parent.height
            width: parent.width / 3
        }
        GhostResistenceSelector
        {
            id: resistence
            height: parent.height
            width: parent.width / 3
        }
    }
    Text {
        id: chance
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height * 0.1
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 22

//        Rectangle {
//            anchors.fill: parent
//            color: "gold"
//        }

        text: qsTr("You shall not pass")
    }
}
