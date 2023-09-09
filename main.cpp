

//  d8888b.  .d88b.  db    db d8b   db  .o88b. d88888b
//  88  `8D .8P  Y8. 88    88 888o  88 d8P  Y8 88'
//  88oooY' 88    88 88    88 88V8o 88 8P      88ooooo
//  88~~~b. 88    88 88    88 88 V8o88 8b      88~~~~~
//  88   8D `8b  d8' 88b  d88 88  V888 Y8b  d8 88.
//  Y8888P'  `Y88P'  ~Y8888P' VP   V8P  `Y88P' Y88888P
//
//                    The-Bike-Game

// include-additional libraries

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <cstring>

// init-other-functions

void setup();
void menu();
void draw_lv();
void draw_game();
void input();
void logic();
bool draw_bike(int draw_x, int draw_y, int currentX, int currentY);
bool draw_enemy(int draw_x, int draw_y, int currentX, int currentY);
bool isGameOver(int enemyX, int enemyY, int x, int y);
void credits();

// init-Variables
bool gameOver = true;
bool quit = false;
bool bikeCord = false;
int mapX = 60, mapY = 30;
int bike_health = 100;
int x, y;
int enemyX, enemyY;
int levelPass = 1;
int wallSize = 3;
int score = 0;
std::string playerName;
enum eDirect
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirect dir;
int spawnX = 5;
int spawnY = mapY / 2;

// Game-objects-enemies-and-traps;
std::string ballObj = "@";
std::string spidObj =
    "  / _ \\\n"
    "\\_\\(_)/_/\n"
    " _//\"\\\\_ \n"
    "  /   \\  \n";

std::string trapObj = "/\\";

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
    "    888b     d888          888                    .d8888b.  8888888b.\n"
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

// the-main-method

int main()
{

    while (!quit)
    {
        setup();
        while (gameOver && !quit)
        {
            score = 0;
            wallSize = 3;
            menu();
        }
        if (score >= 0 && score <= 100 && !gameOver)
        {
            system("cls");
            std::cout << lv_1;
            Sleep(1500);
            system("cls");
            while (!gameOver)
            {

                draw_lv();
                draw_game();
                if (score >= 100)
                {
                    break;
                }
            }
        }
        if (score >= 100 && score <= 200 && !gameOver)
        {
            system("cls");
            std::cout << lv_2;
            Sleep(1500);
            system("cls");
            wallSize += 3;
            while (!gameOver)
            {

                draw_lv();
                draw_game();
                if (score >= 200)
                {
                    break;
                }
            }
        }
        if (score >= 200 && score <= 300 && !gameOver)
        {
            system("cls");
            std::cout << lv_3;
            Sleep(1500);
            system("cls");
            wallSize += 3;
            while (!gameOver)
            {

                draw_lv();
                draw_game();
                Sleep(10);
                if (score >= 300)
                {
                    break;
                }
            }
        }
        if (score >= 300 && !gameOver)
        {
            credits();
            gameOver = true;
        }
    }

    if (quit)
    {
        system("cls");
        std::cout << "\n\n\t\t##########################################\n\n\t\tProudly Presented by Programming Group 16.\n\n\t\t##########################################\n\n\n\n";
        std::cout << "\n\n"
                  << bikeObj << "\n\n";
        Sleep(1500);
        system("exit");
    }

    return 0;
}

// functions

void setup()
{
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
    x = mapX / 2;
    y = mapY / 2;

    enemyX = wallSize + rand() % static_cast<int>(mapX - ((2 * wallSize) + 2));
    enemyY = 3;
}

void menu()
{
    /*
        @return void;

        - main-menu-of-the-game
    */

    system("cls");
    std::cout << menuIcon;
    std::cout << std::endl;
    std::cout << "\t\t\t Sri-Lankan-Version" << std::endl;
    std::cout << std::endl;
    int choise;
    std::cout << "\t\t1. New Game \n\t\t2. Instructions \n\t\t3. Quit \n\n\t>>";
    std::cin >> choise;

    if (choise == 1)
    {
        system("cls");
        std::cin.ignore();
        std::cout << playerIdObj;
        std::cout << "\n\n\n\t\tPlease Enter Your Name : ";
        getline(std::cin, playerName);
        Sleep(1000);
        if (playerName.empty())
        {
            playerName = "Unknown";
        }
        gameOver = false;
    }
    else if (choise == 3)
        quit = true;
    else
    {
        system("cls");
        std::cout << InstrObj;
        std::cout << "\n\n\t01. W - for Jump. \n";
        std::cout << "\t02. S - for Instant Down. \n";
        std::cout << "\t03. A - for Going Left. \n";
        std::cout << "\t04. D - for Going Right. \n";
        std::cout << "\t05. X - for Force Stop and Quit Game; ";

        std::cout << "\n\nFor quit : 1 \nFor New Game : 2 \n\n  Answer : ";
        std::cin >> choise;
        if (choise == 1)
        {
            quit = true;
        }
        else if (choise == 2)
        {
            quit = false;
            gameOver = false;
        }
        else
        {
            std::cout << "Invalid Input : Default Opstion is choosen quit.";
            quit = true;
        }
    }
}

void draw_game()
{
    gameOver = isGameOver(enemyX, enemyY, x, y);
    input();
    logic();
    Sleep(10);
    if (gameOver)
    {
        system("cls");
        std::cout << "\n\n\n"
                  << overIcon;
        std::cout << "\n\n\t\t\t\t\tYour Score : " << score;
        Sleep(2000);
    }
    std::cout << "\n\n\t\t\tYour Score : " << score;
    std::cout << "\n\t\t\tYour PlayerID : " << playerName;
}

bool isGameOver(int enemyX, int enemyY, int x, int y)
{
    bool condition1 = (enemyX <= x && enemyX + 7 >= x) && (enemyY <= y && enemyY + 4 >= y);
    bool condition2 = (enemyX <= x + 7 && enemyX + 7 >= x + 7) && (enemyY <= y && enemyY + 4 >= y);
    if (condition1 || condition2)
    {
        return true;
    }
    return false;
}

void draw_lv()
{
    system("cls");

    // upper-map-frame
    for (int i = 0; i <= mapX; i++)
        std::cout << "#";
    std::cout << std::endl;

    // draw-middle-part
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (j < wallSize)
            {
                std::cout << "#";
            }
            if (j >= (mapX - wallSize))
            {
                std::cout << "#";
            }
            if (j == wallSize)
            {
                std::cout << " ";
            }
            if (draw_bike(x, y, j, i) || draw_enemy(enemyX, enemyY, j, i))
            {
                std::cout << "#";
            }
            else if (j >= wallSize && j < (mapX - wallSize))
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // lower-map-frame
    for (int i = 0; i <= mapX; i++)
        std::cout << "#";
    std::cout << std::endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
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
    }
}

void logic()
{
    switch (dir)
    {
    case LEFT:
        x = x - 3;
        break;
    case RIGHT:
        x = x + 3;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= mapX - (wallSize + 8))
        gameOver = true;
    else if (x < wallSize)
        gameOver = true;
    if (y >= mapY)
        y = 0;
    else if (y < 0)
        y = mapY - 1;

    enemyY = enemyY + 2;
    if (enemyY > mapY)
    {
        enemyX = wallSize + rand() % static_cast<int>(mapX - (wallSize + 8));
        enemyY = 1;
        score = score + 25;
    }
}

bool draw_bike(int draw_x, int draw_y, int currentX, int currentY)
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

void credits()
{
    system("cls");
    std::cout << creditsObj;
    std::cout << "\n\n\n\n\t\t\t\t\tPulindu\n\n\t\t\t\t\tEnuka\n\n\t\t\t\t\tKesara\n\n\t\t\t\t\tUshan";
    Sleep(2000);
}
