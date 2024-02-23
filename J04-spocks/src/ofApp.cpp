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
    gui.add(up.setup("up", 100, 10, 1500));
    gui.add(down.setup("down", 100, 10, 1500));
    gui.add(y.setup("Y", 1, -2, 2));
    gui.add(z.setup("Z", 1, -4, 4));
    gui.add(width.setup("width", 500, 10, 1500));
    gui.add(height.setup("height", 500, 10, 1500));
    gui.add(heightrand.setup("randomize height"));
    gui.add(rotate.setup("rotate", 0, -4, 4));
    gui.add(mytime.setup("mytime", 0, -0.5, 2));
    gui.add(myzoom.setup("myzoom", 0, -5, 5));
    //   gui.add(mymath.setup("sin,cos,tan", 1, 1, 3));
    //to be added later? will it do anything?
    gui.add(red.setup("red", 0,0,255));
    gui.add(blue.setup("blue",0,0,255));
    gui.add(green.setup("green",0,0,255));
    gui.add(alpha.setup("alpha",123,0,255));

    //starting conditions
    width = 555;
    height = 555;
    up = 0;
    down = 0;
    rotate = 1;
    mytime = 0.96;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(mytime !=  0){
        // Update your animation or time-dependent variables here
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofSetColor(red, green, blue, alpha);
    
    
    ofColor darkColor(0,0,0,255);  // Opaque black
    ofColor lightColor(red, green, blue, alpha);  // Opaque white
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
    ofDrawRectangle(up, down, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw a transparent rect
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(fgColor);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);  // Translate to the center of the screen
    //float time = ofGetElapsedTimef();
    for (int i=0; i<100; i++) {
        //ofScale(1.1, 1.1);
        ofScale(mytime*z, mytime*y); // y and z squishes or widens time x scale, each on their own axis.
        // Noise is a topic that deserves a section in a book unto itself
        // Check out Section 1.6 of "The Nature of Code" for a good explanation
        // http://natureofcode.com/book/introduction/
        
        //  float noise = ofSignedNoise(time * timeScale) * 0.5;
        ofRotateDeg(time*rotate);
        ofDrawRectangle(up, down, width, height);
        
        cout << percent << endl;
        
        
    }
    ofPopMatrix();
    
    //    ofBeginShape();
    //    for(int i =  0; i < numsides; i++){
    //        float angle = i * TWO_PI / numsides;
    //        float x = ofGetWidth()/2 + cos(angle) *  100;
    //        float y = ofGetHeight()/2 + sin(angle) *  100;
    //        ofVertex(x, y);
    //    }
    //    ofEndShape(true);
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    if(key == 'p'){
        mytime = (mytime ==  0) ?  1.1 :  0; // Toggle between  0 and  1
       }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    // w = ofMap(x, 0, ofGetWidth(), 0, 255);
    //    h = ofMap(y, 0, ofGetHeight(), 0, 255);
    // timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as the mouse moves from top to bottom
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

        string timestamp = ofGetTimestampString(); // Generate a unique timestamp string
        string filename = "screenshot_" + timestamp + ".png"; // Append the timestamp to the filename
        img.grabScreen(0,  0, ofGetWidth(), ofGetHeight());
        img.save(filename); // Save the screenshot with the unique filename
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
