const val TAVERN_NAME = "Taernyl's Folly"

fun main(args: Array<String>){
    placeOrder()
}

private fun placeOrder(){
    val indexOfApostrohe = TAVERN_NAME.indexOf('\'')
    val tarernMaster = TAVERN_NAME.substring(0 until indexOfApostrohe)
    println("Madrigal speaks with $tarernMaster about their order.")
}
