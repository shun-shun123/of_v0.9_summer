#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    for (int i = 0; i < NUM / 2; i++) {
        verticies[i * 2] = ofVec3f(ofGetWidth() / (NUM / 2) * i, sin(TWO_PI / NUM * i) * 300, 0);
        verticies[i * 2 + 1] = ofVec3f(ofGetWidth() / (NUM / 2) * i, -sin(TWO_PI / NUM * i) * 300, 0);
        colors[i * 2] = ofFloatColor::fromHsb(1.0, 1.0, 1.0, 0.6);
        colors[i * 2 + 1] = ofFloatColor::fromHsb(1.0, 1.0, 1.0, 0.6);
    }
    myVbo.setVertexData(verticies, NUM, GL_DYNAMIC_DRAW);
    myVbo.setColorData(colors, NUM, GL_DYNAMIC_DRAW);
    
    gui.setup();
    gui.add(vertex_num.setup("vertex_num", NUM, 1, NUM));
    gui.add(alpha.setup("alpha", 0.6, 0.1, 1.0));
    gui.add(velocity.setup("velocity", 2.0, 1.0, 4.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    float adjust = 0.0f;
    for (int i = 0; i < vertex_num / 2; i++) {
        verticies[i * 2] = ofVec3f(ofGetWidth() / (vertex_num / 2) * i, sin(TWO_PI / (vertex_num / 2) * i + adjust) * 300, 0);
        verticies[i * 2 + 1] = ofVec3f(ofGetWidth() / (vertex_num / 2) * i, -sin(TWO_PI / (vertex_num / 2) * i + adjust) * 300, 0);
        colors[i * 2] = ofFloatColor::fromHsb(1.0 / (vertex_num / 2) * i, 1.0, 1.0, alpha);
        colors[i * 2 + 1] = ofFloatColor::fromHsb(1.0 / (vertex_num / 2) * i, 1.0, 1.0, alpha);
        adjust += ofGetElapsedTimef() / velocity;
    }
    myVbo.updateVertexData(verticies, vertex_num);
    myVbo.updateColorData(colors, vertex_num);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
    ofTranslate(0, ofGetHeight() / 2);
    glPointSize(10.0);
    myVbo.draw(GL_LINE_STRIP, 0, vertex_num);
    ofPopMatrix();
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
