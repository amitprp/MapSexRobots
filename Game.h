#ifndef MAPSSEXROBOTS_GAME_H
#define MAPSSEXROBOTS_GAME_H
#include "vector"
#include "Robot.h"
#include "Map.h"
/**
 * Game module
 * Game modules manages all of options possible. Controls maps and robots.
 * This module holds 2 maps with known walls and paths, it can add, delete and move robots on the map.
 * It also expands all operators done with maps and involves the robots within.
 */
class Game {
private:
    vector <Robot*> RobosArr;
    Map *map1;
    Map *map2;
    friend Map;
public:
    // Game Constructor.
    Game();
    // Destructor
    ~Game();
    /* Adds a robot to certain number in received coordinates
     * Receives a map number to add the robot to
     * Receives coordinates to the added robot
     */
    void AddRobot(int mapNumber, int x, int y);
    /* Deletes robot from memory and all possible places saved
     * Receives number of the robot to delete
     */
    void DeleteRobot(int robotNum) ;
    /* Moves robot on map
     * Receives number of the robot to move
     * Receives direction to move the robot to
     */
    void MoveRobot(int robotNum, char dir);
    /* Manages operator + on maps and robots
     * concatenates 2 maps, and transfers the robots to the receiving map.
     * the created map is not saved nor returned
     */
    void OPplusMap();
    /* Manages operator += on maps and robots
     * Receives map number to override
     */
    void OPeqplusMap(int mapNum);
    /* manages operator = copy assignment on maps and robots
     * Receives map number to override
     */
    void OPcopyMap(int mapNum);
    /* Manages bool operator ==
     * prints TRUE if equal and FALSE if not
     */
    void OPeqMap();
    /* manages operator <<
     * Receives a map number to operate on
     * Prints map and all robots in the map given
     */
    void OPprintGame(int mapNum);
};


#endif //MAPSSEXROBOTS_GAME_H
