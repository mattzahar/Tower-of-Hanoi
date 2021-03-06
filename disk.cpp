//
// Created by jacel on 4/25/2019.
//

#include "disk.h"
#include "graphics.h"

Disk::Disk(){}

Disk::Disk(int size, int id, double x, double y) {
    center.x = x;
    center.y = y;
    myColor = {.2*(rand()%10),.2*(rand()%10), .2*(rand()%10)};

    this->size = size;
    this->ID = id;
}

void Disk::draw() {
    glColor3f(myColor.red, myColor.green, myColor.blue);
    glBegin(GL_QUADS);
    glVertex2d(this->center.x + this->size, this->center.y + 10);
    glVertex2d(this->center.x + this->size, this->center.y - 10);
    glVertex2d(this->center.x - this->size, this->center.y - 10);
    glVertex2d(this->center.x - this->size, this->center.y + 10);
    glEnd();
}

bool Disk::isOverlapping(double x, double y) {
    if (this == NULL) {
        throw "no disk in stack error";
    }
    if (this->selectable) {
        if (y < this->center.y + 10 && y > this->center.y - 10) {
            if (x < this->center.x + size && x > this->center.x - size) {
                return true;
            }
        }
    }
    return false;
}
