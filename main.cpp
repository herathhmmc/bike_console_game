

//  d8888b.  .d88b.  db    db d8b   db  .o88b. d88888b 
//  88  `8D .8P  Y8. 88    88 888o  88 d8P  Y8 88'     
//  88oooY' 88    88 88    88 88V8o 88 8P      88ooooo 
//  88~~~b. 88    88 88    88 88 V8o88 8b      88~~~~~ 
//  88   8D `8b  d8' 88b  d88 88  V888 Y8b  d8 88.     
//  Y8888P'  `Y88P'  ~Y8888P' VP   V8P  `Y88P' Y88888P 
//                                                     
//                    The-bounce-game                                



//include-additional libraries

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib> 
#include <string>



//init-other-functions

void setup();
void menu();
void draw();
void input();
void logic();


//init-Variables
bool gameOver = true;
bool quit = false;
int mapX = 60,mapY = 25;
int x,y,health;
enum eDirect{STOP = 0 , LEFT , RIGHT , UP , DOWN};
eDirect dir;



//the-main-method
int main(){

    setup();
    while(gameOver && !quit){
        menu();
    }
    while(!gameOver){
        draw();
        input();
        logic();
        Sleep(16);
    }

    return 0;
}



//functions

void setup(){
    /*
        @return void
        - health
        - postiton 
        - points
        - stars (+2 points)
        - animated-objects
        - objects
        - traps (-100 health)
    */

   int health = 100;
   
}

void menu(){
    /*
        @return void;

        - main-menu-of-the-game
    */
   
   std::string menuIcon =
    "\n\n\n  d8888b.  .d88b.  db    db d8b   db  .o88b. d88888b \n"
    "  88  `8D .8P  Y8. 88    88 888o  88 d8P  Y8 88'     \n"
    "  88oooY' 88    88 88    88 88V8o 88 8P      88ooooo \n"
    "  88~~~b. 88    88 88    88 88 V8o88 8b      88~~~~~ \n"
    "  88   8D `8b  d8' 88b  d88 88  V888 Y8b  d8 88.     \n"
    "  Y8888P'  `Y88P'   Y8888P' VP   V8P  `Y88P' Y88888P \n"
    "                                                     \n"
    "                    The-bounce-game                  \n";

        

    std::string overIcon =
        "  dP\"\"b8    db    8b    d8 888888      dP\"Yb  Yb    dP 888888 88\"\"Yb \n"
        " dP   `\"   dPYb   88b  d88 88__       dP   Yb  Yb  dP  88__   88__dP \n"
        " Yb  \"88  dP__Yb  88YbdP88 88\"\"       Yb   dP   YbdP   88\"\"   88\"Yb  \n"
        "  YboodP dP\"\"\"\"Yb 88 YY 88 888888      YbodP     YP    888888 88  Yb \n";

    system("cls");
    std::cout<<menuIcon;
    std::cout<<std::endl;
    std::cout<<std::endl;
    int choise;
    std::cout<<"1. New Game \n2. Instructions \n3.Quit \n\n";
    std::cin>>choise;

    if(choise == 1)
        gameOver = false;
    else if (choise == 3)
        quit = true;
    else{
        std::cout<<"\t----Instructions----\n";
        std::cout<<"\t01. W - for Jump. \n";
        std::cout<<"\t02. S - for Instant Down. \n";
        std::cout<<"\t01. A - for Going Left. \n";
        std::cout<<"\t01. D - for Going Right. \n";
    }


}

void draw(){
    /*
        @return void
        - draw objects,map,stars and traps
        - draw bounce
    */

   system("cls");

    //upper-map-frame
   std::cout<<" ";
    for(int i = 0; i< mapX; i++)
        std::cout<<"#";
    std::cout<<std::endl;

    //draw-middle-part
    for(int i=0; i < mapY; i++){
        for(int j=0; j <= mapX; j++){
            if(j==0){
                std::cout<<"#";
            }
            if(j == mapX){
                std::cout<<"#";
            }
            else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }

    //lower-map-frame
    std::cout<<" ";
    for(int i = 0; i< mapX; i++)
        std::cout<<"#";
    std::cout<<std::endl;

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

}
