# Assignment 3 - Coup

### Academic Integrity

During the work on the assignments, you are allowed to consult with other students and search for information online. However, it is strictly forbidden to copy entire code segments from external sources, including other students, websites, and AI models (such as ChatGPT).

You must report any help you received, whether it was consulting with other students or information found online, according to the [Department's Academic Integrity Guidelines](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).
**If you use any AI tools, you must attach the prompts you entered and the answers you received.**

-----
* **Assignment Goal:** Understanding the material taught in lectures 5 and 6, such as: the Rule of Three, virtual inheritance, and regular inheritance.
* **Submission is individual**.

----

## Submission Instructions in Moodle:

In the Moodle system, you must submit a **text file (e.g., `submission.txt`)** containing 3 lines in the following format:

1. **ID Number** – The student's ID number.
2. **Submission Link** – A link to the GitHub repository containing the project.
3. **Last Commit Details** – The string identifier of the last commit (`commit hash`).

 - Example of a valid submission file:
```
123456789
https://github.com/example-user/my-assignment
e3f1c1a 
```

---

Coup is a board game for 2-6 players who compete against each other to be the last one standing.
In this assignment, you will implement part of the game rules.

---
## Game Rules
At the beginning of the game, each player draws a card from the deck. Each card describes a role that the player can perform. In the center of the table, there is a pool of coins. Each player, on their turn, plays according to their role (details of the roles below) and can take coins accordingly. The goal of the game is to carry out "coups" and eliminate other players from their roles. The last player remaining with a role wins.

- Each player has a name, a role, and coins.
On each turn, a player, regardless of their role, can perform one of the following actions:

- **Gather** - The player receives one coin from the pool. This action has no cost and can be blocked by a sanction.
- **Tax** - The player receives two coins from the pool. This action costs nothing, but certain roles or actions can block it.
- **Bribe** - The player pays 4 coins to perform an additional action in their turn.
- **Arrest** - The player chooses another player and takes one coin from them. This action cannot be used on the same player twice in a row.
- **Sanction** - The player chooses another player and prevents them from using economic actions (gather, tax) until their next turn. The cost of this action is 3 coins.
- **Coup** - The player chooses another player and eliminates them completely from the game. This action costs 7 coins and can only be blocked under certain conditions.

Each action should update the number of coins the player holds accordingly.
If the action is illegal, you must throw an appropriate exception.

---

#### Roles
The game has several roles, each with unique abilities:

- **Governor** - Takes 3 coins from the pool instead of 2 when using the tax action. Additionally, can cancel the tax action of other players.
- **Spy** - Can see the number of coins another player has and prevent them from using the arrest action on their next turn. This action costs no coins and does not count as a turn.
- **Baron** - Can "invest" 3 coins and receive 6 coins in return. Additionally, if attacked with a sanction, receives one coin as compensation (i.e., from the whole process, can lose at most one coin if using tax).
- **General** - Can pay 5 coins to block a coup against another player (or themselves). Note that in this case, the player who performed the coup loses the coins paid. Additionally, if affected by arrest, receives back the coin that was taken.
- **Judge** - Can cancel another player's bribe action, causing them to lose the 4 coins paid. Additionally, if attacked with a sanction, the player who imposed the sanction must pay an extra coin to the pool.
- **Merchant** - If starting a turn with at least 3 coins, receives an extra coin for free. Additionally, if affected by arrest, pays two coins to the pool instead of losing one to another player.

#### Notes:

- There can be two or more players with the same role – nothing special happens in this case.
- If a player has 10 coins at the start of their turn, they must perform a coup that turn.
- Actions that cancel other actions do not have to wait for the acting player's turn and do not waste their turn, but are performed "in real time". In our game, we will not implement "real time" reactions, so implement the following solution:  
A player who performed an action that can be blocked can have their action blocked until their next turn. For example, if a player used the "bribe" action, then a Judge can block the action even though it is not their turn.

#### Game Board
Each game has the players participating, the status of each player, and at the end of the game, the winner. Additionally, the game knows whose turn it is now. Turns are determined by the order players joined the game.

You must implement the following methods:

- **Turn** - `turn` - Print the name of the player whose turn it is now.
- **Active Players** - `players` - The method returns the names of the players currently active in the game.
- **Winner** - `winner` - The method returns the name of the winner. If the game is still ongoing, the method should throw an error.

---

#### Graphical User Interface (GUI) -
Add a graphical interface to your project that allows for a compact display of the game during the demo run. You can assume all players play through the same screen, so it is sufficient for the GUI to display the menu according to the current player's turn.

For this part, you may use the [QT](https://www.qt.io/product/qt6/qml-book/ch17-qtcpp-qtcpp) and [SFML](https://www.sfml-dev.org/) libraries. Of course, you may use other libraries as you see fit.

--- 
#### Additional Requirements:
- Write comprehensive tests and address all possible edge cases!
- For demonstration purposes, a file called ``Demo.cpp`` is attached to demonstrate the game. **Note** that this file is for example purposes only!
- Make sure the repository is public.
- Write your email address at the top of **every** file.
- Write clean, organized, modular, well-documented code, divided into files, and include unit tests for all functions.
- Validate input and throw appropriate exceptions as necessary.
- Add a file with the main function `main` that demonstrates working with the classes and functions you created.
- For your use, the following link [doctest](https://github.com/doctest/doctest) contains more examples of using this library.
- Make sure there are no memory leaks using `valgrind`.
- Also include a `README` file explaining the project, the class and file structure, and any other relevant information.

#### `Makefile`:
Add a `Makefile` to the project with the following commands:
- The command `make Main` – runs the demo file.
- The command `make test` – runs the unit tests.
- The command `make valgrind` – checks for memory leaks using valgrind.
- The command `make clean` - deletes all irrelevant files after running.

Good luck!
