//Oled 1306  128x64 - 32x16 16 collumns, 32 rows
/*
00001000
00001110
00000010
32<-->
    ^
16  |
    |
    ^
*/


#include<iostream>
#include<time.h>
#include<stdllib.h>
#include <queue>

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
    queue<bool> snakeState  ;
    int apple;

    public:

    int calculateCollumn(int position){
    return position%COLLUMNS
    }

    int calculateRows(int position){
    return (position+1)%COLLUMNS == 0 ? ((position+1)/COLLUMNS - 1)  : ((position+1)/COLLUMNS)
    }

    int calculateIndexOfCoordinates(int row, int collumn){
        return row == 0 ? collumn : ((row-1)*COLLUMNS + row)
    }

    int move(Direction moveDirrection)
    {
        switch (moveDirrection){
            case Left: {

            }
        }
        
    }


    const bool* getSnakeState()
    {
        return snakeState;
    }

    const int getApple()
    {
        return apple;
    }    



};