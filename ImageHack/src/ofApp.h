#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define WIDTH 1024
#define HEIGHT 768

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
		
    ofImage image;
    ofVbo myVbo;
    ofVec3f points[WIDTH * HEIGHT]; // 現在の位置情報を持つ
    ofVec3f temp[WIDTH * HEIGHT]; // 元の位置情報を保持しておく
    ofFloatColor colors[WIDTH * HEIGHT]; // それぞれのピクセルの色情報
    ofVec3f vel[WIDTH * HEIGHT]; // それぞれのピクセルのランダムウォークの速度
    int mode = -1;
};
