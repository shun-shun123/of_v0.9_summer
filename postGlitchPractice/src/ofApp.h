#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxPostGlitch.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    float pow(float value, int time);
		
    ofEasyCam cam;
    // particle parameter
    static const int MAX_NUM = 3000;
    int size = 10;
    int radius = 500;
    ofVbo vbo;
    ofVec3f verticies[MAX_NUM];
    ofFloatColor colors[MAX_NUM];
    // gui parameter
    ofxPanel gui;
    ofxIntSlider num;
    // sphere parameter
    ofSpherePrimitive sphere;
    // ofxPostGlitch parameter
    ofFbo buffer;
    ofxPostGlitch postGlitch;
    bool isPressed = false;
    int type = 0;
    // 2, 3, 4, 7, 8あたり面白い
    ofxPostGlitchType effects[17] = {
        OFXPOSTGLITCH_CONVERGENCE,
        OFXPOSTGLITCH_GLOW,
        OFXPOSTGLITCH_SHAKER,
        OFXPOSTGLITCH_CUTSLIDER,
        OFXPOSTGLITCH_TWIST,
        OFXPOSTGLITCH_OUTLINE,
        OFXPOSTGLITCH_NOISE,
        OFXPOSTGLITCH_SLITSCAN,
        OFXPOSTGLITCH_SWELL,
        OFXPOSTGLITCH_INVERT,
        OFXPOSTGLITCH_CR_HIGHCONTRAST,
        OFXPOSTGLITCH_CR_BLUERAISE,
        OFXPOSTGLITCH_CR_REDRAISE,
        OFXPOSTGLITCH_CR_GREENRAISE,
        OFXPOSTGLITCH_CR_REDINVERT,
        OFXPOSTGLITCH_CR_BLUEINVERT,
        OFXPOSTGLITCH_CR_GREENINVERT
    };
    bool isActive[17] = {false};
    string mode[17] = {
        "OFXPOSTGLITCH_CONVERGENCE",
        "OFXPOSTGLITCH_GLOW",
        "OFXPOSTGLITCH_SHAKER",
        "OFXPOSTGLITCH_CUTSLIDER",
        "OFXPOSTGLITCH_TWIST",
        "OFXPOSTGLITCH_OUTLINE",
        "OFXPOSTGLITCH_NOISE",
        "OFXPOSTGLITCH_SLITSCAN",
        "OFXPOSTGLITCH_SWELL",
        "OFXPOSTGLITCH_INVERT",
        "OFXPOSTGLITCH_CR_HIGHCONTRAST",
        "OFXPOSTGLITCH_CR_BLUERAISE",
        "OFXPOSTGLITCH_CR_REDRAISE",
        "OFXPOSTGLITCH_CR_GREENRAISE",
        "OFXPOSTGLITCH_CR_REDINVERT",
        "OFXPOSTGLITCH_CR_BLUEINVERT",
        "OFXPOSTGLITCH_CR_GREENINVERT"
    };
};
