# Chess CLI Game

![C++](https://img.shields.io/badge/C%2B%2B-Game-blue.svg)

## Introduction
This project is a command-line interface (CLI) chess game implemented in C++. It provides a simple and interactive way to play chess directly from the terminal. The game follows standard chess rules, with some exceptions (e.g., castling and en passant are not implemented).

## Features
- Fully interactive CLI-based gameplay
- ASCII symbols representing chess pieces
- Alternating turns between black and white pieces
- Movement restricted to legal chess moves (except castling and en passant)
- Pawn promotion with selectable piece options
- Win condition when a king is captured
- Board rotation for perspective switching
- Simple command-based controls:
    - `exit` - Quit the game
    - `swap` - Rotate the board
    - Move a piece using standard chess notation (e.g., `c2-c4`)

## Project Structure
### Object-Oriented Design:
- Base `Piece` class with derived classes for each chess piece
- `Board` class managing game state and piece placement
- `Side` class organizing pieces by color
- `Game` class handling gameplay logic
- `IO` module for user interaction and board visualization

### Data Structures Used:
- `std::list` for dynamic piece management
- `std::vector<std::string>` for storing possible moves
- `std::wstring` for Unicode-based board rendering
- `bool` flags for tracking game state

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
