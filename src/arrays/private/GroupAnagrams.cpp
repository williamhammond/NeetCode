#include "arrays/public/GroupAnagrams.h"

std::vector<std::vector<std::string>> GroupAnagrams::solve(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto &str: strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());
        if (groups.count(sorted)) {
            groups[sorted].push_back(str);
        } else {
            groups[sorted] = {str};
        }
    }

    std::vector<std::vector<std::string>> result = {};
    for (auto it = groups.begin(); it != groups.end(); it++) {
        std::vector<std::string> group = it->second;
        result.push_back(it->second);
    }

    return result;
}
