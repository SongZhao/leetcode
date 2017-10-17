/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
 */

/*
 * backtrack
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        if (target < 0 || candidates.empty()) {
            return res;
        }
        helper(res, cur, candidates, 0, target, 0);
        return res;
    }

    void helper(vector<vector<int>> &res, vector<int> &cur, const vector<int> &candidates, int sum, int target, int start) {
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            sum += candidates[i];
            helper(res, cur, candidates, sum, target, i);
            sum -= cur.back();
            cur.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<int> candidates({2, 3, 6, 7});
    int target = 7;
    cout << s.combinationSum(candidates, target) << endl;
    return 0;
}
