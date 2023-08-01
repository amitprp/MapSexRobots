#include "Robot.h"
int Robot::next_index = 1; // initialize static index
Robot::Robot(int x, int y, int mapNum) {
    this->location_x = x;
    this->location_y = y;
    this->map_num = mapNum;
    this->rob_num = next_index++;
    this->printRobo();
}
Robot::~Robot() = default;

void Robot::changeLocation(const char move_dir){
    if(move_dir == 'U'){ // Move up one step
        this->location_y++;
    }
    if(move_dir == 'D'){ // Move down one step
        this->location_y--;
    }
    if(move_dir == 'L'){ // Move left one step
        this->location_x--;
    }
    if(move_dir == 'R'){ // Move right one step
        this->location_x++;
    }
    if(location_y > 6 or location_y < 0 or location_x > 6 or location_x < 0){
        location_y = -1; // if out of map, indices are (-1,-1) and no map number
        location_x = -1;
        map_num = 0;
    }
    else cout << "Robot: " << this->rob_num << " Map: " << this->map_num << " GPS: " << this->location_x << "," << this->location_y << endl;
}
// Getters documentation in header
void Robot::printRobo() const{
    //template printing
    cout << "New Robot: " << this->rob_num << "  Map: " << this->map_num << "  GPS: " << this->location_x << "," << this->location_y << endl;
}

int Robot::getRobNum() const {
    return this->rob_num;
}

int Robot::getMapNum() const {
    return map_num;
}

int Robot::getXloc() const {
    return location_x;
}
int Robot::getYloc() const {
    return location_y;
}

