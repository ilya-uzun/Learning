import react.*
import react.dom.*
import kotlinx.css.*
import styled.*
import styled.styledDiv


external interface AppState: RState {
    var currentVideo: Video?
}

@JsExport
class App : RComponent<RProps, AppState>() {
    override fun RBuilder.render() {

        h1 {
             +"KotlinConf Explorer" 
        }
    
        div {
 
            h3 {
                +"Videos to watch"
            }
            videoList {
                videos = unwatchedVideos
                selectedVideo = state.currentVideo
                onSelectVideo = { video -> 
                    setState {
                        currentVideo = video
                    }
                }
            }

            h3 {
                +"Videos watched"
            }
            videoList {
                videos = watchedVideos
                selectedVideo = state.currentVideo
                onSelectVideo = { video -> 
                    setState {
                        currentVideo = video
                    }
                }
            }     
 
        }
        state.currentVideo?.let { currentVideo -> 
            videoPlayer {
                video = currentVideo
            }
        }
   }      
}