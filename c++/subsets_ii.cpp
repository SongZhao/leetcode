/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

/*
 * backtrack, similar to 40. Combination Sum II
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(cur);
        sort(nums.begin(), nums.end());
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
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                i++;
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> nums({5, 5, 5, 5, 5});
    cout << s.subsetsWithDup(nums) << endl;
    return 0;
}
