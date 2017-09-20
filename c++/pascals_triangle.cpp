/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*
 * Just do the maths
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1);
            res[i][0] = 1;
            res[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int numRows = 5;
    vector<vector<int>> res = s.generate(numRows);
    cout << s.generate(numRows) << endl;
    return 0;
}
