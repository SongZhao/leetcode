/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

/*
 * Convert it to a histogram that can use largestRectangleArea in previous question
*/

#include "helper.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int max = 0;
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = i == 0 ? 1 : heights[i - 1][j] + 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            max = std::max(largestRectangleArea(heights[i]), max);
        }
        return max;
    }

    int largestRectangleArea(vector<int> &heights) {
        vector<int> stack;
        int max = 0, i = 0;
        heights.push_back(0);
        while (i < heights.size()) {
            int t = stack.empty() ? -1 : stack.back();
            if (stack.empty() || heights[i] >= heights[stack.back()]) {
                stack.push_back(i++);
            } else {
                int index = stack.back();
                stack.pop_back();
                int width = stack.empty() ? i : i - stack.back() - 1;
                if (heights[index] * width > max) {
                    max = heights[index] * width;
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout << s.maximalRectangle(matrix) << endl;
    matrix = {
            {'1', '0'}
    };
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
