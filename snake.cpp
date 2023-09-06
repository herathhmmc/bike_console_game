#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <conio.h>
#include <windows.h>

//variables
bool gameOver;
const int height = 30;
const int width = 30;
int x , y , fruit_x , fruit_y,score;
int tailX[100],tailY[100];
int nTail=0;
enum eDirect{STOP = 0 , LEFT , RIGHT , UP , DOWN};
eDirect dir;

void setup();
void draw();
void input();
void logic();

//main code
int main(){
    setup();

    while(!gameOver){
        draw();
        input();
        logic();
        Sleep(10); //sleep(10)
    }

    return 0;
}


//function explanantions


void setup(){
    /*
        @return void;
        - setup snake position and fruit position
        - setup score to zero
    
    */
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}


void draw(){

    system("cls");

    std::cout<<" ";
    for(int i = 0; i<width; i++)
        std::cout<<"#";
    std::cout<<std::endl;

    for(int i = 0; i<height; i++){
        for(int j = 0; j<width;j++){
            if(j==0){
                std::cout<<"#";
            }
            if(i == y && j == x){
                std::cout<<"@";
            }
            else if(i == fruit_y && j == fruit_x){
                std::cout<<"F";
            }
            else{
                bool tail = false;
                for(int k = 0; k< nTail;k++){
                    if(tailX[k] == j && tailY[k] == i){
                        tail = true;
                        std::cout<<"o";
                    }
                }
                if(!tail){
                    std::cout<<" ";
                }
            }
            if(j==width-1){
                std::cout<<"#";
            }
        }
        std::cout<<std::endl;
    }

    std::cout<<" ";
    for(int i = 0; i<width; i++)
        std::cout<<"#";
    std::cout<<std::endl;

    std::cout<<"Your Score : "<<score;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }

}

void logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X , prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i=1;i<nTail;i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    // if(x<0 || x > width || y<0 || y> height){
    //     gameOver = true;
    // }

    if(x >= width)  x=0; else if(x < 0) x = width - 1;
    if(y >= height)  y=0; else if(y < 0) y = height - 1;

    for(int i=0; i<nTail; i++){
        if(tailX[i] == x && tailY[i] == y){
            gameOver = true;
        }
    }

    if(x == fruit_x && y == fruit_y){
        nTail++;
        score += 10;
        fruit_x = rand() % width;
        fruit_y = rand() % height;
    }
}
