# Coup Game Implementation
This project implements the card game "Coup" where 2-6 players compete to be the last player remaining through strategic actions and role abilities.

## Project Structure
### Core Files
- `Game.cpp/h` - Main game logic and state management
- `Player.cpp/h` - Player class implementation
- `Roles.cpp/h` - Different character roles and their abilities
- `MainWindow.cpp/h` - Main GUI window implementation
- `GameWindow.cpp/h` - Game interface window
- `main.cpp` - Program entry point

## Key Classes & Methods
### Game Class
- `turn()` - Returns name of player whose turn it is
- `players()` - Returns list of active players
- `winner()` - Returns winner's name (throws error if game still active)

### Player Class

#### Core actions:

- `gather()` - Collect 1 coin from treasury
- `tax()` - Collect 2 coins from treasury
- `arrest()` - Take 1 coin from another player
- `sanction()` - Block economic actions of another player (costs 3 coins)
- `bribe()` - Pay 4 coins to take extra action
- `coup()` - Eliminate another player (costs 7 coins)

#### Roles
- Governor - Enhanced tax ability
- General - Can block coups
- Merchant - Gets bonus coins
- Spy - Can see other players' coins

## GUI Interface
The game includes a graphical interface built with Qt6 that shows:
- Current game state
- Active players
- Available actions
- Player resources

## Building & Running

### Prerequisites
- C++ compiler with C++17 support
- Qt6
- CMake 3.16+
Build Commands

```bash
mkdir build
cd build
cmake ..
make
```

### Running
- Main game: `./Coup`
- Tests: `make test`
- Memory check: `make valgrind`
- Clean build: `make clean`
