import react.*
import react.dom.*
import kotlinx.css.*
import styled.*
import kotlinx.browser.document


@JsExport
class App : RComponent<RProps, RState>() {

    override fun RBuilder.render() {

        h1 {
             +" Hello, React+Kotlin" 
        }
    
        div {
 
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
                //borderStyle = solid
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
   }      
}