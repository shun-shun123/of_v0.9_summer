#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    circles.push_back(ofVec3f(0, 0, 0));
    colors.push_back(ofFloatColor::fromHsb(0, 1.0, 1.0));
    for (int i = 0; i <= resolution; i++) {
        circles.push_back(ofVec3f(scale * cos((2 * PI) / resolution * i), scale * sin((2 * PI) / resolution * i), 0));
        colors.push_back(ofFloatColor::fromHsb(1.0 / resolution * i, 1.0, 0.8));
    }
    ofBackground(0);
    soundStream.setup(this, 0, 1, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    vector<ofVec3f> temp;
    temp.push_back(circles[0]);
    for (int i = 1; i <= resolution + 1; i++) {
        temp.push_back(circles[i]);
        circles[i] *= ofMap(curVol, 0.0, 3.0, 1.0, 20.0);
    }
    mesh.addVertices(circles);
    circles = temp;
    for (int i = 1; i <= resolution + 1; i++) {
        colors[i] = ofFloatColor::fromHsb(hue / resolution * i, 1.0, 1.0);
    }
    mesh.addColors(colors);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZ(rotateZ);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.draw();
//    mesh.drawWireframe();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::audioIn(float* input, int bufferSize, int nChannels) {
    curVol = 0.0;
    for (int i = 0; i < bufferSize; i++) {
        curVol += input[i] * input[i];
    }
    curVol /= bufferSize;
    cout << curVol << endl;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    hue = float(y) / float(ofGetHeight());
    rotateZ = float(x) / float(ofGetWidth()) * 360.0;
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
