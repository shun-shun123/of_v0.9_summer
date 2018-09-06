#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(num.setup("num", NUM, 0, NUM));
    gui.add(red.setup("red", 1.0, 0, 1.0));
    gui.add(green.setup("green", 1.0, 0, 1.0));
    gui.add(blue.setup("blue", 1.0, 0, 1.0));
    gui.add(alpha.setup("alpha", 1.0, 0, 1.0));
    
    for (int i = 0; i < num; i++) {
        position[i] = ofVec2f(ofRandomWidth(), ofRandomHeight());
        color[i] = ofFloatColor(red, green, blue, alpha);
    }
    vbo.setVertexData(position, num, GL_DYNAMIC_DRAW);
    vbo.setColorData(color, num, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < num; i++) {
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    vbo.draw(GL_POINTS, 0, num);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
