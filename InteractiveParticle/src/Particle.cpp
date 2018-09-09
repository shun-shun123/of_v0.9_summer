//
//  Particle.cpp
//  InteractiveParticle
//
//  Created by 斉藤俊介 on 2018/09/10.
//

#include "Particle.hpp"
void Particle::setup() {
    position = ofVec2f(ofRandomWidth(), ofRandomHeight());
    velocity = ofVec2f(0, 0);
    acceleration = ofVec2f(0, 0);
    float f = ofRandom(0.01, 0.04);
    friction = ofVec2f(f, f);
    gravity = ofVec2f(0, ofRandom(0.1, 0.8));
}

void Particle::update(int mode) {
    if (!mode) {
        velocity += gravity;
    }
    velocity += acceleration;
    velocity *= ofVec2f(1.0, 1.0) - friction;
    position += velocity;
    bounceOffWalls();
    acceleration = ofVec2f(0, 0);
}

ofVec2f Particle::getVertex() {
    return position;
}

void Particle::bounceOffWalls() {
    if (position.x < 0) {
        position.x = 0;
        velocity.x *= -1;
    } else if (position.x > ofGetWidth()) {
        position.x = ofGetWidth();
        velocity.x *= -1;
    }
    if (position.y > ofGetHeight()) {
        position.y = ofGetHeight();
        velocity.y *= -1;
    }
}

void Particle::mouseDragged() {
    ofVec2f temp = ofVec2f(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    ofVec2f cur = ofVec2f(ofGetMouseX(), ofGetMouseY());
    ofVec2f direction = cur - temp;
    acceleration += direction * ofRandom(0.01, 0.1);
}

void Particle::attraction() {
    ofVec2f cur = ofVec2f(ofGetMouseX(), ofGetMouseY());
    ofVec2f attraction = (cur - position) / ofGetWidth() ;
    acceleration += attraction;
}
