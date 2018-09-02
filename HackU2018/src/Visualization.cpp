//
//  Visualization.cpp
//  HackU2018
//
//  Created by 斉藤俊介 on 2018/08/30.
//

#include "Visualization.hpp"
Visualization::Visualization() {
    cout << "No argument Visualization is created" << endl;
}

Visualization::Visualization(vector<struct Elem> elem) {
    cout << "Visualization is successfully created" << endl;
    this->dataSets = elem;
    this->font.load("sazanami.ttf", 90);
    ofSetCircleResolution(64);
    
    sphere.set(800, 10);
    sphere.setPosition(0, 0, 0);
    mesh = sphere.getMesh();
    int index = 0;
    while (this->position.size() != this->dataSets.size()) {
        index = int(ofRandom(mesh.getVertices().size()));
        if (mesh.getVertices()[index].x > 1) {
            bool isAdd = true;
            for (int i = 0; i < this->position.size(); i++) {
                if (this->position[i].distance(mesh.getVertices()[index]) <= 100) {
                    isAdd = false;
                    break;
                }
            }
            if (isAdd) {
                if (ofRandom(-1, 1) < 0) {
                    this->position.push_back(mesh.getVertices()[index] * 0.9);
                } else {
                    ofVec3f added = mesh.getVertices()[index];
                    added.x = added.x * -1;
                    if (ofRandom(-1, 1) < 0) {
                        this->position.push_back(added * 0.9);
                    } else {
                        added.z = added.z * -1;
                        this->position.push_back(added * 0.9);
                    }
                }
                this->colors.push_back(ofColor::fromHsb(ofRandom(255), 255, 255));
                this->angle.push_back(ofRandom(30, 60));
            }
        }
    }
    cout << this->dataSets.size() << endl;
    // particle用のmesh初期設定
    particleMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 3; j++) {
            ofVec3f pos = ofVec3f(ofRandom(-2000, 2000), ofRandom(-2000, 2000), ofRandom(-2000, 2000));
            ofVec3f sub = pos - ofVec3f(ofRandom(-20, 20), ofRandom(-20, 20), ofRandom(-20, 20));
            ofVec3f add = pos + ofVec3f(ofRandom(-20, 20), ofRandom(-20, 20), ofRandom(-20, 20));
            particleMesh.addVertex(pos);
            particleMesh.addVertex(sub);
            particleMesh.addVertex(add);
            particleMesh.addColor(ofFloatColor::fromHsb(ofRandom(1.0), 0.2, 1.0));
            particleMesh.addColor(ofFloatColor::fromHsb(ofRandom(1.0), 0.2, 1.0));
            particleMesh.addColor(ofFloatColor::fromHsb(ofRandom(1.0), 0.2, 1.0));
        }
    }
}

void Visualization::update() {

}

void Visualization::draw() {
    cam.lookAt(ofVec3f(center), ofVec3f(0, -1, 0));
    cam.begin();
    ofPushMatrix();
    ofTranslate(center);
    environment();
    rotateStationNames();
    particle();
    ofPopMatrix();
    cam.end();
}

void Visualization::rotateStationNames() {
    ofRotateY(ofGetFrameNum() / 2);
    for (int i = 0; i < this->dataSets.size(); i++) {
        ofPushMatrix();
        ofTranslate(this->position[i].x, this->position[i].y, this->position[i].z);
        ofRotateY(angle[i]);
        ofSetColor(this->colors[i]);
        font.drawString(this->dataSets[i].entranceStationName, 0, 0);
        ofPopMatrix();
    }
    ofPushStyle();
    ofSetColor(255, ofGetFrameNum() % 120);
    sphere.drawWireframe();
    ofPopStyle();
}

void Visualization::particle() {
    particleMesh.draw();
}

void Visualization::environment() {
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(5);
    
    ofPushMatrix();
    ofRotateX(ofGetFrameNum());
    ofSetColor(200, 100, 50, ofGetFrameNum() % 100 + 100);
    ofDrawCircle(0, 0, 1500 + (ofGetFrameNum() * 5 % 500));
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateX(ofGetFrameNum() * 0.7);
    ofSetColor(50, 200, 10, ofGetFrameNum() % 100 + 100);
    ofDrawCircle(0, 0, 800);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateY(ofGetFrameNum());
    ofSetColor(100, 50, 200, ofGetFrameNum() % 100 + 100);
    ofDrawCircle(0, 0, 800);
    ofPopMatrix();
    ofPopStyle();
}
