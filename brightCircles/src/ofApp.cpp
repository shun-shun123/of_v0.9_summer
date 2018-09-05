#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int i = 0; i < 10; i++) {
        bird[i].setup(ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5)), ofVec2f(0, ofRandom(0.1, 1)), ofVec2f(0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f direction;
    for (int i = 0; i < 10; i++) {
        attraction[i] = bird[i].getPosition();
        direction += attraction[i];
    }
    direction /= 10;
    
    for (int i = 0; i < 10; i++) {
        bird[i].update(direction - attraction[i]);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 10; i++) {
        bird[i].draw();
    }
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
