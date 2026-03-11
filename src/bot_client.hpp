#include <iostream>
#include <cpr/cpr.h>


class BotClient {
private:
    std::string base_url_;

public:
    BotClient(const std::string& base_url) : base_url_(base_url) {}

    bool ping() const {
        cpr::Response r = cpr::Get(cpr::Url{base_url_ + "/ping"});

        return r.status_code == 200;
    }

    std::string send(const std::string& message) const {
        cpr::Response r = cpr::Post(
                cpr::Url{base_url_ + "/message"},

                cpr::Payload{{"text", message}}
                );

        if (r.status_code == 200) {
            return r.text;
        } else {
            std::cerr << "Ошибка HTTP: " << r.status_code << "\n";
            return "";
        }
    }

};

