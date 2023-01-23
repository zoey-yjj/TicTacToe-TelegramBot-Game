#include <iostream>
#include <tgbot/tgbot.h>
#include "GameHandler.h"

int main() {
    // Telegram Bot API token
    std::string botToken = "YOUR_BOT_TOKEN";

    // Create a bot object
    TgBot::Bot bot(botToken);

    // Create a game handler object
    GameHandler gameHandler(bot);

    // Set the function to handle incoming messages
    bot.getEvents().onAnyMessage([&gameHandler](TgBot::Message::Ptr message) {
        gameHandler.handleIncomingMessage(message);
    });

    // Run the bot
    try {
        bot.getApi().deleteWebhook();
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "Telegram Bot Exception: " << e.what() << std::endl;
    }

    return 0;
}
