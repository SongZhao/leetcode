/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

/*
 * backtrack, similar to Combination Sum II and Subsets II
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> isVisited(nums.size(), false);
        sort(nums.begin(), nums.end());
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
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }

        }
    }
};


int main() {
    Solution s;
    vector<int> nums({1, 1, 2});
    cout << s.permuteUnique(nums) << endl;
    return 0;
}
