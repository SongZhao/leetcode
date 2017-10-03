/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
 * Simple dynamic programing.
*/

#include "helper.h"

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];

        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid;
    vector<int> row;
    row = {1, 2, 3};
    grid.push_back(row);
    row = {4, 5, 6};
    grid.push_back(row);
    row = {7, 8, 9};
    grid.push_back(row);
    cout << s.minPathSum(grid) << endl;
    return 0;
}
