import react.dom.*
import kotlinx.css.*
import styled.*
import kotlinx.browser.document


fun main() {
    render(document.getElementById("root")){
       child(App::class) {}
    }
}

