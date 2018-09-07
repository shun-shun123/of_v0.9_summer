#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    init();
    
    for (int i = 0; i < num; i++) {
        position[i] = ofVec2f(ofRandomWidth(), ofRandomHeight() - 300);
        gravity[i] = ofVec2f(0, ofRandom(0.1, 0.5));
        color[i] = ofFloatColor(red, green, blue, alpha);
        velocity[i] = ofVec2f(ofRandom(-5, 5), ofRandom(2, 5));
    }
    vbo.setVertexData(position, num, GL_DYNAMIC_DRAW);
    vbo.setColorData(color, num, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < num; i++) {
        velocity[i] += gravity[i];
        velocity[i] *= friction;
        position[i] += velocity[i];
        bounds(position[i], velocity[i]);
        color[i] = ofFloatColor(red, green, blue, alpha);
    }
    vbo.updateVertexData(position, num);
    vbo.updateColorData(color, num);
}

//--------------------------------------------------------------
void ofApp::draw(){
    glPointSize(20);
    vbo.draw(GL_POINTS, 0, num);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
        case 'r':
            for (int i = 0; i < num; i++) {
                velocity[i] = ofVec2f(ofRandom(-5, 5), ofRandom(2, 5));
                position[i] = ofVec2f(ofRandomWidth(), ofRandomHeight() - 300);
            }
            cout << "Pressed" << endl;
            break;
    }
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
void ofApp::init() {
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    guiSetup();
}

//--------------------------------------------------------------
void ofApp::guiSetup() {
    gui.setup();
    gui.add(num.setup("num", NUM, 0, NUM));
    gui.add(red.setup("red", 1.0, 0, 1.0));
    gui.add(green.setup("green", 1.0, 0, 1.0));
    gui.add(blue.setup("blue", 0.0, 0, 1.0));
    gui.add(alpha.setup("alpha", 0.1, 0, 1.0));
}

//---------------------------------------------------------------
void ofApp::bounds(ofVec2f& _position, ofVec2f& _velocity) {
    if (_position.x <= 0) {
        _position.x = 0;
        _velocity.x *= -1;
    } else if (_position.x > ofGetWidth()) {
        _position.x = ofGetWidth();
        _velocity.x *= -1;
    }
    if (_position.y > ofGetHeight()) {
        _position.y = ofGetHeight();
        _velocity.y *= -1;
    }
}
