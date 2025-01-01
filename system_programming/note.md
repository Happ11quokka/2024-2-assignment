# Dinosaur Game - System Programming Overview

This C++ program utilizes the `ncurses` library to implement a simple terminal-based dinosaur game where the player must avoid obstacles like cactuses. Below is an in-depth look at the key system programming features used in this application.

## Key Features

### 1. **Using ncurses Library**

The `ncurses` library is employed to create a text-based user interface directly in the terminal. This library enables dynamic text and layout management, which is crucial for real-time applications like games.

- **Functions Used**:
  - `initscr()`: Initializes the screen for ncurses.
  - `endwin()`: Restores terminal settings when exiting ncurses mode.
  - `refresh()`: Refreshes the screen to reflect changes.
  - `clear()`: Clears the screen.
  - `move()`: Moves the cursor to a specified position.
  - `printw()`: Prints text at the current cursor position.

### 2. **Asynchronous Key Input Handling**

Key inputs are handled asynchronously to ensure the game remains responsive and fluid.

- **Key Handling Functions**:
  - `_kbhit()`: Non-blocking check for key press, utilizing `select()` to monitor keyboard input.
  - `GetKeyDown()`: Fetches the key if one is pressed, using `getch()` to retrieve the character.

### 3. **Game Physics and Logic**

The game includes physics for jumping and logic for obstacle movement.

- **Jumping and Movement**:

  - Tracks whether the dinosaur is jumping or on the ground.
  - Adjusts the dinosaur's vertical position based on its state.

- **Collision Detection**:
  - Checks if the dinosaur collides with a cactus to trigger a game over.

### 4. **Timing and Speed Control**

The game uses timing functions to control the speed of the gameplay, making it progressively harder.

- **Speed Management**:
  - Utilizes `usleep()` to delay loop iterations, effectively controlling the frame rate and difficulty.

### 5. **Game Termination and Scoring**

End-game scenarios and score management are handled to provide feedback to the player.

- **Score Display and Game Over**:
  - Scores are displayed and updated based on game events.
  - A game over message is shown when the player collides with an obstacle.

## Considerations and Improvements

- **Memory Management**: Ensure that all resources initialized with `ncurses` are properly managed and freed.
- **Error Handling**: Implement robust error handling for system calls and ncurses functions to prevent crashes or undefined behavior.
- **User Interface**: Enhance the user interface to be more engaging and informative.
- **Code Modularity**: Refactor the code to increase modularity, improving readability and maintainability.

## Conclusion

This program demonstrates essential system programming techniques in C++ using the ncurses library, suitable for real-time applications that require direct terminal manipulation and asynchronous input handling.
