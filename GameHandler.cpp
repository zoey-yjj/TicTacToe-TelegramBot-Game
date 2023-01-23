#include "GameHandler.h"

GameHandler::GameHandler(TgBot::Bot& bot) : bot(bot), board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

void GameHandler::handleIncomingMessage(TgBot::Message::Ptr message) {
    // Check if it's a text message
    if (message->text.empty())
        return;

    // Check if it's a command to start the game
    if (message->text == "/startgame") {
        // Reset the game board
        bot.getApi().sendMessage(message->chat->id, "Game is started!!");
    }
}