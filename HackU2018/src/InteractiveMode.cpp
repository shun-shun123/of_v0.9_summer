//
//  InteractiveMode.cpp
//  HackU2018
//
//  Created by 斉藤俊介 on 2018/08/30.
//

#include "InteractiveMode.hpp"

//InteractiveMode::InteractiveMode(vector<struct Elem> elem) {
//    this->dataSets = elem;
//}

InteractiveMode::InteractiveMode() {
    cout << "No argument InteractiveMode is created" << endl;
}

InteractiveMode::InteractiveMode(vector<struct Elem> elem) {
    cout << "InteractiveMode is successfully created" << endl;
    this->dataSets = elem;
    for (int i = 0; i < this->dataSets.size(); i++) {
        int y = (ofGetHeight() - 50) / this->dataSets.size() * i + 50;
        this->position.push_back(ofVec2f(0, y + 50));
        vector<bool> addElem;
        for (int j = 0; j < 4; j++) {
            addElem.push_back(false);
        }
        this->isVisible.push_back(addElem);
    }
    int fontSize = this->position[1].y - this->position[0].y - 30;
    font.load("sazanami.ttf", fontSize);
    title.load("sazanami.ttf", 25);
}

void InteractiveMode::update() {
    if (start) {
        if (index < this->dataSets.size()) {
            if (ticker % 5 == 0) {
                isVisible[index][target] = true;
                target++;
                if (target == 4) {
                    index++;
                    target = 0;
                }
            }
        }
    }
    ticker++;
    if (ticker >= 100)
        start = true;
    if (left) {
        loadingAnim += 2;
    } else {
        loadingAnim -= 2;
    }
    if (loadingAnim <= xRow[4] + 30)
        left = true;
    else if (loadingAnim >= xRow[4] + 240)
        left = false;
}

void InteractiveMode::draw() {
    ofPushStyle();
    font.drawString("出発駅名", xRow[0], 40);
    font.drawString("到着駅名", xRow[1], 40);
    font.drawString("日付", xRow[2], 40);
    font.drawString("残高", xRow[3], 40);
    ofSetColor(0, 200, 200);
    for (int i = 0; i < this->dataSets.size(); i++) {
        if (!isVisible[i][0])
            break;
        font.drawString(this->dataSets[i].entranceStationName, xRow[0], position[i].y);
        if (!isVisible[i][1])
            break;
        font.drawString(this->dataSets[i].exitStationName, xRow[1], position[i].y);
        if (!isVisible[i][2])
            break;
        font.drawString(this->dataSets[i].entranceStationId.substr(0, 10), xRow[2], position[i].y);
        if (!isVisible[i][3])
            break;
        font.drawString(ofToString(this->dataSets[i].money) + "円", xRow[3], position[i].y);
    }
    ofPopStyle();
    ofPushStyle();
    ofSetColor(255, (ofGetFrameNum() * 2) % 150 + 50);
    if (isVisible[isVisible.size() - 1][3]) {
        title.drawString("Where will you go next?\nPress 1 key", xRow[4], ofGetHeight() / 2);
    } else {
        title.drawString("Now Loading", xRow[4] + 30, ofGetHeight() / 2);
        ofDrawCircle(loadingAnim, ofGetHeight() / 2 + 10, 5);
    }
    ofPopStyle();
}

void InteractiveMode::isClicked(int x, int y) {

}
