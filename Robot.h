#ifndef MAPSSEXROBOTS_ROBOT_H
#define MAPSSEXROBOTS_ROBOT_H
#include <iostream>
#include <cstring>
using namespace std;
/**
 * Robot Module
 * Controls all of robots actions, constructing, destructing and moving. Provides getters for other modules
 * Used by game module
 */
class Robot{
private:
    int location_x; // column loc
    int location_y; // row loc
    int rob_num = 0; // index of robot
    static int next_index; // static index for robot number
    int map_num; // number of map robot is located

public:
    /* constructor, only construct on an existing map
     * Receives coordinates as (x,y)
     * Receives number of map that is constructed in
     * */
    Robot(int x, int y, int NumOfMap);
    // default destructor
    ~Robot();
    // return robot number
    int getRobNum() const;
    // return map number
    int getMapNum() const;
    // return x coordinate
    int getXloc() const;
    // return  coordinate
    int getYloc() const;
    /* Moves the robot in the map according to direction char input
     * if out of bounds coordinates are (-1,-1),map number assigned to be 0 and no further communication is available
     * */
    void changeLocation(char move_dir);
    // prints robot according to template
    void printRobo() const;
};
#endif //MAPSSEXROBOTS_ROBOT_H
