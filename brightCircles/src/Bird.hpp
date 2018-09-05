//
//  Bird.hpp
//  brightCircles
//
//  Created by 斉藤俊介 on 2018/09/05.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include "ofMain.h"
class Bird {
public:
    void setup(ofVec2f _mainForce, ofVec2f _gravity, ofVec2f _attarctionForce);
    void update(ofVec2f _attractionForce);
    void draw();
    ofVec2f getPosition();
private:
    ofVec2f mainForce;
    ofVec2f gravity;
    ofVec2f attractionForce;
    ofVec2f direction;
    ofVec2f position;
    void calcDirection();
    void setAttractionForce(ofVec2f _attractionForce);
};
#endif /* Bird_hpp */
