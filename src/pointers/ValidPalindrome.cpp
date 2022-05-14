#include "ValidPalindrome.h"
#include <cctype>
#include <functional>

bool ValidPalindrome::solve(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), &ispunct), s.end());
    s.erase(std::remove_if(s.begin(), s.end(), &isspace), s.end());
    for (std::size_t i = 0; i < s.size() / 2; i++) {
        std::size_t j = s.size() - i - 1;
        if (std::tolower(s[i]) != std::tolower(s[j])) {
            return false;
        }
    }
    return true;
}
