#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    // kinect初期化
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    angle = 0;
    kinect.setCameraTiltAngle(angle);
}

//--------------------------------------------------------------
void ofApp::update(){
    // kinect更新
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    drawPointCloud();
    cam.end();
}
//--------------------------------------------------------------
void ofApp::drawPointCloud() {
    int width = kinect.width;
    int height = kinect.height;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    int step = 2;
    for (int y = 0; y < height; y += step) {
        for (int x = 0; x < width; x += step) {
            if (kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x, y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    
    // mesh描画
    glPointSize(2);
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    glDisable(GL_DEPTH_TEST);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            angle++;
            if (angle > 30) angle = 30;
            kinect.setCameraTiltAngle(angle);
            break;
        case OF_KEY_DOWN:
            angle--;
            if (angle < -30) angle = -30;
            kinect.setCameraTiltAngle(angle);
            break;
        case 's':
            image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            string title = ofToString(picNum) + ".png";
            image.save(title);
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
