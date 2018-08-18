#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    camWidth = 640;
    camHeight = 360;
    
    videoGrabber.setVerbose(true);
//    videoGrabber.initGrabber(camWidth, camHeight);
    videoGrabber.setup(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoGrabber.draw(200, 0, camWidth, camHeight);

    unsigned char *pixels = videoGrabber.getPixels().getData();
    for (int w = 0; w < camWidth; w += 10) {
        for (int h = 0; h < camHeight; h += 10) {
            // RGBの明度を取得
            unsigned char r = pixels[(h * camWidth + w) * 3];
            unsigned char g = pixels[(h * camWidth + w) * 3 + 1];
            unsigned char b = pixels[(h * camWidth + w) * 3 + 2];
            ofSetColor(255, 0, 0, 100);
            ofDrawCircle(200 + w,camHeight + h,20.0 * (float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofDrawCircle(200 + w,camHeight + h,20.0 * (float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofDrawCircle(200 + w,camHeight + h,20.0 * (float)b/255.0);
        }
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
