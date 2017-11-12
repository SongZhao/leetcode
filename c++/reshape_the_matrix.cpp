/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different
 size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the
 row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise,
 output the original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/

/*
 * greedy, two iterates two make sure the requirements are satisfied.
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (nums.empty() || nums[0].empty() || nums.size() * nums[0].size() != r * c) {
            return nums;
        }
        vector<vector<int>> res;
        int count = 0;
        vector<int> row;
        for (auto &v:nums) {
            for (int num:v) {
                if (count < c) {
                    row.push_back(num);
                    count++;
                }
                if (count == c) {
                    res.push_back(row);
                    count = 0;
                    row.clear();
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> row;
    vector<vector<int>> nums;
    row = {1, 2};
    nums.push_back(row);
    row = {3, 4};
    nums.push_back(row);
    cout << s.matrixReshape(nums, 1, 4) << endl;
    return 0;
}
