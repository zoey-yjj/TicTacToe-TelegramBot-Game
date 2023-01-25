#include "GameHandler.h"

GameHandler::GameHandler(TgBot::Bot& bot) : bot(bot), board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

void GameHandler::handleIncomingMessage(TgBot::Message::Ptr message) {
    // Check if it's a text message
    if (message->text.empty())
        return;

    // Check if it's a command to start the game
    if (message->text == "/startgame") {
        // Reset the game board
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));

        // Send the initial game board
        sendInitialBoard(message->chat->id);
    }

    // Check if it's a move command
    else if (message->text.length() == 3 && 
             message->text[0] >= '1' && message->text[0] <= '3' &&
             message->text[1] == ' ' && 
             message->text[2] >= '1' && message->text[2] <= '3') {
        int row = message->text[0] - '1';
        int col = message->text[2] - '1';

        // Check if the move is valid
        if (board[row][col] == ' ') {
            // Make the move
            board[row][col] = currentPlayer;

            // Switch the player turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

            // Send the updated game board
            sendUpdatedBoard(message->chat->id);
        } else {
            // Invalid move
            bot.getApi().sendMessage(message->chat->id, "Invalid move! Please try again.");
        }
    }
}

void GameHandler::sendInitialBoard(long long chatId) {
    std::string gameBoard = "Let's play Tic-Tac-Toe!\n\n"
                            "To make a move, use the format 'row column'. For example, '1 2' represents the top "
                            "center cell.\n\n" + std::string("Game Board:\n") +
                            "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        gameBoard += std::to_string(i + 1) + " ";
        for (int j = 0; j < 3; j++) {
            gameBoard += board[i][j];
            if (j < 2)
                gameBoard += " | ";
        }
        gameBoard += "\n";
        if (i < 2)
            gameBoard += "  -------------\n";
    }

    // Send the initial game board
    bot.getApi().sendMessage(chatId, gameBoard);
}

void GameHandler::sendUpdatedBoard(long long chatId) {
    std::string gameBoard = "Player " + std::string(1, currentPlayer) + "'s turn\n\n" 
                            "Game Board:\n"
                            "  1   2   3\n";
    for (int i = 0; i < 3; i++) {
        gameBoard += std::to_string(i + 1) + " ";
        for (int j = 0; j < 3; j++) {
            gameBoard += board[i][j];
            if (j < 2)
                gameBoard += " | ";
        }
        gameBoard += "\n";
        if (i < 2)
            gameBoard += "  -------------\n";
    }

    // Send the updated game board
    bot.getApi().sendMessage(chatId, gameBoard);
}
