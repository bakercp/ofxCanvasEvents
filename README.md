ofxCanvasEvents
=====================================

__NOTE: DOES NOT WORK YET!__

Introduction
------------
Broadcast mouse, touch, and key events from an HTML5 Canvas to your openFrameworks app.

License
-------
[MIT License](license.md)

Installation
------------
Download or clone this repository into your `openFrameworks/addons/` folder making sure to save it as `ofxCanvasEvents`.

Dependencies
------------

- [ofxIO](http://github.com/bakercp/ofxIO)
- [ofxJSON](http://github.com/bakercp/ofxJSON)
- [ofxJSONRPC](http://github.com/bakercp/ofxJSONRPC)
- [ofxMediaType](http://github.com/bakercp/ofxMediaType)
- [ofxSSLManager](http://github.com/bakercp/ofxSSLManager)
- [ofxTaskQueue](http://github.com/bakercp/ofxTaskQueue)
- [ofxHTTP](http://github.com/bakercp/ofxHTTP)

Huge shoutout to @bakercp for developing the entire suite of dependencies that make this addon possible.

Compatibility
------------
Compatible with openFrameworks 0.8.4 and above (may work with older versions too).

Usage
-----

### Basic

Create a new project using the oF Project Generator making sure to include the
ofxCanvasEvent addon and the rest of the dependencies mentioned above. Copy the
Document

```cpp
#include "ofMain.h"
#include "ofxCanvasEvents.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(ofKeyEventArgs& args);
		void keyReleased(ofKeyEventArgs& args);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofx::CanvasEvents canvasEvents;
};

```

### keycodes

```cpp
void keyPressed(ofKeyEventArgs& args);
void keyReleased(ofKeyEventArgs& args);
```

```cpp

void ofApp::keyPressed(ofKeyEventArgs& args){

    message = "keyPressed keycode: " + ofToString(args.keycode);
}

void ofApp::keyReleased(ofKeyEventArgs& args){

    message = "keyReleased keycode: " + ofToString(args.keycode);
}

```

<!-- Known issues
------------
Any specific (and long-living) issues/limitations you want to mention? For bugs, etc. you should use the issue tracker of your addon's repository

Version history
------------
It make sense to include a version history here (newest releases first), describing new features and changes to the addon. Use [git tags](http://learn.github.com/p/tagging.html) to mark release points in your repo, too!

### Version 0.1 (Date):
Describe relevant changes etc.
-->
