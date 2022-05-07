#include "arrays/public/ValidAnagram.h"

#include<unordered_map>

bool ValidAnagram::solve(std::string s, std::string t) {
    if (s.length() != t.length()) return false;
    std::size_t n = s.length();
    std::unordered_map<char, int> counts;
    for (std::size_t i = 0; i < n; i++) {
        counts[s[i]]++;
        counts[t[i]]--;
    }
    for (auto count: counts) {
        if (count.second) return false;
    }
    return true;
}
