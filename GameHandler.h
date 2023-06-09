#pragma once

#include <vector>
#include <string>
#include <tgbot/tgbot.h>

class GameHandler {
public:
    GameHandler(TgBot::Bot& bot);
    void handleIncomingMessage(TgBot::Message::Ptr message);

private:
    TgBot::Bot& bot;
    std::vector<std::vector<char>> board;
    char currentPlayer;

    bool checkWin();
    void sendInitialBoard(long long chatId);
    void sendUpdatedBoard(long long chatId);
};
