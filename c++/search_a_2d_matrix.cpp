/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

/*
 * Convert 2d matrix to 1d binary search. O(log(mn))
*/

#include "helper.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int height = matrix.size(), width = matrix[0].size();
        int start = 0, end = height * width - 1;

        while (end > start) {
            int mid = (start + end) / 2;
            if (getNum(matrix, mid) < target) {
                start = start < height * width - 1 ? mid + 1 : mid;
            } else if (getNum(matrix, mid) > target) {
                end = mid > 0 ? mid - 1 : mid;
            } else {
                return true;
            }
        }
        return getNum(matrix, start) == target || getNum(matrix, end) == target;
    }

    // matrix guarantees not empty
    int getNum(vector<vector<int>> &matrix, int index) {
        int width = matrix[0].size();
        int col = index % width;
        int row = (index - col) / width;
        return matrix[row][col];
    }

    bool binarySearch(vector<int> nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int start = 0, end = nums.size() - 1;
        while (end > start) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid < nums.size() - 1 ? mid + 1 : mid;
            } else if (nums[mid] > target) {
                end = mid > 0 ? mid - 1 : mid;
            } else {
                return true;
            }
        }
        return nums[start] == target || nums[end] == target;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    int target = 50;
    cout << s.searchMatrix(matrix, target) << endl;
    matrix = {
            {1},
            {3}
    };
    target = 0;
    cout << s.searchMatrix(matrix, target) << endl;
    return 0;
}
