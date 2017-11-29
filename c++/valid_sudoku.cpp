/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

/*
 * Find smallest number first, then binary search
*/

#include "helper.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = true;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<vector<char>> board = {{'.','8','7','6','5','4','3','2','1'}, {'2','.','.','.','.','.','.','.','.'},
                                  {'3','.','.','.','.','.','.','.','.'}, {'4','.','.','.','.','.','.','.','.'},
                                  {'5','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.'},
                                  {'7','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.'},
                                  {'9','.','.','.','.','.','.','.','.'}};
    cout << s.isValidSudoku(board);
    
    return 0;
}
