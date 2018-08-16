#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofToggleFullscreen();
    ofSetWindowTitle("OF_PRIMITIVE_TRIANGLE_FAN");
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    vertices.push_back(ofVec3f(0, 0, 0));
    vertices.push_back(ofVec3f(0, ofGetHeight(), 0));
    vertices.push_back(ofVec3f(ofGetWidth(), 0, 0));
    vertices.push_back(ofVec3f(ofGetWidth(), ofGetHeight(), 0));
    for (int i = 0; i < vertices.size(); i++) {
        colors.push_back(ofFloatColor::fromHsb(ofRandom(0.2, 0.9), 1.0, 1.0));
    }
    // 頂点情報を初期化
    for (int i = 0; i < meshSize; i++) {
        vertices.push_back(ofVec3f(ofRandomWidth(), ofRandomHeight(), ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2)));
        colors.push_back(ofFloatColor::fromHsb(ofRandom(0, 1.0), ofRandom(0.8, 1.0), ofRandom(0.8, 1.0)));
    }
    // 各頂点の色変化率を決定
    for (int i = 0; i < vertices.size(); i++) {
        diffRatio.push_back(sin(ofRandom(-PI, PI)) * 0.005);
    }
    // 中心を判定
    for (int i = 0; i < vertices.size(); i++) {
        middle += vertices[i];
    }
    middle /= float(vertices.size());
    cam.lookAt(middle);
    cam.setPosition(0.0, 0.0, 350.0);
    orbit = cam.getPosition();
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    // 色情報を変化させる
    for (int i = 0; i < vertices.size(); i++) {
        float hue = colors[i].getHue();
        hue = (hue + diffRatio[i] <= 1.0)? hue + diffRatio[i] : 0.0;
        colors[i].setHue(hue);
    }
    
    mesh.addVertices(vertices);
    mesh.addColors(colors);
    orbit.x = 600 * sin(ofGetElapsedTimef() / 15.0);
    orbit.y = 600 * cos(ofGetElapsedTimef() / 15.0);
    cam.setPosition(orbit + middle);
    cam.lookAt(middle);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.draw();
    ofBoxPrimitive box = ofBoxPrimitive(100, 100, 100);
    box.setPosition(orbit + middle);
//    box.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
            ofSetWindowTitle("OF_PRIMITIVE_TRIANGLE_FAN");
            break;
        case '1':
            mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            ofSetWindowTitle("OF_PRIMITIVE_TRIANGLE_STRIP");
            break;
        case '2':
            mesh.setMode(OF_PRIMITIVE_TRIANGLES_ADJACENCY);
            ofSetWindowTitle("OF_PRIMITIVE_TRIANGLES_ADJACENCY");
            break;
        case '3':
            mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
            ofSetWindowTitle("OF_PRIMITIVE_LINE_LOOP");
            break;
        case '4':
            mesh.setMode(OF_PRIMITIVE_TRIANGLES);
            ofSetWindowTitle("OF_PRIMITIVE_TRIANGLES");
            break;
        case '5':
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP_ADJACENCY);
            ofSetWindowTitle("OF_PRIMITIVE_LINE_STRIP_ADJACENCY");
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
