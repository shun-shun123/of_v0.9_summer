#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    image.load("image.jpg");
    unsigned char* pixels = image.getPixels().getData();
    for (int w = 0; w < WIDTH; w++) {
        for (int h = 0; h < HEIGHT; h++) {
            float red = ofMap(image.getColor(w, h).r, 0, 255, 0, 1.0);
            float green = ofMap(image.getColor(w, h).g, 0, 255, 0, 1.0);
            float blue = ofMap(image.getColor(w, h).b, 0, 255, 0, 1.0);
            colors[h + w * HEIGHT] = ofFloatColor(red, green, blue);
            points[h + w * HEIGHT] = ofVec3f(ofRandomWidth(), ofRandomHeight(), ofRandom(-1000));
            temp[h + w * HEIGHT] = ofVec3f(w, h, 0);
            vel[h + w * HEIGHT] = ofVec3f(ofRandom(-10, 10), ofRandom(-10, 10), ofRandom(-5, 5));
        }
    }
    myVbo.setVertexData(points, WIDTH * HEIGHT, GL_DYNAMIC_DRAW);
    myVbo.setColorData(colors, WIDTH * HEIGHT, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    switch (mode) {
        case 0: // 元の画像復元
            for (int w = 0; w < WIDTH; w++) {
                for (int h = 0; h < HEIGHT; h++) {
                    ofVec3f vel = (temp[h + w * WIDTH] - points[h + w * WIDTH]) * 0.1;
                    points[h + w * WIDTH] += vel;
                }
            }
            break;
        case 1: // ランダムウォーク
            for (int w = 0; w < WIDTH; w++) {
                for (int h = 0; h < HEIGHT; h++) {
                    points[h + w * WIDTH] += vel[h + w * WIDTH];
                }
            }
            break;
    }
    myVbo.updateVertexData(points, WIDTH * HEIGHT);
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (mode == -1) {
//        image.draw(0, 0);
    } else {
        glPointSize(1);
        myVbo.draw(GL_POINTS, 0, WIDTH * HEIGHT);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case '0':
            mode = 0;
            break;
        case '1':
            mode = 1;
            break;
        default:
            mode = -1;
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
