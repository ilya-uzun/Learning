import QtQuick 2.12
import QtQuick.Window 2.12
//корневой элемент
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    // подключаем Tile
    Tile {
        //указыаем геометрию фигуры
        width: 50
        height: 50
    }
}
