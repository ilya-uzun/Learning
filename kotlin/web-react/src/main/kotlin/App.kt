import react.*
import react.dom.*
import kotlinx.css.*
import styled.*
import kotlinx.browser.document


@JsExport
class App : RComponent<RProps, RState>() {

    override fun RBuilder.render() {
        css {
            position = Position.absolute
            top = 10.px
            right = 10.px
        }
        styledDiv {
            h1 {
                +" Hello, React+Kotlin" 
            }
        }
        styledDiv {
            css {
                position = Position.absolute
                top = 10.px
                right = 10.px
            }
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
                +"Videos to watch"
            }
            child(VideoList::class){
                attrs.videos = unwatchedVideos
            }

            h3 {
                +"Videos watched"
            }
            child(VideoList::class){
                attrs.videos = watchedVideos
            }       
 
        }
        styledDiv {
            css {
                position = Position.absolute
                top = 10.px
                right = 10.px
            }
            img {
                 attrs {
                  src = "https://via.placeholder.com/640x360.png?text=Video+Player+Placeholder"
                }
            }
        }
   }   
    
    
}