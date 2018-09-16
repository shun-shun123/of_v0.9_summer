#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableSmoothing();
    
    // postGlitch initialization
    buffer.allocate(ofGetWidth(), ofGetHeight());
    postGlitch.setup(&buffer);
    
    sphere.set(300, 20);
    sphere.setPosition(0, 0, 0);
    for (int i = 0; i < MAX_NUM / 3; i++) {
        float radianS = PI / (MAX_NUM / 3) * i;
        
        float radianT =  20;
        radianT += 20 * i;
        verticies[i * 3] = ofVec3f(radius * sin(radianS) * cos(radianT),
                                   radius * sin(radianS) * sin(radianT),
                                   radius * cos(radianS));
        verticies[i * 3 + 1] = verticies[i * 3] + ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size));
        verticies[i * 3 + 2] = verticies[i * 3] + ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size));
        colors[i * 3] = ofFloatColor::fromHsb(ofRandom(1.0), 1.0, 1.0);
        colors[i * 3 + 1] = colors[i * 3];
        colors[i * 3 + 2] = colors[i * 3];
    }
    vbo.setVertexData(verticies, MAX_NUM, GL_DYNAMIC_DRAW);
    vbo.setColorData(colors, MAX_NUM, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    buffer.begin();
    ofClear(255, 255, 255);
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, -300);
    ofRotateY(ofGetFrameNum() / 3);
    sphere.drawWireframe();
    vbo.draw(GL_TRIANGLES, 0, MAX_NUM);
    ofPopMatrix();
    buffer.end();
    postGlitch.setFx(effects[type], isActive[type]);
    postGlitch.generateFx();
}

//--------------------------------------------------------------
void ofApp::draw(){
    buffer.draw(0, 0);
    for (int i = 0; i < 17; i++) {
        if (isActive[i]) {
            ofDrawBitmapString(ofToString(i) + ": " + mode[i], 20, i * 11 + 11);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ' :
            isPressed = !isPressed;
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

float ofApp::pow(float value, int time) {
    for (int i = 1; i < time; i++) {
        value *= value;
    }
    return value;
}
