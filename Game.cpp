#include "Game.h"
using namespace std;
// Game constructor, initialize 2 maps received.
Game::Game() { // initialize both maps by template matrix
    //map 1:
    int mapArray1 [7][7] = {{1,1,1,0,0,1,1},
                            {0,0,0,0,1,1,0},
                            {0,1,1,0,0,0,0},
                            {0,0,1,1,1,0,1},
                            {0,0,0,1,1,0,1},
                            {0,1,1,1,1,0,0},
                            {0,0,0,0,0,1,1}};
    //map 2:
    int mapArray2 [7][7] = {{1,1,0,0,1,1,1},
                            {0,1,0,1,1,1,1},
                            {1,0,0,1,0,0,0},
                            {0,1,0,1,0,1,0},
                            {0,1,0,0,0,1,0},
                            {0,1,1,1,1,1,1},
                            {0,0,1,1,1,1,1}};
    map1 = new Map (mapArray1);
    map2 = new Map (mapArray2);
}

// Add Robot to a specific map and coordinates
void Game::AddRobot(int mapNumber, int x, int y) {
    bool path_result;
    if (mapNumber == 1) { // check if we need map1 or map2
        path_result = map1->checkPathForRob(x, y);} // function that checks if coordinates is on a path '0'
    else path_result = map2->checkPathForRob(x, y);
    if(x > 6 or x < 0 or y > 6 or y < 0) path_result = false; // if out of bounds of map
    if(path_result){RobosArr.emplace_back(new Robot(x, y, mapNumber));}
    else cout<<"Invalid location"<<endl;
}
// Delete robot from vector
void Game::DeleteRobot(int robotNum) {
    for(int i = 0; i < RobosArr.size(); i++){
        if(robotNum == RobosArr[i]->getRobNum()) { // find robot in vector, print and erase
           cout << "Robot deleted : " << RobosArr[i]->getRobNum() << " MAP: " << RobosArr[i]->getMapNum() << " GPS: "<<RobosArr[i]->getXloc()<<","<<RobosArr[i]->getYloc()<<endl;
            delete RobosArr[i];
            RobosArr.erase(RobosArr.begin() + i);
            break;
        }
    }
    RobosArr.shrink_to_fit();
}
// Move the robot around the map
void Game::MoveRobot(int robotNum, char dir) {
    int AfterChangeX, AfterChangeY;
    bool path_result;
    for(auto & robot : RobosArr){
        if(robotNum == robot->getRobNum()) { // find the correct robot
            // check all possible outcomes before moving robot
            AfterChangeY = robot->getYloc();
            AfterChangeX = robot->getXloc();
            if(dir == 'U'){ // Move up one step
                AfterChangeY++;
            }
            if(dir == 'D'){ // Move down one step
                AfterChangeY--;
            }
            if(dir == 'L'){ // Move left one step
                AfterChangeX--;
            }
            if(dir == 'R'){ // Move right one step
                AfterChangeX++;
            }
            if(robot->getMapNum() == 1){// check which map
                path_result = map1->checkPathForRob(AfterChangeX, AfterChangeY);// check if coordinates are in map
            }
            else path_result = map2->checkPathForRob(AfterChangeX, AfterChangeY);
            if(path_result){robot->changeLocation(dir);}


        }
    }
}
// Default destructor
Game::~Game(){
    delete map1;
    delete map2;
    for (auto & robot : RobosArr){
        delete robot;
    }
    RobosArr.clear();
    RobosArr.reserve(0);
}

void Game::OPplusMap() {
    bool transferred;
    Map OpMap = *map1 + *map2;
    for (auto & robot : RobosArr){
        // check if transfer is available
        transferred = OpMap.checkPathForRob(robot->getXloc(), robot->getYloc());
        if (transferred){
            // if available, print robot with no map number
            cout<<"Robot: "<<robot->getRobNum()<<" GPS: "<<robot->getXloc()<<","<<robot->getYloc()<<" "<<endl;
        }
    }
}

void Game::OPeqplusMap(int mapNum) {
    bool transferred;
    if(mapNum == 1){ // if mapNum is 1, use += on 1, and remove robots in a wall
       *map1 += *map2;
        for(int i = 0; i < RobosArr.size(); i++){
            if(RobosArr[i]->getMapNum() == mapNum){
                transferred = map1->checkPathForRob(RobosArr[i]->getXloc(), RobosArr[i]->getYloc());
                if (!transferred){ // if not transfrerred to new map after operator, delete robot
                    delete RobosArr[i];
                    RobosArr.erase(RobosArr.begin() + i);
                }
            }
        }
        RobosArr.shrink_to_fit();// reduce vector size
    }
    else{ // if mapNum is 2
        *map2 += *map1;
        for(int i = 0; i < RobosArr.size(); i++){
            if(RobosArr[i]->getMapNum() == mapNum){
                transferred = map2->checkPathForRob(RobosArr[i]->getXloc(), RobosArr[i]->getYloc());
                if (!transferred){ // if not transfrerred to new map after operator, delete robot
                    delete RobosArr[i];
                    RobosArr.erase(RobosArr.begin() + i);
                }
            }
        }
        RobosArr.shrink_to_fit();
    }

}

void Game::OPeqMap() {
    // access to main
    *map1 == *map2;
}

void Game::OPcopyMap(int mapNum) {
    bool transferred;
    if(mapNum == 1){ // if mapNum is 1, use copy assignment from 2 to 1, and remove robots in a wall
        *map1 = *map2;
        for(int i = 0; i < RobosArr.size(); i++){
            if(RobosArr[i]->getMapNum() == mapNum){
                transferred = map1->checkPathForRob(RobosArr[i]->getXloc(), RobosArr[i]->getYloc());
                if (!transferred){ // if not transferred to new map after operator, delete robot
                    delete RobosArr[i];
                    RobosArr.erase(RobosArr.begin() + i);
                }
            }
        }
        RobosArr.shrink_to_fit();// reduce vector size
    }
    else{ // if mapNum is 2
        *map2 = *map1;
        for(int i = 0; i < RobosArr.size(); i++){
            if(RobosArr[i]->getMapNum() == mapNum){
                transferred = map2->checkPathForRob(RobosArr[i]->getXloc(), RobosArr[i]->getYloc());
                if (!transferred){ // if not transferred to new map after operator, delete robot
                    delete RobosArr[i];
                    RobosArr.erase(RobosArr.begin() + i);
                }
            }
        }
        RobosArr.shrink_to_fit();
    }

}

void Game::OPprintGame(int mapNum) {
    if(mapNum == 1){cout << *map1;}
    else cout << *map2;
    for (auto & robot : RobosArr){ // print every robot in the chosen map
        if (robot->getMapNum() == mapNum){
            cout << "Robot: " << robot->getRobNum() << " Map: " << robot->getMapNum() << " GPS: " << robot->getXloc() << "," << robot->getYloc() << endl;
        }
    }
}




