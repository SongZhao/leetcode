/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
 * Similar to Spiral Matrix
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1, num = 1;

        while (num <= n * n) {
            // Go Right
            for (int j = colBegin; j <= colEnd; j++) {
                res[rowBegin][j] = num++;
            }
            rowBegin++;

            // Go Down
            for (int j = rowBegin; j <= rowEnd; j++) {
                res[j][colEnd] = num++;
            }
            colEnd--;

            if (rowBegin <= rowEnd) {
                // Go Left
                for (int j = colEnd; j >= colBegin; j--) {
                    res[rowEnd][j] = num++;
                }
            }
            rowEnd--;

            if (colBegin <= colEnd) {
                // Go Up
                for (int j = rowEnd; j >= rowBegin; j--) {
                    res[j][colBegin] = num++;
                }
            }
            colBegin++;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.generateMatrix(3) << endl;

    return 0;
}
