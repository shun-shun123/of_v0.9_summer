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
		
    //this holds all of our points
    vector<ofVec3f> points;
    //this keeps track of the center of all the points
    ofVec3f center;
    
    //our camera objects for looking at the scene from multiple perspectives
    ofCamera camera;
    
    //if usecamera is true, we'll turn on the camera view
    bool usecamera;
};

/*
 OF_PRIMITIVE_TRIANGLES:3点集まれば三角形を作るっていう感じ(GL_TRIANGLES)
 OF_PRIMITIVE_TRIANGLE_STRIP:最初の三点で三角形を作ってから１点追加されるごとに新しい三角形を生成して行く(GL_TRIANGLE_STRIP)
 OF_PRIMITIVE_TRIANGLE_FAN:最初の一点を起点に２点が決定すれば三角形を作って行く(GL_TRIANGLE_FAN)
 OF_PRIMITIVE_LINES:2点が決まれば線を描く(GL_LINES)
 OF_PRIMITIVE_LINE_STRIP:点をどんどん繋いで線を作る(GL_LINE_STRIP)
 OF_PRIMITIVE_LINE_LOOP:最初の一点を起点に線を描いて行く(GL_LINE_LOOP)
 OP_PRIMITIVE_POINTS:頂点に点を描画する
 */
