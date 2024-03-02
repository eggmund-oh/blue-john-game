#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

class Actor : public GraphObject {
public:
    // Constructor
    Actor( double startX, double startY, int imageID, StudentWorld* world, int dir = right, double size = 1.0);
    
    virtual void doSomething() = 0;
    virtual ~Actor(){}

    
    int getDir() const{
        return m_dir;
        
    }
    void setDir(int newDir ){
         m_dir = newDir;
        setDirection(m_dir);
    }
    void setX(double newX){
        m_startX = newX;
        moveTo(m_startX, m_startY);
    }
    void setY(double newY){
        m_startY = newY;
        moveTo(m_startX, m_startY);
    }
    StudentWorld* getWorld() const{
        return m_world;
    }
private:
    StudentWorld* m_world;
    double m_startX;
    double m_startY;
    int m_imageID;
    int m_dir;
    double m_size;
    
};

class Wall : public Actor{
public:
    //constructor
    Wall(double startX, double startY, StudentWorld* world, int imageID = IID_WALL);
    // it needs to make itself visible setVisible(true)
    void doSomething() override {}
    
private:
  
    
};

class PlayerAvatar : public Actor {
public:
    //Must have ID image player
    // proper location when constructor called by init in StudentWorld
    // initial state
    PlayerAvatar(int startX, int startY, StudentWorld* world, int imageID = IID_PLAYER);
    // make itself visible
    
    // lets user pick a direction by hitting a directional key
    // by properly changing the x y coordinates and direction
    // at each tick
    void doSomething() override;
    
    // reduce number of peas by 1;
    void reducePeas();
    
    //check if hasPeas to fire
    bool hasPeas();
    int getHealth() const{
        return m_healthPoints;
    }
    int getNPeas() const{
        return m_nPeas;
    }
    
private:
    int m_healthPoints;
    int m_nPeas;

};

//class Pea : public Actor {
//public:
//    Pea(int startX, int startY, StudentWorld* world, int imageID = IID_PEA)
//        : Actor(startX, startY, world, imageID) {}
//};


class RageBot : public Actor {
public:
    // Constructor and member functions specific to RageBot
    // Define here...
};

class HorizontalRageBot : public RageBot {
public:
    // Constructor and member functions specific to HorizontalRageBot
    // Define here...
};

class VerticalRageBot : public RageBot {
public:
    // Constructor and member functions specific to VerticalRageBot
    // Define here...
};

class ThiefBot : public Actor {
public:
    // Constructor and member functions specific to ThiefBot
    // Define here...
};

class MeanThiefBot : public ThiefBot {
public:
    // Constructor and member functions specific to MeanThiefBot
    // Define here...
};

class Factory : public Actor {
public:
    // Constructor and member functions specific to Factory
    // Define here...
};

class RegularFactory : public Factory {
public:
    // Constructor and member functions specific to RegularFactory
    // Define here...
};

class MeanFactory : public Factory {
public:
    // Constructor and member functions specific to MeanFactory
    // Define here...
};

// Define classes for other objects similarly...






#endif // ACTOR_H_
