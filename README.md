# **Tic-Tac-Toe Game**

This is a simple implementation of the Tic-Tac-Toe game using the Telegram Bot API in C++. It allows users to play Tic-Tac-Toe against each other in a chat conversation.

## **Dependencies**

- C++ Compiler 
- TgBot library 

## **Configuration**

Before running the game, you need to obtain a Telegram Bot API token. Follow these steps to get the token:

1. Create a new bot on Telegram by talking to the BotFather.

1. Obtain the API token for your bot.

1. Open the main.cpp file and replace "YOUR_BOT_TOKEN" with your actual bot token.

## **How to Build**

1. Clone the repository or download the source code.

1. Install the dependencies mentioned above.

1. Open a terminal or command prompt and navigate to the project directory.

1. Run the following command to build the project:

    ```
    make
    ```

1. The executable named tictactoe will be generated in the current directory.

## **Running the Game**

1. Ensure that the executable tictactoe has execute permissions. If not, run the following command:

    ```
    chmod +x tictactoe
    ```

1. Run the game by executing the following command:

    ```
    ./tictactoe
    ```

1. The game will connect to the Telegram Bot API and start listening for incoming messages.

1. Start a conversation with your bot on Telegram and enjoy playing Tic-Tac-Toe!

## **How to Play**

1. Start the game by sending the command /startgame to the bot.

1. The game board will be displayed, showing a 3x3 grid with numbers representing each cell. Each player takes turns to make a move.

1. To make a move, send a message with the row and column numbers of the desired cell. For example, to place your symbol in the top-center cell, send a message with 1 2.

1. The game will update the board and switch to the other player's turn.

1. Continue making moves until one of the players wins or the game ends in a draw.

1. If a player wins, the game will display a victory message with the winning player's symbol.

1. To start a new game, send the /startgame command again.
