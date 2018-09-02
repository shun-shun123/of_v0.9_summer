#pragma once

#include "ofMain.h"
#include "ofxJson.h"
#include "Visualization.hpp"

// Jsonデータを取り出す時のKey
const string inStaKey = "entranceStationName";
const string outStaKey = "exitStationName";
const string dateKey = "entranceStationId";
const string moneyKey = "exitStationID";

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
    
    void loadData(string file, ofxJSONElement& json);
    vector<struct Elem> buildDataSet(ofxJSONElement json);
    InteractiveMode *interactiveMode = 0;
    Visualization *visualization = 0;
    int state = 0;
};
