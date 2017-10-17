/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
 */

/*
 * backtrack
*/

#include "helper.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        if (target < 0 || candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        helper(res, cur, candidates, 0, target, 0);
        return res;
    }

    void
    helper(vector<vector<int>> &res, vector<int> &cur, const vector<int> &candidates, int sum, int target, int start) {
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
            helper(res, cur, candidates, sum, target, i + 1);
            sum -= cur.back();
            cur.pop_back();
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> candidates({10, 1, 2, 7, 6, 1, 5});
    int target = 8;
    cout << s.combinationSum2(candidates, target) << endl;
    return 0;
}
