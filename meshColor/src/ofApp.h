#pragma once

#include "ofMain.h"

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
		
    ofMesh mesh;
    int meshSize = 200;
    vector<ofVec3f> vertices;
    vector<ofFloatColor> colors;
    vector<ofVec3f> velocity;
    vector<float> diffRatio;
    ofVec3f corners[4];
    ofCamera cam;
    ofEasyCam easyCam;
    ofVec3f orbit;
    ofVec3f middle;
    void printCamPosition(ofEasyCam cam) {
        cout << cam.getPosition() << endl;
    }
};
