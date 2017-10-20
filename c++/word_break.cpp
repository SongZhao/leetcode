/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be
 segmented into a space-separated sequence of one or more dictionary words.
 You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/*
 * dynamic programming, dp[i] = dp[j] && s.substr(j,i-j) in dict
*/

#include "helper.h"

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                string substring = s.substr(j, i-j);
                if (dp[j] == true && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


int main() {
    Solution s;
    vector<string> wordDict({"le", "et", "code"});
    cout << s.wordBreak("leetcode", wordDict) << endl;
    return 0;
}
