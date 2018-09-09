//
//  Particle.hpp
//  InteractiveParticle
//
//  Created by 斉藤俊介 on 2018/09/10.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"
class Particle {
private:
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f friction;
    ofVec2f gravity;
public:
    void setup();
    void update(int mode);
    ofVec2f getVertex();
    void bounceOffWalls();
    void mouseDragged();
    void attraction();
};
#endif /* Particle_hpp */
