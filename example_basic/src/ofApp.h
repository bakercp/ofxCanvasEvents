#pragma once

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

        int lastKeyPressed;
        std::string message;
        ofVec2f mouse;
        ofx::CanvasEvents canvasEvents;
};
