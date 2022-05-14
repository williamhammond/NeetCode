#include "Sudoku.h"
#include <set>
#include<string>

bool Sudoku::solve(std::vector<std::vector<char>> &board) {
    std::size_t n = 9;
    std::set<std::string> seen;
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            std::string number = std::string(1, board[i][j]);
            if (number != ".") {
                std::string row = number + "-row-" + std::to_string(i);
                std::string col = number + "-col-" + std::to_string(j);
                std::string block = number + "-block-" + std::to_string(i / 3) + "-" + std::to_string(j / 3);
                if (seen.count(row) > 0 || seen.count(col) > 0 || seen.count(block) > 0) {
                    return false;
                }
                seen.insert(row);
                seen.insert(col);
                seen.insert(block);
            }
        }
    }
    return true;
}
