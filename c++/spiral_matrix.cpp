/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;

        if (matrix.empty()) {
            return res;
        }

        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Go Right
            for (int j = colBegin; j <= colEnd; j++) {
                res.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;

            // Go Down
            for (int j = rowBegin; j <= rowEnd; j++) {
                res.push_back(matrix[j][colEnd]);
            }
            colEnd--;

            if (rowBegin <= rowEnd) {
                // Go Left
                for (int j = colEnd; j >= colBegin; j--) {
                    res.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;

            if (colBegin <= colEnd) {
                // Go Up
                for (int j = rowEnd; j >= rowBegin; j--) {
                    res.push_back(matrix[j][colBegin]);
                }
            }
            colBegin++;
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    cout << s.spiralOrder(matrix) << endl;

    return 0;
}
