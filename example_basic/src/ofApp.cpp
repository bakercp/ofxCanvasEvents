#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetWindowShape(380, 240);
    
//    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(255);
    
    lastKeyPressed = 0;
    message = "";
    
    ofLaunchBrowser(canvasEvents.getServer()->getURL());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    std::string isMouseOverCanvas = canvasEvents.isMouseOver() ? "TRUE" : "FALSE";
//    std::string message = "Mouse: " + ofToString((int) mouse.x) + ", " + ofToString((int) mouse.x);
    ofDrawBitmapStringHighlight(message, 15, 30);
    ofDrawBitmapStringHighlight("mouse over canvas: " + isMouseOverCanvas, 15, 50);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(ofKeyEventArgs& args){
    
    message = "keyPressed keycode: " + ofToString(args.keycode);
}

//--------------------------------------------------------------
void ofApp::keyReleased(ofKeyEventArgs& args){
    
    message = "keyReleased keycode: " + ofToString(args.keycode);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    message = "mouseMoved: " + ofToString(x) + ", " + ofToString(y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    message = "mouseDragged: " + ofToString(x) + ", " + ofToString(y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    message = "mousePressed: " + ofToString(x) + ", " + ofToString(y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    message = "mouseReleased: " + ofToString(x) + ", " + ofToString(y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
