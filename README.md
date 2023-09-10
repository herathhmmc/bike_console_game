# The Bike Game 🚴‍♂️

The Bike Game is a simple console-based game written in C++. It's a fun and addictive game where you control a bike and try to avoid obstacles while collecting points.

## Contributors 🤝

- [Ushan Ikshana](https://github.com/im-ushan-ikshana) - Main Developer
- [Kesara Kulathunga](https://github.com/kesarakulathunga) - Contributor
- [Pulindu Wimalaweera](https://github.com/psw101) - Contributor

## Code Explanation 💻

This game is developed in C++ and uses the following libraries:

- `iostream`: The `iostream` library is used for basic input and output operations. It allows the game to display messages and information on the console.

- `conio.h`: The `conio.h` library is used for reading keyboard inputs. It enables the game to respond to key presses and control the bike's movements based on user input.

- `windows.h`: The `windows.h` library is used for console manipulation functions. It helps clear the console screen and provides control over console display.

- `cstdlib`: The `cstdlib` library is used for random number generation. It's used to randomize the position of obstacles and enemies in the game.

- `string` and `cstring`: The `string` and `cstring` libraries are used for string manipulation. They are used to manage player names and display text-based game elements.

The game includes the following key functions:

- `setup()`: Initializes game variables, including the player's health, position, and score.

- `menu()`: Displays the main menu of the game and allows the player to start a new game or quit.

- `newPlayer()`: Prompts the player to enter their name and sets a default name if none is provided.

- `draw_game()`: Handles the main game loop, including drawing the game screen, taking player input, and updating the game state.

- `isGameOver()`: Checks if the game is over by comparing the positions of the player and the enemy.

- `draw_lv()`: Draws the game's levels, including walls, the player's bike, and enemies.

- `input()`: Handles keyboard input for controlling the bike.

- `logic()`: Implements the game's logic, including player movement and enemy spawning.

- `draw_bike()` and `draw_enemy()`: Functions to draw the player's bike and enemies on the game screen.

- `credits()`: Displays a credits screen when the player achieves a high score.

## License 📜

This project is licensed under the GNU General Public License (GPL). See the [LICENSE](LICENSE) file for details.
