# The Bike Game

This is a simple text-based game implemented in C++. The game allows players to control a bike and navigate through a maze, avoiding obstacles and walls. Below, we provide an overview of the code and its functionality.

## Table of Contents

- [Introduction](#introduction)
- [Gameplay](#gameplay)
- [Code Overview](#code-overview)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Contributions](#contributions)
- [License](#license)

## Introduction

The Bike Game is a console-based game where the player controls a bike avatar and must navigate through a maze. The objective is to reach the end of the maze while avoiding collisions with walls and obstacles. The game features multiple levels, but only the first level is implemented in this code sample.

## Gameplay

In the game, the player can control the bike using the following keys:

- W: Move the bike up.
- S: Move the bike down.
- A: Move the bike left.
- D: Move the bike right.
- X: Force stop and quit the game.

The player's goal is to guide the bike through the maze and avoid crashing into walls. As the bike moves, the player can also jump and move in different directions to navigate the maze successfully. The game includes a menu where players can start a new game, access instructions, or quit.

## Code Overview

The code consists of several key components:

- Initialization: The game initializes various variables, including the game state, player position, and level settings.

- Menu: The `menu()` function displays the main menu and handles player choices to start a new game or access instructions.

- Level Drawing: The `draw_lv1()` function draws the game level, including the maze walls and the player's bike. Only the first level is implemented in this code.

- Input: The `input()` function handles player input, allowing them to control the bike.

- Logic: The `logic()` function processes the game's logic, including updating the bike's position and checking for collisions.

- Bike Drawing: The `draw_bike()` function is responsible for drawing the bike avatar on the screen based on its current position.

## How to Play

1. Compile and run the C++ code provided in your development environment.

2. Use the following keys to control the bike:
   - W: Move up
   - S: Move down
   - A: Move left
   - D: Move right
   - X: Quit the game

3. Navigate the bike through the maze while avoiding collisions with walls.

4. Try to reach the end of the maze to complete the level.

5. You can access the main menu by pressing a key when prompted, allowing you to start a new game, access instructions, or quit the game.

## Installation

To run the code, you will need a C++ development environment. Follow these steps:

1. Clone the repository or download the source code.

2. Compile the code using a C++ compiler, such as g++:

3. Run the compiled executable:


## Contributions

Contributions to this project are welcome. Feel free to open issues, suggest improvements, or submit pull requests.

## License

This project is licensed under the [MIT License](LICENSE).
