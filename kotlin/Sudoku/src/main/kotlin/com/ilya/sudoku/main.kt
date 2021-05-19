@file:JvmName("Main")
package com.ilya.sudoku

import java.io.File
import java.io.InputStream

fun main() {

    val input = readInput()
//    val input: InputStream = File("input").inputStream()
//    val inputString = input.bufferedReader().use { it.readText() }
    println(input)
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