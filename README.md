# CPP_EX3
### This project is implementation of the "COUP" game in C++

In this project we focused on Inheritance, Polymorphism and GUI in C++.

## compilation 
To compile the project, you can use the following commands:
```bash
sudo apt install libsfml-dev    #install SFML library
make                            #compile the project
make test                       #compiles the tests executable and runs the tests
make Main                       #runs the main program
make valgrind                   #runs valgrind on the main program
make valgrind-test              #runs valgrind on the tests
make clean                      #Deletes all .o files

```
## In this project I had to implement the following:
- The game logic of the "COUP" game, including the rules and mechanics.
- A graphical user interface (GUI) using the SFML library to display the game state and allow user interaction.
- Unit tests to ensure the correctness of the game logic and GUI components.

## Guide to the game:
- The game is controlled by the mouse, you need to use the keyboard only to enter your name.
- To set your name, click on the "CHOOSE A ROLE CARD" button.
- To start the game, click on the "START GAME" button.
- To perform an action, click on the green buttons in the GUI.
- If you chose action that you make on another player, you need to click on the player you want to perform the action on.

## Author
- Name: Ronen Chereshnya
- ID: 207304338
- Email: ronen.chereshn@msmail.ariel.ac.il