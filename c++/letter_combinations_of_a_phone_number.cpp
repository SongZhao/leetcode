/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

/*
 * backtrack
*/

#include "helper.h"

class Solution {
public:
    map<char, string> mapping;
    Solution() {
        mapping['0'] = "";
        mapping['1'] = "";
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string cur;
        helper(res, cur, digits, 0);
        return res;
    }

    void helper(vector<string> &res, string &cur, const string &digits, int start) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0;i< mapping[digits[start]].size();i++){
                cur.push_back(mapping[digits[start]][i]);
                helper(res, cur, digits, start+1);
                cur.pop_back();
        }
    }
};


int main() {
    Solution s;
    cout << s.letterCombinations("22") << endl;
    return 0;
}
