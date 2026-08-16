<img width="1920" height="1054" alt="image" src="https://github.com/user-attachments/assets/67e200bb-b0bd-4194-90a5-984bc12b803a" />
# Terminal Chess - C++ Two-Player Game

A terminal-based chess game built entirely in C++ that allows two players to play chess in the command line interface. This is a small, self-contained project focused on implementing core chess logic without external dependencies.

## Features

- **Complete Chess Rules**: All standard chess rules implemented, including:
  - Legal move validation for all pieces
  - Check and checkmate detection
  - Castling (king-side and queen-side)
  - En passant capture
  - Pawn promotion
  - Stalemate detection
- **Terminal Interface**: Simple ASCII board display with clear visualization
- **Two-Player Local Multiplayer**: Take turns on the same terminal
- **Pure C++ Implementation**: No external libraries or dependencies

## How to Play

1. Clone the repository
2. Compile using any C++ compiler:
   ```bash
   g++ -std=c++11 -o chess *.cpp
   ```
3. Run the executable:
   ```bash
   ./chess
   ```
4. Follow the on-screen prompts to make your moves (e.g., "e2 e4")
 - or you can use numbers from 1 to 64 why bc why not 0]0/(and it might not work check the the the list of the features)

## Requirements

- C++11 or higher
- Terminal with Unicode/ASCII support

## Why This Project?

This project was built as a learning exercise to practice:

- Object-oriented programming in C++
- Game logic implementation
- Data structures and algorithms
- Clean code practices
  
## Features

- [X] display in terminal
- [X] All pieces with movement rules
- [ ] Special moves
- [ ] Check/checkmate detection
- [ ] simple menu
- [ ] Move input using algebraic notation (e.g., e2e4)


## Future Improvements

- [ ] Save/load game state
- [ ] Move history with undo functionality
- [ ] Basic AI opponent
- [ ] Colored terminal output
- [ ] Time controls

---
