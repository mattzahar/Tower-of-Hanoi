//
// Created by jacel on 4/25/2019.
//

#include "confetti.h"
#include "math.h"

Confetti::Confetti() {
    // populate vector of shape pointers
    spawnConfetti();
}

void Confetti::draw() {
    // draw each shape
    // polymorphism (different draw method for each shape type)
    for (const auto& p: confetti) {
        p->draw();
    }
}

void Confetti::spawnConfetti() {
    // make 50 shapes
    for (int i = 0; i < 80; ++i) {
        // every fifth shape is a circle
        if (i % 5 == 0) {
            // create circle with random position and color, and add it to vector of shape pointers
            Circle circle(rand() % Game::width, rand() % Game::height, RADIUS);
            circle.setFill({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0});
            confetti.push_back(make_unique<Circle>(circle));
        } else {

            // create Quad at random position and color, adding it to vector of shape pointers
            Quad quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0},
                      {rand() % Game::width, rand() % Game::height}, QUAD_SIZE, QUAD_SIZE);
            confetti.push_back(make_unique<Quad>(quad));

        }
    }
}

void Confetti::timestep() {
    // for every piece of confetti
    for (auto &p : confetti) {
        // move it down two and maybe to the side
        int deltaY = 2;
        int deltaX = (rand() % (int) 3) * pow(-1, rand() % 20);
        p->setX(p->getX() + deltaX);
        p->setY(p->getY() + deltaY);

        // if it goes past end of screen, move it back to the top
        if (p->getY() > Game::height) {
            p->setY(0);
        }
    }
}