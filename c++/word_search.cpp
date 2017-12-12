/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
 or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited;
        visited.resize(row);
        for (auto &it : visited) {
            it.resize(col);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((word[0] == board[i][j]) && search(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(const vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int i, int j,
                int index) {
        if (index == word.length()) {
            return true;
        }

        if (i >= board.size() || i < 0 || j >= board[i].size() || j < 0 || board[i][j] != word[index] ||
            visited[i][j]) {
            return false;
        }

        visited[i][j] = true;
        if (search(board, visited, word, i - 1, j, index + 1) ||
            search(board, visited, word, i + 1, j, index + 1) ||
            search(board, visited, word, i, j - 1, index + 1) ||
            search(board, visited, word, i, j + 1, index + 1)) {
            return true;
        }

        visited[i][j] = false;
        return false;
    }

};

int main() {
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}
    };

    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;

    return 0;
}
