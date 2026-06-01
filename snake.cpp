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

std::string getDirectionName(Direction d) {
    switch (d) {
        case Up:    return "Up";
        case Down:  return "Down";
        case Left:  return "Left";
        case Right: return "Right";
        default:    return "Unknown";
    }
}

class GameLogic {
    private:
    Direction currentDirection = Direction::Right;
    const uint8_t ROWS = 16;
    const uint8_t COLLUMNS = 32;
    int snakeState[512] = {-1}; // from 0 to 512, from tail to head, -1 equals empty
    int score = 0;
    int apple = 15;

    public:

    void setup (){
        srand(time(NULL));
        for(int i = 0; i < 512; i++) snakeState[i] = -1;
        snakeState[calculateIndexOfCoordinates(8,15)] = 0;
        generateApple();
    }

    void generateApple(){   
        int tmp = (rand()%512); 
        while(snakeState[tmp] != -1){
            tmp = (rand()%512); 
        }
        apple = tmp;
    }


    //width
    int calculateCollumn(int position){
        return position%COLLUMNS;
    }


    //height
    int calculateRows(int position){
        return position / COLLUMNS;    }


    int getHeadPosition(){
        for (int i=0; i<512; i++){
            if(snakeState[i] == score)
                return i;
        }
        
        return -1;
    }

    int calculateIndexOfCoordinates(int row, int collumn){
        return (row * COLLUMNS) + collumn;
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
        return calculateIndexOfCoordinates(height, width);
    }

    void changeSnakePosition(int nextPosition){
        for (int i=0; i<512; i++){
            if (snakeState[i] != -1){
                snakeState[i]--;
            }
        }
        snakeState[nextPosition] = score;
    }

    void changeSnakePositionAfterEatingApple(){
        score++;
        snakeState[apple] = score;
        generateApple();
    }

    const int* getSnakeState()
    {
        return snakeState;
    }

    const int getApple()
    {
        return apple;
    }    


    void printBoart()
    {
        std::cout << "\n\n\n\n\n";
        for (int height=0; height<16; height++){
            for(int width=0; width<32; width++){
            std::cout<<char(snakeState[calculateIndexOfCoordinates(height, width)] + int(' ') + 1);    
            }
            std::cout<<"\n";
        }
    }


    void turn(Direction moveDirrection){
        int position = getHeadPosition();
        int nextPosition = move(moveDirrection, position);
        if (snakeState[nextPosition] >= 0 ){
            score = 0;
            for (int i=0; i<512; i++){
                snakeState[i] = -1;
            }
            return;
        }

        if( nextPosition == apple){
            changeSnakePositionAfterEatingApple();

        }
        else
            changeSnakePosition(nextPosition);        
    }

    Direction randDirection(){
        int rnd = rand()%4;
        switch (rnd){
            //case 0:
            //    return Direction::Up;
            case 1:
                return Direction::Down;
            case 2:
                return Direction::Left;
            default:
                return Direction::Right;
        }
    }

    void simGame()
    {
        while(1){
        Direction d = randDirection();
        std::cout<<apple<<"\n"<<score<<"\n";
        std::cout<<getDirectionName(d);
         
        turn(d);
        //printBoart();
        }
    }
};

class MicroControllerLogic{
    private:
    GameLogic CurrentGame;
    Direction ReadPressedDirection(){};
    void GameStateHandler(){};
    void ScoreDisplayHandle(){};
    void GameDisplayHandler(){};
    void MainLoopHandler(){};
    public:
    //TODO! OLED to dislay gameboard, 7 segment display to display current score, 

};


int main()
{

    GameLogic g;
    g.setup();
    g.simGame();
    return 0;
}