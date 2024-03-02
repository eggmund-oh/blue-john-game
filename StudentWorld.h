#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp



class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    virtual int init();
    virtual int move();
  virtual void cleanUp();
    ~StudentWorld();
    std::string levelFilefinder(int curLevel);
    std::vector<Actor*> getActors(){
        return m_actorTracker;
    }
   
private:
    std::vector<Actor*> m_actorTracker;
  
};

#endif // STUDENTWORLD_H_
