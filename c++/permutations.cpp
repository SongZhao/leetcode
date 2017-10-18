/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

/*
 * backtrack
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> isVisited(nums.size(), false);
        helper(res, cur, nums, isVisited);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &cur, const vector<int> &nums, vector<bool> isVisited) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                cur.push_back(nums[i]);
                helper(res, cur, nums, isVisited);
                isVisited[i] = false;
                cur.pop_back();
            }

        }
    }
};


int main() {
    Solution s;
    vector<int> nums({1, 2, 3});
    cout << s.permute(nums) << endl;
    return 0;
}
