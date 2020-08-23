#include <vector>


class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        backtrack(board);
    }

private:
    std::vector<char> choices{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    bool backtrack(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (auto& choice : choices) {
                        if (isValid(board, i, j, choice)) {
                            board[i][j] = choice;
                            if (backtrack(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
        }
        return true;
    }
};