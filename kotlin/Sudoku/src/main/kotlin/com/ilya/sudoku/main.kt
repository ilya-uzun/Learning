@file:JvmName("Main")
package com.ilya.sudoku

fun main() {
    val firstNumber = 10.0
    val secondNumber = 256
    val therdNumder = firstNumber + secondNumber
    println(therdNumder)
    //вывод массива
    val firstArray = arrayOf(1, 2, 34, 5)
    println(firstArray.contentToString())

    val modiArray = firstArray.map { number -> number * 10 }.toIntArray()
    println(modiArray.contentToString())
}