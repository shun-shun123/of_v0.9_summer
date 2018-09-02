//
//  InteractiveMode.hpp
//  HackU2018
//
//  Created by 斉藤俊介 on 2018/08/30.
//

#ifndef InteractiveMode_hpp
#define InteractiveMode_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

struct Elem {
    string entranceStationName;
    string exitStationName;
    string entranceStationId;
    int money;
};

class InteractiveMode {
private:
    vector<struct Elem> dataSets;
    vector<ofVec2f> position;
    vector<vector<bool>> isVisible;
    ofxTrueTypeFontUC font;
    ofxTrueTypeFontUC title;
    int index = 0;
    int ticker = 1;
    bool start = false;
    // mac用
    int xRow[5] = {0, 300, 590, 800, 950};
    // screen用
//    int xRow[5] = {0, 500, 990, 1300, 1500};
    int target = 0;
    int loadingAnim = xRow[4] + 30;
    bool left = true;
public:
    InteractiveMode();
    InteractiveMode(vector<struct Elem> elem);
    void update();
    void draw();
    void isClicked(int x, int y);
};

#endif /* InteractiveMode_hpp */
