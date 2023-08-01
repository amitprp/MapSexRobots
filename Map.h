#ifndef MAPSSEXROBOTS_MAP_H
#define MAPSSEXROBOTS_MAP_H

#include "Robot.h"
/**
 * Map Module
 * Map is represented by a matrix of ints, '0' and '1'.
 * '0' represents a path, while '1' represents a wall.
 * Map is used by game module and has robots assigned to it.
 */
class Map{
private:
    int map[7][7]{}; // matrix of map


public:
    /* Map constructor, needs a matrix to initialize
     * Map[7][7] is an int matrix with '0's and '1's
     * */
    explicit Map(int map[7][7]);
    // Destructor
    ~Map();
    /* checks if a robot is on a path '0' or a wall '1'.
     * Received as inputs coordinates of a specific robot.
     * returns true if on a path and false if on a wall
     * */
    bool checkPathForRob(int x, int y);
    /* concatenates maps, with or logic between walls(if either map has 1 on [i][j], new map has 1 on [i][j])
     * receives a map as a const ref to avoid copies
     */
    Map operator+(const Map& m_Map);
    /* Copy assignment operator
     * receives a map as a const ref to avoid copies
     */
    Map& operator=(const Map& m_Map);
    /* concatenates another map to self using operator + logic
     * receives a map as a const ref to avoid copies
     */
    Map& operator+=(const Map& m_Map);
    /* checks if maps are equal by checking every cell in matrix and equalizing values, returns bool
     * receives a map as a const ref to avoid copies
     */
    bool operator==(const Map& m_Map) const;
    // print operator for cout
    friend ostream& operator<<(ostream& out, Map m_Map);
    // map print template
    void printMap();
};
#endif //MAPSSEXROBOTS_MAP_H
