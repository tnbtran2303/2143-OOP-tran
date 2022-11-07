## P03 - Black Jack
### Ngoc Bao Tran Tran
### Description:

- In this assignment, we will implement a text-based Black Jack game with a lot of Class and Use case. 
- The game will be played by a single player against a dealer. 
- The player will be able to choose to hit or stand. The dealer will hit until the dealer's hand has value 17 or greater. The player who is closer to 21 without going over wins. 
- If the player goes over 21, the player loses. If the dealer goes over 21, the dealer loses. If both player and dealer have the same value, then it is a tie. 
- The player starts with some amount of money. The player's money goes up and down depending on wins, losses, and ties. 
- The player can quit the game at any time.

### Files

|   #   | File              | Description                                |
| :---: | ----------------- | --------------------------------------------------------------------------------------------- |
|   1   | cardContainer.hpp | contains the prototype and implementation of the containers: base container, deck, hand and shoe |
|   2   | cards.hpp         | contains the class prototype and implementation of card class and blackJackCard class |
|   3   | game.hpp          | contains the main game class, initiate the other classes for the player to start playing |
|   4   | player.hpp        | contains the player related class prototypes and implementation: base player, player and dealer |
|   5   | utilities.hpp     | contains the utility functions for the game |
|   6   | main.cpp          | contains the main function to start the game |
    

### Instructions

- Make sure you have g++ compiler installed on your machine
- First of all, you have to compile the program by typing the following command with two parameters as follow in the terminal:
```
g++ <source file name> -o <build file name>
```
- After compiling, run the program by typing the name of the file you have built previously:
```
./<build file name>
```

- Example Command:
  - ```g++ *.cpp -o main```
  - ```./main```

