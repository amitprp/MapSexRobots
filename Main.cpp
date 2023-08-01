///*
#include "Game.h"
int main(){
    Game *MainGame = new Game();
    char input[300];
    bool run = true;
    while(run) {
        cout << "Robot Control Menu \n"
        "1. Add Robot \n"
        "2. Delete Robot \n"
        "3. Move Robot \n"
        "4. Operator + \n"
        "5. Operator += \n"
        "6. Operator = \n"
        "7. Operator == \n"
        "8. Operator << \n"
        "9. Quit \n"
        "Input your option: \n";
        cin >> input;
        switch (*input) {
            case '1': // Add a Robot
                cout << "Enter MAP number: " << endl;
                int mapNum, x, y;
                cin >> mapNum;
                cout << "Enter Coordinates (X,Y): " << endl;
                cin >> x >> y;
                MainGame->AddRobot(mapNum, x, y);
                break;
            case '2': // Delete a Robot
                cout << "Enter Robot number: " << endl;
                int robNum;
                cin >> robNum;
                MainGame->DeleteRobot(robNum);
                break;
            case '3': // Move robot
                cout << "Enter Robot number: " << endl;
                cin >> robNum;
                cout<<"Enter Direction: "<<endl;
                char dir;
                cin >> dir;
                MainGame->MoveRobot(robNum, dir);
                break;
            case '4': // Operator +
                MainGame->OPplusMap();
                break;
            case '5': // Operator +=
                cout << "Override MAP number: "<<endl;
                cin >> mapNum;
                if (mapNum == 1 or mapNum == 2){
                    MainGame->OPeqplusMap(mapNum);
                }
                else{
                    cout<<"Invalid MAP number"<<endl;
                }
                break;
            case '6':
                cout << "Override MAP number: "<<endl;
                cin >> mapNum;
                if (mapNum == 1 or mapNum == 2){
                    MainGame->OPcopyMap(mapNum);
                }
                else{
                    cout<<"Invalid MAP number"<<endl;
                }
                break;
            case '7': // Operator ==
                MainGame->OPeqMap();
                break;
            case '8': // Operator <<
                cout << "Please enter MAP number: " << endl;
                cin >> mapNum;
                if (mapNum == 1 or mapNum == 2){
                    MainGame->OPprintGame(mapNum);
                }
                else{
                    cout << "Invalid MAP number" << endl;
                }
                break;
            case '9':
                run = false;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;

        }
    }
    delete MainGame;
}
//*/