#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Bird.hpp"

static const int NUM = 10000;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void init();
    void guiSetup();
    void bounds(ofVec2f& _position, ofVec2f& _velocity);
    
    ofVbo vbo;
    ofVec2f position[NUM];
    ofVec2f velocity[NUM];
    ofFloatColor color[NUM];
    ofVec2f gravity[NUM];
    ofVec2f friction = ofVec2f(0.99, 0.99);
    
    ofxFloatSlider red;
    ofxFloatSlider green;
    ofxFloatSlider blue;
    ofxFloatSlider alpha;
    ofxIntSlider num;
    ofxPanel gui;
};
