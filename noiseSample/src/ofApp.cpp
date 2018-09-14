#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    gui.setup();
    gui.add(step.setup("step", 10, 1, 20));
    gui.add(bias.setup("bias", 0.1, 0.01, 0.2));
    gui.add(alpha.setup("alpha", 10, 1, 50));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    
    for (int w = 0; w < ofGetWidth(); w += step) {
        for (int h = 0; h < ofGetHeight(); h += step) {
            noiseControl += bias;
            ofPushMatrix();
            ofTranslate(w, h);
            switch (mode) {
                case 0:// gray
                    ofSetColor(ofMap(ofNoise(noiseControl), 0.0, 1.0, 0, 255), alpha);
                    break;
                case 1:
                    ofSetColor(ofMap(ofNoise(noiseControl), 0.0, 1.0, 0, 255), 0, 0, alpha);
                    break;
                case 2:
                    ofSetColor(0, ofMap(ofNoise(noiseControl), 0.0, 1.0, 0, 255), 0, alpha);
                    break;
                case 3:
                    ofSetColor(0, 0, ofMap(ofNoise(noiseControl), 0.0, 1.0, 0, 255), alpha);
                    break;
            }
            ofDrawRectangle(0, 0, step, step);
            ofPopMatrix();
        }
    }
    noiseControl = 0;
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            mode = 0;
            break;
        case '1':
            mode = 1;
            break;
        case '2':
            mode = 2;
            break;
        case '3':
            mode = 3;
            break;
    }
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
