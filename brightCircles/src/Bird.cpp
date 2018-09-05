//
//  Bird.cpp
//  brightCircles
//
//  Created by 斉藤俊介 on 2018/09/05.
//

#include "Bird.hpp"

void Bird::setup(ofVec2f _mainForce, ofVec2f _gravity, ofVec2f _attractionForce) {
    mainForce = _mainForce;
    gravity = _gravity;
    attractionForce = _attractionForce;
    position = ofVec2f(ofRandomWidth(), ofRandomHeight());
}

void Bird::update(ofVec2f _attractionForce) {
    setAttractionForce(_attractionForce);
    position += direction;
}

void Bird::draw() {
    ofDrawCircle(position, 10);
}

void Bird::calcDirection() {
    direction = (mainForce + gravity + attractionForce) / 3;
}

void Bird::setAttractionForce(ofVec2f _attractionForce) {
    attractionForce = _attractionForce;
    calcDirection();
}

ofVec2f Bird::getPosition() {
    return position;
}
