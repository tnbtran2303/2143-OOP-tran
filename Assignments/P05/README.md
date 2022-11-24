### P03B - BolNiverse Fight Club
### Ngoc Bao Tran Tran
### Description:

### Files

|   #   | File            | Description                                        |\par
| :---: | --------------- | -------------------------------------------------- |
|   1   | main.cpp        | Main driver of my project that launches game.      |
|   2   | helpers.hpp     | Header part that handle vector and choose random item  |
|   3   | dice.hpp        | Header part that contains Die and Dice class          |
|   4   | fighter.py      | Header part that contains BaseFighter class               |
|   5   | weapon.hpp      | Header part that contains Weapon class               |

### Instructions

- Make sure you have g++ compiler installed on your machine\par
- First of all, you have to compile the program by typing the following command with two parameters as follow in the terminal:
```
g++ <source file name> -o <build file name>
```
- After compiling, run the program by typing the name of the file you have built previously:
```
./<build file name>
```
- My program expects input file named `input.dat.txt` when you run the program.
- The input file should be formatted with a fighters name on a seperate line:

+------------+
| warrior    |
| wizard     |
| elf        |
| wizard     |
| dragonborn |
| etc...     |
+------------+

- Example Command:
  - ```g++ main.cpp -o Vector```
  - ```./Vector```
}

