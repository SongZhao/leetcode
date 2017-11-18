/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, "", 0);
        return res;
    }

    void helper(vector<string> &res, int n, const string &cur, int leftNum) {
        if (cur.length() == n * 2) {
            res.push_back(cur);
        }
        if (leftNum < n) {
            helper(res, n, cur + '(', leftNum + 1);
        }
        if (cur.length() - leftNum < n && leftNum > cur.length() - leftNum) {
            helper(res, n, cur + ')', leftNum);
        }
    }
};

int main() {
    Solution s;
    cout << s.generateParenthesis(1) << endl;
    cout << s.generateParenthesis(2) << endl;
    cout << s.generateParenthesis(3) << endl;
    return 0;
}
