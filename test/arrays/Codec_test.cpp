#include <gtest/gtest.h>
#include "../../src/arrays/public/Codec.h"
#include <vector>

TEST(Codec, serder_empty) {
    Codec codec;
    std::vector<std::string> input = {""};
    std::vector<std::string> result = codec.decode(codec.encode(input));
    EXPECT_EQ(input, result);
}

TEST(Codec, serder_simple) {
    Codec codec;
    std::vector<std::string> input = {"a", "b", "c"};
    std::vector<std::string> result = codec.decode(codec.encode(input));
    EXPECT_EQ(input, result);
}

TEST(Codec, serder_special) {
    Codec codec;
    std::vector<std::string> input = {"␠", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/",
                                      "0", "1", ":", ";" "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{",
                                      "|", "}" "~", "␡"};
    std::vector<std::string> result = codec.decode(codec.encode(input));
    EXPECT_EQ(input, result);
}

TEST(Codec, serder_control) {
    Codec codec;
    std::vector<std::string> input = {
            "␁", "␂", "␃", "␄", "␅", "␆", "␇", "␈", "␉", "␊", "␋", "␌", "␍", "␎", "␏", "␐", "␑", "␒", "␓", "␔",
            "␕", "␖", "␗", "␘", "␙", "␚", "␛", "␜", "␝", "␞", "␟", "␠"
    };
    std::vector<std::string> result = codec.decode(codec.encode(input));
    EXPECT_EQ(input, result);
}

TEST(Codec, serder_extended) {
    Codec codec;
    std::vector<std::string> input = {
            "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "", "", "", "", " ", "¡", "¢", "£", "¤", "¥", "¦", "§", "¨", "©",
            "ª", "«", "¬", "­", "®", "¯", "°", "±", "²", "³", "´", "µ", "¶", "·", "¸", "¹", "º", "»", "¼", "½", "¾",
            "¿", "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó",
            "Ô", "Õ", "Ö", "×", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "Þ", "ß", "à", "á", "â", "ã", "ä", "å", "æ", "ç", "è",
            "é", "ê", "ë", "ì", "í", "î", "ï", "ð", "ñ", "ò", "ó", "ô", "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ý",
            "þ", "ÿ"
    };
    std::vector<std::string> result = codec.decode(codec.encode(input));
    EXPECT_EQ(input, result);
}