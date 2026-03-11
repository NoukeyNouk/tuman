#include <iostream>

#include "parser.hpp"
#include "bot_client.hpp"

int main(int argc, char** argv) {
    Parser psr(argc, argv);

    psr.parse();

    BotClient bot(psr.getUrl());
    std::cout << bot.send(psr.getMessage()) << "\n";

    std::cout << "flag -m " << psr.getMessage() << "\n";

    return 0;
}
