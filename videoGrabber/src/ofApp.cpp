#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    camWidth = 1280;
    camHeight = 720;
    
    videoGrabber.setVerbose(true);
    videoGrabber.initGrabber(camWidth, camHeight);
    image.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    guiSetup();
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
//    videoGrabber.draw(20, 20);

    unsigned char *pixels = videoGrabber.getPixels().getData();
    for (int w = 0; w < camWidth; w += 10) {
        for (int h = 0; h < camHeight; h += 10) {
            // RGBの明度を取得
            unsigned char r = pixels[(h * camWidth + w) * 3];
            unsigned char g = pixels[(h * camWidth + w) * 3 + 1];
            unsigned char b = pixels[(h * camWidth + w) * 3 + 2];
            ofSetColor(255, 0, 0, alpha);
            ofDrawCircle(w, 20 + h,diameter * (float)r/255.0);
            ofSetColor(0, 255, 0, alpha);
            ofDrawCircle(w, 20 + h, diameter * (float)g/255.0);
            ofSetColor(0, 0, 255, alpha);
            ofDrawCircle(w, 20 + h, diameter * (float)b/255.0);
        }
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's':
            videoGrabber.videoSettings();
            break;
        case ' ':// スペースキーのとき
            ofPixels pixels = videoGrabber.getPixels();
            image.setFromPixels(videoGrabber.getPixels());
            image.save("pic.png");
            cout << "Successfully Saved" << endl;
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

//--------------------------------------------------------------
void ofApp::guiSetup() {
    gui.setup();
    gui.add(diameter.setup("diameter", 20.0, 10.0, 30.0));
    gui.add(alpha.setup("alpha", 100, 50, 150));
}
