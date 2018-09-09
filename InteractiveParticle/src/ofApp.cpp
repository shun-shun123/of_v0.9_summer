#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    for (int i = 0; i < NUM; i++) {
        particles[i].setup();
        vertex[i] = particles[i].getVertex();
        color[i] = ofFloatColor::fromHsb(ofRandom(1.0), 1.0, 1.0, 0.2);
    }
    myVbo.setVertexData(vertex, NUM, GL_DYNAMIC_DRAW);
    myVbo.setColorData(color, NUM, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        particles[i].update(mode);
        vertex[i] = particles[i].getVertex();
        if (mode) {
            particles[i].attraction();
        }
    }
    myVbo.updateVertexData(vertex, NUM);
}

//--------------------------------------------------------------
void ofApp::draw(){
    glPointSize(20);
    myVbo.draw(GL_POINTS, 0, NUM);
    if (mode) {
        ofDrawBitmapString("attraction mode", 50, 50);
    }
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
    for (int i = 0; i < NUM; i++) {
        particles[i].mouseDragged();
    }
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
