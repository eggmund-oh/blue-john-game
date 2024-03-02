#include "Actor.h"
#include "StudentWorld.h"
#include <iostream>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp



Actor::Actor( double startX, double startY, int imageID, StudentWorld* world, int dir, double size)
:GraphObject(imageID, startX, startY, dir, size), m_world(world),  m_startX(startX), m_startY(startY), m_imageID(imageID), m_dir(dir), m_size(size)
{
    setVisible(true);
}

PlayerAvatar::PlayerAvatar(int startX, int startY, StudentWorld* world, int imageID):
Actor(startX, startY, imageID, world, right, 1.0), m_healthPoints(100), m_nPeas(0)
{
   
}


class StudentWorld;

void PlayerAvatar::doSomething() {
    int ch;
    StudentWorld* world = getWorld();
    if (world->getKey(ch)) {
        double newX = getX();
        double newY = getY();
        switch (ch) {
            case KEY_PRESS_UP:
                setDirection(up);
                newY++;
                break;
            case KEY_PRESS_DOWN:
                setDirection(down);
                newY--;
                break;
            case KEY_PRESS_LEFT:
                setDirection(left);
                newX--;
                break;
            case KEY_PRESS_RIGHT:
                setDirection(right);
                newX++;
                break;
            default:
                break;
        }

        // Boundary check
        if (newX >= 0 && newX < VIEW_WIDTH && newY >= 0 && newY < VIEW_HEIGHT) {
            // Obstacle check
            bool canMove = true;
            for (Actor* actor : world->getActors()) {
                // Check if actor is not the player and is occupying the target location
                if (actor != this && actor->getX() == newX && actor->getY() == newY) {
                    canMove = false;
                    break;
                }
            }
            if (canMove) {
                // Update position
                moveTo(newX, newY);
            }
        }
    }
}


Wall::Wall(double startX, double startY, StudentWorld* world, int imageID)
: Actor(startX, startY, imageID, world, none, 1.0) {
    
}
