@file:JvmName("Main")
package com.ilya.sudoku

import java.io.File
import java.io.InputStream

fun main() {
    val input = File("input")
        .readLines()
        .withIndex()
        .flatMap { indexedValue ->
            val xCoordinate = indexedValue.index
            indexedValue.value.toCharArray().withIndex()
                .filter { indexedChar -> indexedChar.value != '.'}
                .map{ indexedChar ->
                val yCoordinate = indexedChar.index
                (xCoordinate to yCoordinate) to indexedChar.value
            }
        }
        .toMap()
//    val input: InputStream = File("input").inputStream()
//    val inputString = input.bufferedReader().use { it.readText() }
    println(input)
}