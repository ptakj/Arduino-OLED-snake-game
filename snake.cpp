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

#include <cstdint>
#include<iostream>
#include<time.h>
#include <vector>
#include <algorithm>

enum Direction : uint8_t{
    Up,
    Down,
    Left,
    Right
};

class GameLogic {
    private:
    Direction currentDirection = Direction.Right;
    const uint8_t ROWS = 16;
    const uint8_t COLLUMNS = 32;
    int snakeState[512] = {-1}; // from 0 to 512, from tail to head, -1 equals empty
    uint8_t score = 1;
    int apple;

    public:

    void setup (){
        srand(time(NULL));
        snakeState[calculateIndexOfCoordinates(8,15)];
    }

    void generateApple(){
        int tmp = rand()%512; 
        while(snakeState[tmp] != -1){
            tmp = rand()%512; 
        }
        apple = tmp;
    }


    //width
    int calculateCollumn(int position){
    return position%COLLUMNS;
    }


    //height
    int calculateRows(int position){
    return (position+1)%COLLUMNS == 0 ? ((position+1)/COLLUMNS - 1)  : ((position+1)/COLLUMNS);
    }


    int getHeadPosition(){
        for (int i=0; i<512; i++){
            if(snakeState[i] == score)
                return i;
        }
        
        return -1;
    }

    int calculateIndexOfCoordinates(int row, int collumn){
        return row == 0 ? collumn : ((row-1)*COLLUMNS + row);
    }

    int normaliseHeight(int height){
        switch (height) {
            case 16:
                return 0;
            case -1: 
                return 15;
            default:
                return height;
        }
    }

    int normaliseWidth(int width){
        switch(width) {
            case -1:
                return 32;
            case 32:
                return 0;
            default:
                return width;
        }
    }

    int move(Direction moveDirrection, int position)
    {
        int width = calculateCollumn(position);
        int height = calculateRows(position);

        switch (moveDirrection){
            case Left:
                width--;
                break;        
            case Right:
                width++;
                break;
            case Up:
                height++;
                break;
            case Down:
                height --;
                break;
        }
        
        height = normaliseHeight(height);
        width = normaliseWidth(width);
        return calculateIndexOfCoordinates(width, height);
    }


    const int* getSnakeState()
    {
        return snakeState;
    }

    const int getApple()
    {
        return apple;
    }    



};

int main()
{
    std::cout<<((-65)%64);
    return 0;
}