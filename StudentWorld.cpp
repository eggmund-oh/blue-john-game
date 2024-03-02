#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <sstream>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}

// based on currentLevel, outputs the string file name of the level data file
string levelFileFinder(int curLevel){
    std::ostringstream folderName;
    if (curLevel < 10){
        folderName << "level0" << curLevel << ".txt";
    } else {
        folderName << "leevl" << curLevel << ".txt";
    }
    
    return folderName.str();
}

int StudentWorld::init()
{
    //load levels
    string curLevel = levelFileFinder(getLevel());
    Level lev(assetPath());
    Level::LoadResult result = lev.loadLevel(curLevel);
    if (result == Level::load_fail_file_not_found ||
     result == Level:: load_fail_bad_format)
     return -1; //something going wrong
   
    // get contents of the levels
        //iterate through 0 -14
    for(int i = 0; i < VIEW_WIDTH; i++){
        for(int j = 0; j < VIEW_HEIGHT; j++){
            Level::MazeEntry item = lev.getContentsOf(i, j);
            switch(item) {
                case Level::player:{
                    PlayerAvatar* new_Player = new PlayerAvatar(i, j, this);
                    m_actorTracker.push_back(new_Player);
                    break;
                }
                case Level::wall:{
                    Wall* new_Wall = new Wall(i, j, this);
                    m_actorTracker.push_back(new_Wall);
                    break;
                }
                case Level::empty:
                    // Handle empty space
                    break;
                case Level::exit:
                    // Handle exit
                    break;
                case Level::horiz_ragebot:
                    // Handle horizontal ragebot
                    break;
                case Level::vert_ragebot:
                    // Handle vertical ragebot
                    break;
                case Level::thiefbot_factory:
                    // Handle thiefbot factory
                    break;
                case Level::mean_thiefbot_factory:
                    // Handle mean thiefbot factory
                    break;
                case Level::marble:
                    // Handle marble
                    break;
                case Level::pit:
                    // Handle pit
                    break;
                case Level::crystal:
                    // Handle crystal
                    break;
                case Level::restore_health:
                    // Handle restore health
                    break;
                case Level::extra_life:
                    // Handle extra life
                    break;
                case Level::ammo:
                    // Handle ammo
                    break;
            }
        }
    }

    
    
    
    
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you type q

    setGameStatText("Game will end when you type q");
    
    for(int i = 0; i < m_actorTracker.size(); i ++){
        Actor* actor = m_actorTracker[i];
        actor->doSomething();
       
    
    }
    
    
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    for(int i = 0; i < m_actorTracker.size(); i ++){
        Actor* actor = m_actorTracker[i];
        delete actor;
    }
    m_actorTracker.clear();
   
  
}


StudentWorld::~StudentWorld(){
    cleanUp();
    
}
