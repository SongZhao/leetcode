/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

/*
 * backtrack
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(cur);
        helper(res, cur, nums, 0);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &cur, const vector<int> &nums, int start) {
        if (nums.size() == start) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            res.push_back(cur);
            helper(res, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<int> nums({1, 2, 3});
    cout << s.subsets(nums) << endl;
    return 0;
}
