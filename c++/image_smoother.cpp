/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make
 the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.
 If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        vector<vector<int>> res(M);
        vector<int> v({-1, 0, 1});
        for (int row = 0; row < M.size(); row++) {
            for (int col = 0; col < M[0].size(); col++) {
                int count = 0;
                int sum = 0;
                for (int incR : v) {
                    for (int incC :v) {
                        if (isValid(row + incR, col + incC, M.size(), M[0].size())) {
                            count++;
                            sum += M[row + incR][col + incC];
                        }
                    }
                }
                res[row][col] = sum / count;
            }
        }

        return res;
    }

private:
    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
};

int main() {
    Solution s;
    vector<int> row;
    vector<vector<int>> img;
    row = {1, 1, 1};
    img.push_back(row);
    row = {1, 0, 1};
    img.push_back(row);
    row = {1, 1, 1};
    img.push_back(row);
    cout << s.imageSmoother(img) << endl;

    return 0;
}
