#include "Map.h"
// Constructor, deep copy each value to matrix in map
Map::Map(int MapInput[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            this->map[i][j] = MapInput[i][j];
        }
    }
}
// Operator+, concatenates maps
Map Map::operator+(const Map& m_Map) {
    Map newMap = Map(m_Map);
    for (int j = 6; j > -1; j--){
        for (int i = 0; i < 7; i++){
            if (map[i][j] == 1 || m_Map.map[i][j] == 1){//Or logic, if either map1/m_map[i][j]=1, newMap[i][j]=1
                newMap.map[i][j] = 1;
            }
            else newMap.map[i][j] = 0;
        }
    }
    // prints map in the end
    newMap.printMap();
    return newMap;
}
// template of printing map, helpful for methods and operator<<
void Map::printMap() {
    for (int j = 6; j > -1; j--){
        cout << "[";
        for (int i = 0; i < 6; i++){
            cout << map[i][j] << " ";
        }
        cout << map[6][j];
        cout << "]" <<endl;
    }
    cout<<endl;
}
// Copy assignment, deep copy each value
Map &Map::operator=(const Map &m_Map) {
    if (this != &m_Map) {
        for (int j = 6; j > -1; j--){
            for (int i = 0; i < 7; i++){
                this->map[i][j] = m_Map.map[i][j]; //deep copy integers
            }
        }
    }
    return *this;
}

// concatenate map to self object
Map &Map::operator+=(const Map &m_Map) {
    for (int j = 6; j > -1; j--){
        for (int i = 0; i < 7; i++){
            this->map[i][j] = this->map[i][j] + m_Map.map[i][j];// summing values in maps
            if (this->map[i][j] != 0){// while summing could be bigger than 1, get to 2
                this->map[i][j] = 1; //reset to 1
            }
        }
    }
    return *this;
}
// Equal checking operator
bool Map::operator==(const Map& m_Map) const {
    for (int j = 6; j > -1; j--){
        for (int i = 0; i < 7; i++){
            if(this->map[i][j] == m_Map.map[i][j]){ // check each value in map
                continue;
            } else { //  if even one is not the same then false
                cout<<"FALSE"<<endl;
                return false;
            }
        }
    }
    cout<<"TRUE"<<endl;
    return true;
}
// print operator in cout
ostream &operator<<(ostream &out, Map m_Map) {
   m_Map.printMap();
   return out;
}
// check if standing on path '0' or wall '1'
bool Map::checkPathForRob(int x, int y) {

    if(map[x][y] == 0 or y > 6 or y < 0 or x > 6 or x < 0){
        return true;
    }
    return false;
}
//Default destructor
Map::~Map() = default;
