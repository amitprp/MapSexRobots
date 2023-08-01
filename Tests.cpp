#include <iostream>
#include "Robot.h"
#include "Map.h"
#include "Game.h"
/*
int Robot::next_index = 1;
int main() {
    // Robo Test
    cout<<"Robot 1 created"<<endl;
    auto *robo_test = new Robot(2,3,1);
    cout<<"Robot 2 created"<<endl;
    auto *robo_test2 = new Robot(2, 3, 2);
    cout<<"Robot 1 goes up 1"<<endl;
    robo_test->changeLocation('U');
    cout<<"Robot 2 goes down 1"<<endl;
    robo_test2->changeLocation('D');
    cout<<"Robot 3 created"<<endl;
    auto *robo_test3 = new Robot(3, 6, 2);
    delete robo_test;
    delete robo_test2;
    delete robo_test3;
    // Map Test


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
    Map *newMap1 = new Map(mapArray1);
    Map *newMap2 = new Map(mapArray2);
    *newMap1 == *newMap2;
    cout<<"first map:"<<endl;
    newMap1->printMap();
    cout<<"second map:"<<endl;
    newMap2->printMap();cout<<endl;
    cout<<"operator +:"<<endl;
    Map map_test = *newMap1+*newMap2;
    *newMap1 += *newMap2;
    *newMap1 == map_test;
    cout<<"first map after operator +=:"<<endl;
    newMap1->printMap();
    *newMap1 = *newMap2;
    cout<<"second map:"<<endl;
    newMap2->printMap();cout<<endl;
    cout<<"first map after operator =:"<<endl;
    cout<<*newMap1<<endl;
    delete newMap1;
    delete newMap2;

    //Game Test
    cout<<"GAME TEST"<<endl;
    Game *newGame = new Game();
    newGame->AddRobot(1, 3, 4);
    newGame->AddRobot(1, 2, 4);
    newGame->MoveRobot(4, 'R');
    newGame->MoveRobot(4,'L');
    newGame->MoveRobot(4,'L');
    newGame->MoveRobot(4,'L');
    newGame->DeleteRobot(4);
    delete newGame;

}
//*/