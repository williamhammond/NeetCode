
#include "Codec.h"


Codec::Codec() {
    seperator = "-";
}

Codec::Codec(std::string s) {
    seperator = s;
}

std::string Codec::encode(std::vector<std::string> &strs) {
    std::string encoded = "";
    for (auto str: strs) {
        std::size_t length = str.size();
        encoded += std::to_string(length) + seperator + str;
    }
    return encoded;
}

std::vector<std::string> Codec::decode(std::string s) {
    std::vector<std::string> decoded;
    std::size_t head = 0;
    while (head < s.size()) {
        std::size_t at_pos = s.find_first_of(seperator, head);
        std::size_t len = stoull(s.substr(head, at_pos - head));
        head = at_pos + 1;
        decoded.push_back(s.substr(head, len));
        head += len;
    }

    return decoded;
}
