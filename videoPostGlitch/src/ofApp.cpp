#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    
    buffer.allocate(ofGetWidth(), ofGetHeight());
    postGlitch.setup(&buffer);
    
    for (int i = 0; i < 3; i++) {
        scene[i].load("SCENE" + ofToString(i + 1) + ".mp4");
        scene[i].setLoopState(OF_LOOP_PALINDROME);
        scene[i].play();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    scene[currentScene].update();
    buffer.begin();
    scene[currentScene].draw(0, 0, ofGetWidth(), ofGetHeight());
    buffer.end();
    postGlitch.setFx(effects[type], isActive[type]);
    postGlitch.generateFx();
}

//--------------------------------------------------------------
void ofApp::draw(){
    buffer.draw(0, 0);
    for (int i = 0; i < 17; i++) {
        if (isActive[i]) {
            ofDrawBitmapString(ofToString(i) + ":" + mode[i], 20, i * 10 + 10);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ' :
            currentScene = (currentScene + 1) % 3;
            break;
        case '0':
            type = 0;
            break;
        case '1':
            type = 1;
            break;
        case '2':
            type = 2;
            break;
        case '3':
            type = 3;
            break;
        case '4':
            type = 4;
            break;
        case '5':
            type = 5;
            break;
        case '6':
            type = 6;
            break;
        case '7':
            type = 7;
            break;
        case '8':
            type = 8;
            break;
        case '9':
            type = 9;
            break;
        case 'a':
            type = 10;
            break;
        case 's':
            type = 11;
            break;
        case 'd':
            type = 12;
            break;
        case 'f':
            type = 13;
            break;
        case 'g':
            type = 14;
            break;
        case 'h':
            type = 15;
            break;
        case 'j':
            type = 16;
            break;
    }
    isActive[type] = !isActive[type];
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
