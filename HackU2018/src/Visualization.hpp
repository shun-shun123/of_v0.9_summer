//
//  Visualization.hpp
//  HackU2018
//
//  Created by 斉藤俊介 on 2018/08/30.
//

#ifndef Visualization_hpp
#define Visualization_hpp

#include <stdio.h>
#include "ofMain.h"
#include "InteractiveMode.hpp"

class Visualization {
private:
    const ofVec3f center = ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2, -1000);
    vector<struct Elem> dataSets;
    ofxTrueTypeFontUC font;
    vector<ofVec3f> position;
    vector<ofColor> colors;
    vector<int> angle;
    // 球体の描画に使う
    ofSpherePrimitive sphere;
    ofMesh mesh;
    ofMesh particleMesh;
    ofEasyCam cam;
public:
    Visualization();
    Visualization(vector<struct Elem> elem);
    void update();
    void draw();
    void environment();
    void rotateStationNames();
    void particle();
};

#endif /* Visualization_hpp */
