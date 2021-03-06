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
    void audioIn(float *input, int bufferSize, int nChannels);
		
    vector<ofVec3f> circles;
    vector<ofFloatColor> colors;
    int resolution = 64;
    int scale = 300;
    float hue = 0.0;
    ofMesh mesh;
    float rotateZ = 0;
    ofSoundStream soundStream;
    float curVol;
    
};
