#include "ofApp.h"
#include "ofxGui.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending(); // Remember if we are using transparency, we need to let openFrameworks know
    ofBackground(255);
   
    ofSetFrameRate(60);
  //  ofSetCircleResolution(100);
    
    gui.setup();
    gui.add(width.setup("width", 140, 10, 500));
    gui.add(height.setup("height", 140, 10, 500));
   
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  //  gui.draw();

    ofColor darkColor(0,0,0,255);  // Opaque black
    ofColor lightColor(255,255,255,255);  // Opaque white
    float time = ofGetElapsedTimef();  // Time in seconds
    float percent = ofMap(cos(time/2.0), -1, 1, 0, 1);  // Create a value that oscillates between 0 to 1
    ofColor bgColor = darkColor;  // Color for the transparent rectangle we use to clear the screen
    bgColor.lerp(lightColor, percent);  // This modifies our color "in place", check out the documentation page
    bgColor.a = clearAlpha;  // Our initial colors were opaque, but our rectangle needs to be transparent
    ofColor fgColor = lightColor;  // Color for the rectangle outlines
    fgColor.lerp(darkColor, percent);  // Modifies color in place
    
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw a transparent rect
    
    

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(fgColor);
    ofNoFill();
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);  // Translate to the center of the screen
        for (int i=0; i<100; i++) {
            ofScale(1.1, 1.1);
            // Noise is a topic that deserves a section in a book unto itself
            // Check out Section 1.6 of "The Nature of Code" for a good explanation
            // http://natureofcode.com/book/introduction/
            float time = ofGetElapsedTimef();
           
          //  float noise = ofSignedNoise(time * timeScale) * 0.5;
            ofRotateDeg(time/5);
            ofDrawRectangle(0, 0, w, h);
        }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  w = ofMap(x, 0, ofGetWidth(), 0, 255); 
    h = ofMap(y, 0, ofGetHeight(), 0, 255);
    
    
   // timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as the mouse moves from top to bottom
    
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
