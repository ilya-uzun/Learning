@file:JvmName("Main")
package com.ilya.sudoku

import java.io.File
import java.io.InputStream

fun main() {
   // val input = File( pathname = "input").readLines()
    val inputStream: InputStream = File("input").inputStream()
    val inputString = inputStream.bufferedReader().use { it.readText() }
    println(inputString)
}