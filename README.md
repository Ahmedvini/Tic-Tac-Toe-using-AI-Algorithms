# Tic-Tac-Toe-using-AI-Algorithms

This project is a Tic Tac Toe game with a GUI built using GTK in C, featuring multiple AI algorithms for the computer’s moves. Users can play against different AI algorithms, including BFS, DFS, UCS, Iterative Deepening, and an unbeatable mode using Minimax with Alpha-Beta Pruning.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [AI Algorithm Options](#ai-algorithm-options)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

This Tic Tac Toe game allows players to challenge a computer opponent implemented using different AI algorithms. The game has a graphical user interface created using the GTK library, providing an interactive and visually engaging experience. Users can select between various search algorithms for the computer's moves, allowing exploration of how each algorithm approaches decision-making in the game.

## Features

- **Graphical User Interface**: Built with GTK for an interactive gameplay experience.
- **Multiple AI Algorithms**:
  - **BFS** (Breadth-First Search)
  - **DFS** (Depth-First Search)
  - **UCS** (Uniform-Cost Search)
  - **Iterative Deepening**
  - **Unbeatable** (Minimax with Alpha-Beta Pruning)
- **Play Again Option**: Easily restart the game after each match without restarting the application.
- **Continuous Gameplay**: The game doesn’t end after the computer wins, allowing the player to keep interacting with the board until they choose to restart.

## Installation

### Prerequisites

- **GTK 3**: Ensure GTK 3 is installed on your system. You can install it on Ubuntu with:
  ```bash
  sudo apt-get install libgtk-3-dev
  ```
- **CMake**: To build the project. Install it on Ubuntu with:
  ```bash
  sudo apt-get install cmake
  ```

### Build Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Ahmedvini/Tic-Tac-Toe-using-AI-Algorithms
   ```

2. **Compile the Project**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Game**:
   ```bash
   ./TicTacToe
   ```

## Usage

Upon launching the application:
1. **Select an Algorithm**: Use the dropdown menu to select one of the AI algorithms (BFS, DFS, UCS, Iterative Deepening, or Unbeatable).
2. **Play the Game**:
   - Click on an empty cell to make your move as the player (X).
   - The computer will respond with its move as O based on the selected algorithm.
3. **Play Again**:
   - After each game, click "Play Again" to reset the board and start a new match.
   - The game status will indicate results like "You win!", "Computer wins!", or "It's a draw!"

## AI Algorithm Options

Each algorithm presents a different approach to how the computer decides its moves:

1. **BFS (Breadth-First Search)**:
   - Explores the board layer by layer, making moves sequentially from the top left to the bottom right.
   
2. **DFS (Depth-First Search)**:
   - Searches deeply into the board from bottom-right to top-left, finding the last available cell.

3. **UCS (Uniform-Cost Search)**:
   - Uses a basic cost matrix, with cells closer to the center having lower costs, to find the best move.

4. **Iterative Deepening**:
   - Similar to DFS but with a depth limit, allowing iterative exploration while approximating optimal moves.

5. **Unbeatable (Minimax with Alpha-Beta Pruning)**:
   - Utilizes the Minimax algorithm, ensuring optimal moves for an unbeatable experience.

### Choosing an Algorithm

Each algorithm represents a different AI decision-making style. While BFS and DFS are straightforward, UCS considers positional costs, and Iterative Deepening improves on DFS by refining search depth. The Unbeatable mode with Minimax is the most challenging for the player.

## Project Structure

```plaintext
tic-tac-toe-ai/
├── src/
│   ├── main.c                   # Entry point, initializes GTK and creates GUI
│   ├── gui.c                    # GUI components and event handling
│   ├── board.c                  # Board logic and game state management
│   ├── computer_move.c          # AI algorithms and move decision logic
│   ├── gui.h                    # GUI-related function declarations
│   ├── board.h                  # Board structure and function declarations
│   └── computer_move.h          # AI algorithms function declarations
├── CMakeLists.txt               # CMake build configuration
└── README.md                    # Project documentation
```

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## License

This project is open-source and available under the MIT License.
