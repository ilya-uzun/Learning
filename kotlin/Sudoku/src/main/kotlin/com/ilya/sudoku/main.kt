@file:JvmName("Main")
package com.ilya.sudoku

import java.io.File
import java.io.InputStream

fun main() {

    //val input = readInput()
    //val input: InputStream = File("input").inputStream()
    //val inputString = input.bufferedReader().use { it.readText() }
    //println(input)

    // Массивы тест
    val x_1 = arrayOf(1,2)
    val x_2 = arrayOf<Int>(1,2)
    val x_3 = intArrayOf(1,2)
    val x_4 = Array(6, {i -> i*1})
    val x_5: Array<Int> = arrayOf(1,2)
    val x_6: IntArray = intArrayOf(1,2)







    println(x_1[1])
    println(x_2[0])
    println(x_3[0])
    println(x_4[0])
    println(x_5[0])
}

fun readInput():Map<Pair<Int, Int>, Int>{

    val input = File("input")
        .readLines()
        .withIndex()
        .flatMap { indexedValue ->
            val xCoordinate = indexedValue.index
            indexedValue.value.toCharArray().withIndex()
                .filter { indexedChar -> indexedChar.value != '.'} // != добавели фильтр точекр
                .map{ indexedChar ->
                    val yCoordinate = indexedChar.index
                    var number = Character.getNumericValue(indexedChar.value)
                    (xCoordinate to yCoordinate) to number
                }
        }
        .toMap()
    return  input
}