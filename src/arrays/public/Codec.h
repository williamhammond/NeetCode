
#ifndef NEETCODE_CODEC_H
#define NEETCODE_CODEC_H

#include<string>
#include<vector>

class Codec {

public:
    Codec();

    Codec(std::string seperator);

    std::string encode(std::vector<std::string> &strs);

    std::vector<std::string> decode(std::string s);

private:
    std::string seperator;

};


#endif //NEETCODE_CODEC_H
