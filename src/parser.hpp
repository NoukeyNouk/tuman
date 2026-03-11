#pragma once

#include <string>
#include "CLI.hpp"

class Parser {
private:
    std::string message_ = "Hello World!!";
    std::string url_ = "http://127.0.0.1:8000";
    CLI::App app_{"tuman"};
    int argc_;
    char** argv_;

public:
    Parser(int argc, char** argv): argc_(argc), argv_(argv) {
        app_.add_option("-m,--message", message_, "Сообщение");
        app_.add_option("-u,--url", url_, "Сайт");
    }

    const std::string& getMessage() const {
        return message_;
    }

    const std::string& getUrl() const {
        return url_;
    }

    int parse() {
        CLI11_PARSE(app_, argc_, argv_);
        return 0;
    }
};

