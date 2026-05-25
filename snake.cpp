//Oled 1306  128x64 - 32x16 16 collumns, 32 rows



#include<iostream>
#include<time.h>
#include<stdllib.h>


enum Direction {
    Up,
    Down,
    Left,
    Right
};

class GameLogic {
    private:
    const int ROWS = 16;
    const int COLLUMNS = 32;
    bool SnakeState[512];
    int apple;
    public:

    int calculateCollumn(int position){
    return position%COLLUMNS
    }

    int calculateRows(int position){
    return (position+1)%COLLUMNS == 0 ? ((position+1)/COLLUMNS - 1)  : ((position+1)/COLLUMNS)
    }
    


};