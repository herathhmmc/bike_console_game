/***
 *     ____    ____         _                     ______  _______
 *    |_   \  /   _|       / |_                 .' ___  ||_   __ \
 *      |   \/   |   .--. `| |-' .--.   ______ / .'   \_|  | |__) |
 *      | |\  /| | / .'`\ \| | / .'`\ \|______|| |   ____  |  ___/
 *     _| |_\/_| |_| \__. || |,| \__. |        \ `.___]  |_| |_
 *    |_____||_____|'.__.' \__/ '.__.'          `._____.'|_____|
 *                       the-bike-game(text-based)
 */

// include libraries
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <cstring>

// initialize-functions
void setup();                                                        // setup bike variables (x,y)
void menu();                                                         // print menu
void newPlayer();                                                    // get user's name
void draw_lv();                                                      // draw map , bike and enemy
void build_game();                                                   // build the game
void input();                                                        // get users inputs
void logic();                                                        // logic parts of the game
bool draw_bike(int draw_x, int draw_y, int currentX, int currentY);  // check possibility of drawing bike
bool draw_enemy(int draw_x, int draw_y, int currentX, int currentY); // check possibility of drawing enemy bike
bool isGameOver(int enemyX, int enemyY, int x, int y);               // check enemy was hit by bike
void credits();                                                      // show credits

// initialize Variables
bool gameOver = true;
bool quit = false;
int mapX = 50, mapY = 30; // map height and width
int x, y;                 // bike cordinates
int enemyX, enemyY;       // enemy bike cordinates
int wallSize = 3;         // width of the wall
int score = 0;            // player score
std::string playerName;   // players-name

enum eDirect // define directions
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirect dir;

// ASCII-art Collection
std::string bikeObj =
    "\t                      ;~\\.\n"
    "\t        .              _._\\\")\n"
    "\t        I\\___        ,;)))}^\\\n"
    "\t        I `%%^\\%%%%.::q::    `\\.\n"
    "\t      .*//*.    OOO  }}} ))    .\\8^8*.\n"
    "\t   =LIEF()ZIMMERMAN(((((()'    --(*)--\n"
    "\t      \"*oo*\"                   \"*ooo*\"\n";

std::string overIcon =
    "     .d8888b.                                          .d88888b.\n"
    "    d88P  Y88b                                        d88P\" \"Y88b\n"
    "    888    888                                        888     888\n"
    "    888         8888b.  88888b.d88b.   .d88b.         888     888 888  888  .d88b.  888d888\n"
    "    888  88888     \"88b 888 \"888 \"88b d8P  Y8b        888     888 888  888 d8P  Y8b 888P\"\n"
    "    888    888 .d888888 888  888  888 88888888 888888 888     888 Y88  88P 88888888 888\n"
    "    Y88b  d88P 888  888 888  888  888 Y8b.            Y88b. .d88P  Y8bd8P  Y8b.     888\n"
    "     \"Y8888P88 \"Y888888 888  888  888  \"Y8888          \"Y88888P\"    Y88P    \"Y8888  888\n";

std::string lv_1 =
    "\n\n\n\t\tdb      d88888b db    db d88888b db                        db\n"
    "\t\t88      88'     88    88 88'     88                       o88\n"
    "\t\t88      88ooooo Y8    8P 88ooooo 88                        88\n"
    "\t\t88      88~~~~~ `8b  d8' 88~~~~~ 88           C8888D       88\n"
    "\t\t88booo. 88.      `8bd8'  88.     88booo.                   88\n"
    "\t\tY88888P Y88888P    YP    Y88888P Y88888P                   VP\n";

std::string lv_2 =
    "\n\n\n\t\tdb      d88888b db    db d88888b db                       .d888b.\n"
    "\t\t88      88'     88    88 88'     88                       VP  `8D\n"
    "\t\t88      88ooooo Y8    8P 88ooooo 88                          odD'\n"
    "\t\t88      88~~~~~ `8b  d8' 88~~~~~ 88           C8888D       .88'\n"
    "\t\t88booo. 88.      `8bd8'  88.     88booo.                  j88.\n"
    "\t\tY88888P Y88888P    YP    Y88888P Y88888P                  888888D\n";

std::string lv_3 =
    "\n\n\n\t\tdb      d88888b db    db d88888b db                       d8888b.\n"
    "\t\t88      88'     88    88 88'     88                       VP  `8D\n"
    "\t\t88      88ooooo Y8    8P 88ooooo 88                         oooY'\n"
    "\t\t88      88~~~~~ `8b  d8' 88~~~~~ 88           C8888D        ~~~b.\n"
    "\t\t88booo. 88.      `8bd8'  88.     88booo.                  db   8D\n"
    "\t\tY88888P Y88888P    YP    Y88888P Y88888P                  Y8888P'\n";

std::string creditsObj =
    "\n\n\t\t\t _____              _ _ _       \n"
    "\t\t\t/  __ \\            | (_) |      \n"
    "\t\t\t| /  \\/_ __ ___  __| |_| |_ ___ \n"
    "\t\t\t| |   | '__/ _ \\/ _` | | __/ __|\n"
    "\t\t\t| \\__/\\ | |  __/ (_| | | |\\__ \\ \n"
    "\t\t\t \\____/_|  \\___|\\__,_|_|_||___/\n"
    "\t\t\t                                \n";

std::string InstrObj =
    "\n\t  _    _                 _          _____  _             \n"
    "\t | |  | |               | |        |  __ \\| |            \n"
    "\t | |__| | _____      __ | |_ ___   | |__) | | __ _ _   _ \n"
    "\t |  __  |/ _ \\ \\ /\\ / / | __/ _ \\  |  ___/| |/ _` | | | |\n"
    "\t | |  | | (_) \\ V  V /  | || (_) | | |    | | (_| | |_| |\n"
    "\t |_|  |_|\\___/ \\_/\\_/    \\__\\___/  |_|    |_|\\__,_|\\__, |\n"
    "\t                                                    __/ |\n"
    "\t                                                   |___/ \n";

std::string menuIcon =
    "\n\n    888b     d888          888                    .d8888b.  8888888b.\n"
    "    8888b   d8888          888                   d88P  Y88b 888   Y88b\n"
    "    88888b.d88888          888                   888    888 888    888\n"
    "    888Y88888P888  .d88b.  888888 .d88b.         888        888   d88P\n"
    "    888 Y888P 888 d88\"\"88b 888   d88\"\"88b        888  88888 8888888P\"\n"
    "    888  Y8P  888 888  888 888   888  888 888888 888    888 888\n"
    "    888   \"   888 Y88..88P Y88b. Y88..88P        Y88b  d88P 888\n"
    "    888       888  \"Y88P\"   \"Y888 \"Y88P\"          \"Y8888P88 888\n";

std::string playerIdObj =
    "\n\t    ____  __                         ________ \n"
    "\t   / __ \\/ /___ ___  _____  _____   /  _/ __ \\\n"
    "\t  / /_/ / / __ `/ / / / _ \\/ ___/   / // / / /\n"
    "\t / ____/ / /_/ / /_/ /  __/ /     _/ // /_/ / \n"
    "\t/_/   /_/\\__,_/\\__, /\\___/_/     /___/_____/  \n"
    "\t              /____/                          \n";

std::string asciiArt =
    "\n\n\t\t              .-=========-.   \n"
    "\t\t              \\'-=======-'/   \n"
    "\t\t              _|   .=.   |_   \n"
    "\t\t             ((|  {{1}}  |))  \n"
    "\t\t              \\|   /|\\   |/   \n"
    "\t\t               \\__ '`' __/    \n"
    "\t\t                 _`) (`_      \n"
    "\t\t               _/_______\\_    \n"
    "\t\t              /___________\\   \n";

// use-namespace-as std
using namespace std;

// main function
int main()
{
    /*
    Main loop for game

    - loop until user gives command to quit

    */
    while (!quit) // loop untill quit
    {
        setup(); // setup-bike and enemy
        while (gameOver && !quit)
        {
            score = 0;
            wallSize = 3;
            menu(); // print-menu
        }
        if (score >= 0 && score <= 100 && !gameOver)
        {
            system("cls");    // clear the command line outputs
            cout << lv_1;     // print the ASCII-art
            Sleep(1500);      // wait untill 1500 mili-seconds
            system("cls");    // clear the command line outputs
            while (!gameOver) // loop untill gameOver becomes true
            {

                draw_lv();        // draw map,bike and enemy
                build_game();     // build the game (get user inputs , check logic)
                if (score >= 100) // break the loop when score is more-than or equal to 100
                {
                    break;
                }
            }
        }
        if (score >= 100 && score <= 200 && !gameOver)
        {
            system("cls");
            cout << lv_2;
            Sleep(1500);
            system("cls");
            wallSize += 3; // increase wallSize by 3
            while (!gameOver)
            {

                draw_lv();
                build_game();
                if (score >= 200)
                {
                    break;
                }
            }
        }
        if (score >= 200 && score <= 300 && !gameOver)
        {
            system("cls");
            cout << lv_3;
            Sleep(1500);
            system("cls");
            wallSize += 3; // increase wallSize by 3
            while (!gameOver)
            {

                draw_lv();
                build_game();
                Sleep(10);
                if (score >= 300)
                {
                    break;
                }
            }
        }
        if (score >= 300 && !gameOver)
        {
            credits(); // show credits
            gameOver = true;
        }
    }

    if (quit)
    {
        system("cls"); // clear the command line ouputs
        cout << "\n\n\t\t##########################################\n\n\t\tProudly Presented by Programming Group 16.\n\n\t\t##########################################\n\n\n\n";
        cout << "\n\n"
             << bikeObj << "\n\n"; // print ASCII art
        Sleep(1500);               // wait 1500 miliseconds to execute next code
        system("exit");            // close the command line
    }
    return 0;
}

// functions

// setup bike spawn cordinates and enemy spawn cordinates
void setup()
{

    x = mapX / 2; // x is equal to half of the map width
    y = mapY / 2; // y is equal to half of the map height

    enemyX = wallSize + rand() % (mapX - ((2 * wallSize) + 7)); // get random x cordinate for the enemy
    enemyY = 3;                                                 // set y cordinate foe the enemy
}

// print the Main-menu and get users inputs(New-Game )
void menu()
{

    system("cls");    // clear the command line
    cout << menuIcon; // print the ASCII-art
    cout << std::endl;
    cout << "\t\t\t Sri-Lankan-Version" << std::endl;
    cout << std::endl;
    int choise;
    cout << "\t\t1. New Game \n\t\t2. Instructions \n\t\t3. Quit \n\n\t>>";
    cin >> choise;

    if (choise == 1)
    {
        newPlayer(); // get user's name
        gameOver = false;
    }
    else if (choise == 3)
        quit = true;
    else
    {
        system("cls");    // clear the command line
        cout << InstrObj; // print ascii art
        cout << "\n\n\t01. W - for Jump. \n";
        cout << "\t02. S - for Instant Down. \n";
        cout << "\t03. A - for Going Left. \n";
        cout << "\t04. D - for Going Right. \n";
        cout << "\t05. X - for Force Stop and Quit Game; ";

        cout << "\n\nFor quit : 1 \nFor New Game : 2 \n\n  Answer : ";
        cin >> choise; // get user's input to choise
        if (choise == 1)
        {
            quit = true;
        }
        else if (choise == 2)
        {
            newPlayer(); // get user's name
            quit = false;
            gameOver = false;
        }
        else
        {
            std::cout << "Invalid Input : Default Option is chosen quit.";
            quit = true;
        }
    }
}

// get users's name
void newPlayer()
{
    system("cls");       // clear the command line
    cin.ignore();        // clear the input buffer
    cout << playerIdObj; // print an ASCII art
    cout << "\n\n\n\t\tPlease Enter Your Name : ";
    getline(cin, playerName); // store users name inside the char
    Sleep(500);               // wait 500 mili-seconds to execute the code
    if (playerName.empty())   // check the player name is empty or not
    {
        playerName = "Unknown"; // if player name is empty it equals to 'Unkown'
    }
}

// build game(get user inputs,check logics)
void build_game()
{
    gameOver = isGameOver(enemyX, enemyY, x, y); // check the enemy hit the bike
    input();                                     // get users input
    logic();                                     // check logics
    Sleep(10);                                   // wait 10 mili-seconds to draw
    if (gameOver)
    {
        system("cls");   // clear the command line
        cout << "\n\n\n" // print the ASCII art
             << overIcon;
        cout << "\n\n\t\t\t\t\tYour Score : " << score;
        Sleep(2000);
    }
    cout << "\n\n\t\tYour Score : " << score;
    cout << "\n\t\tYour PlayerID : " << playerName;
}

// check the bike hit the enemy
bool isGameOver(int enemyX, int enemyY, int x, int y)
{
    bool condition1 = (enemyX <= x && enemyX + 7 >= x) && (enemyY <= y && enemyY + 4 >= y); //  check whether the bike x and y inside the enemyX and enemyY range
    bool condition2 = (enemyX <= x + 7 && enemyX + 7 >= x + 7) && (enemyY <= y && enemyY + 4 >= y);
    if (condition1 || condition2)
    {
        return true; // return true if the bike hit by the enemy
    }
    return false;
}

void draw_lv()
{
    system("cls"); // clear the command line

    // upper-map-frame
    for (int i = 0; i <= mapX; i++)
        cout << "#";
    cout << std::endl;

    // draw-middle-part
    for (int i = 0; i < mapY; i++) // loop through the height of the map
    {
        for (int j = 0; j < mapX; j++) // loop through the width of the map
        {
            if (j < wallSize) // draw the first line-wall
            {
                cout << "#";
            }
            if (j >= (mapX - wallSize)) // draw the last line wall
            {
                cout << "#";
            }
            if (j == wallSize)
            {
                cout << " ";
            }
            if (draw_bike(x, y, j, i) || draw_enemy(enemyX, enemyY, j, i)) // draw the enemy and bike
            {
                cout << "#";
            }
            else if (j >= wallSize && j < (mapX - wallSize)) // draw the empty space
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // lower-map-frame
    for (int i = 0; i <= mapX; i++)
        cout << "#";
    cout << endl;
}

void input()
{
    if (_kbhit()) // check the user pressed a keyboard button
    {
        char key = _getch(); // Get the key that was pressed
        switch (key)         // switch to specific keyboard function
        {
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
            quit = true;
            break;
        }

        // Clear the input buffer
        while (_kbhit())
        {
            key = _getch();
        }
    }
    else
    {
        dir = STOP; // wehen key is not prssed bike movment will stop
    }
}

void logic()
{
    switch (dir) // logic and bike movement speed controll
    {
    case LEFT:
        x -= 3;
        break;
    case RIGHT:
        x += 3;
        break;
    case UP:
        y -= 2;
        break;
    case DOWN:
        y += 2;
        break;
    }

    if (x >= mapX - (wallSize + 8)) // gameOver when bike hit the wall
        gameOver = true;
    else if (x < wallSize)
        gameOver = true;
    if (y >= mapY)
        y = 0;
    else if (y < 0)
        y = mapY - 1;

    enemyY = enemyY + 2; // moving the enemy downward
    if (enemyY > mapY)
    {
        enemyX = wallSize + rand() % static_cast<int>(mapX - (2 * wallSize + 7)); // spawn enemy in random poisition
        enemyY = 1;                                                               // set enemy enemyY cordinates to beginig of the map
        score = score + 25;                                                       // when enemy passed the map users score wil increase
    }
}

bool draw_bike(int draw_x, int draw_y, int currentX, int currentY)
/* draw the bike
- get x and y cordinates for bike
- and get current cusur position and output true when the bike can drawn
*/
{
    if (currentX <= (draw_x + 7) && currentY <= (draw_y + 4))
    {
        if (currentX == draw_x + 3 && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 1 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 6 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 7 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 2)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 2)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x && currentY == draw_y + 4)
        {
            return true;
        }
        if (currentX == draw_x + 1 && currentY == draw_y + 4)
        {
            return true;
        }
        if (currentX == draw_x + 6 && currentY == draw_y + 4)
        {
            return true;
        }
        if (currentX == draw_x + 7 && currentY == draw_y + 4)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool draw_enemy(int draw_x, int draw_y, int currentX, int currentY)
/*draw the enemy
- get x and y cordinates for enemy
- and get current cusur position and output true when enemy can drawn
*/
{
    if (currentX <= (draw_x + 7) && currentY <= (draw_y + 4))
    {
        if (currentX == draw_x && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x + 1 && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x + 6 && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x + 7 && currentY == draw_y)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 1)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 2)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 2)
        {
            return true;
        }
        if (currentX == draw_x && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 1 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 6 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 7 && currentY == draw_y + 3)
        {
            return true;
        }
        if (currentX == draw_x + 3 && currentY == draw_y + 4)
        {
            return true;
        }
        if (currentX == draw_x + 4 && currentY == draw_y + 4)
        {
            return true;
        }
        return false;
    }
    return false;
}

void credits() // show credits for game
{
    system("cls");
    cout << "\n\n\t" << playerName << "You got highest score for our little game.";
    cout << asciiArt;
    Sleep(1500);
    system("cls");
    cout << creditsObj;
    cout << "\n\n\n\n\t\t\t\tPulindu\n\n\t\t\t\tEnuka\n\n\t\t\t\tKesara\n\n\t\t\t\tUshan";
    Sleep(2000);
}
