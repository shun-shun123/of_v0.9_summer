#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    corners[0] = ofVec3f(0, 0, 0);
    corners[1] = ofVec3f(0, ofGetHeight(), 0);
    corners[2] = ofVec3f(ofGetWidth(), 0, 0);
    corners[3] = ofVec3f(ofGetWidth(), ofGetHeight(), 0);
    int target = 0;
    for (int i = 0; i < meshSize; i++) {
        if (i % (meshSize / 4) == 0) {
            vertices.push_back(corners[target]);
            colors.push_back(ofFloatColor::fromHsb(ofRandom(0.3, 0.8), 1.0, 1.0));
            target++;
        }
        vertices.push_back(ofVec3f(ofRandomWidth(), ofRandomHeight(), ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2)));
        colors.push_back(ofFloatColor::fromHsb(ofRandom(0, 1.0), ofRandom(0.8, 1.0), ofRandom(0.8, 1.0)));
    }
    for (int i = 0; i < vertices.size(); i++) {
        velocity.push_back(ofVec3f(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0), 0.0));
    }
    for (int i = 0; i < vertices.size(); i++) {
        middle += vertices[i];
    }
    middle /= float(vertices.size());
    cam.lookAt(middle);
    cam.setPosition(0.0, 0.0, 700.0);
    orbit = cam.getPosition();
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] += velocity[i];
        if (vertices[i].x < 0 || vertices[i].x > ofGetWidth()) {
            velocity[i].x *= -1.0;
        }
        if (vertices[i].y < 0 || vertices[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
    }
    mesh.addVertices(vertices);
    mesh.addColors(colors);
    orbit.x = 300 * sin(ofGetElapsedTimef());
    orbit.y = 300 * cos(ofGetElapsedTimef());
    cam.setPosition(orbit);
    cam.lookAt(middle);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.draw();
    ofBoxPrimitive box = ofBoxPrimitive(100, 100, 100);
    box.setPosition(orbit);
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
