/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

/*
 * Dynamic programing. Similar to Unique Paths but added checking obstacle. Pay attention to initialize.
*/

#include "helper.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];

        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = ((dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0);
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = ((dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0) ? 1 : 0);
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid;
    vector<int> row;
    row = {0, 0, 0};
    obstacleGrid.push_back(row);
    row = {0, 1, 0};
    obstacleGrid.push_back(row);
    row = {0, 0, 0};
    obstacleGrid.push_back(row);
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
