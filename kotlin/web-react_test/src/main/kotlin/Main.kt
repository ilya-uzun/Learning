import react.dom.*
import kotlinx.css.*
import styled.*
import kotlinx.browser.document


fun main() {
    render(document.getElementById("root")){
       h3{
           +"Test"
       }
    }
}

