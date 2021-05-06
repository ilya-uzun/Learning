import react.dom.*
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
        div {
            h3 {
                + "Загаловок перед картиной"
            }
            img {
                attrs {
                    src = "https://via.placeholder.com/640x360.png?text=Video+Player+Placeholder"
                }
            }
        }
        for (video in unwatchedVideos){
            p {
                +"${video.speaker}: ${video.title}"
            }
        }
   }   
}

