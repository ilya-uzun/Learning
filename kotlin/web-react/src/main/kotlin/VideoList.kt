import react.*
import react.dom.*
import kotlinx.html.js.onClickFunction
import kotlinx.browser.window

external interface VideoListProps : RProps {
    var videos: List<Video>
}

@JsExport
class VideoList : RComponent<VideoListProps, RState>() {

    override fun RBuilder.render() {
        for (video in props.videos) {
        p {
            key = video.id.toString()
            attrs {
                onClickFunction = {
                    window.alert("Clicked $video!")
                }
            }
            +"${video.speaker}: ${video.title}"
        }
        }
        
    }
}