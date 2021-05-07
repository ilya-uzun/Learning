import react.dom.*
import kotlinx.css.*
import styled.*
import kotlinx.browser.document


val unwatchedVideos = listOf(
    KotlinVideo(1, "Building and breaking things", "John Doe", "https://youtu.be/PsaFVLr8t4E"),
    KotlinVideo(2, "The development process", "Jane Smith", "https://youtu.be/PsaFVLr8t4E"),
    KotlinVideo(3, "The Web 7.0", "Matt Miller", "https://youtu.be/PsaFVLr8t4E")
)

val watchedVideos = listOf(
    KotlinVideo(4, "Mouseless development", "Tom Jerry", "https://youtu.be/PsaFVLr8t4E")
)

fun main() {
    render (document.getElementById("root")){
        h1 {
            +" Hello, React+Kotlin" 
        }
        div{
            h3 {
                +"Видио "
            }
            p {
                + "Первый параграф"
            }
            p {
                + "Второй параграф"
            }
            p {
                + "Третий параграф"
            }
            h3 {
                + "Videos watched"
            }
            p {
                + "Четвертый параграф"
            }
        }
        // использование css
        styledDiv {
            css {
                position = Position.absolute
                top = 10.px
                right = 10.px
            }
            h3 {
                +"John Doe: Building and breaking things"
            }
            img {
                attrs {
                    src = "https://via.placeholder.com/640x360.png?text=Video+Player+Placeholder"
                }
            }
        }
        for (video in unwatchedVideos){
            p {
                +"${video.speaker}: ${video.title} : ${video.videoUrl}"
            }
        }
   }   
}

// инфа https://habr.com/ru/post/555744/