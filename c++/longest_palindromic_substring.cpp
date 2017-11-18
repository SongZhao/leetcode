/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
 * Expand from middle
*/

#include "helper.h"

class Solution {
    int maxLen = 0;
    string res;
public:
    string longestPalindrome(string s) {
        maxLen = 0;
        res = "";
        for (int i = 0; i < s.length(); i++) {
            helper(s, i, 1 , i-1, i+1); // for case aba
            helper(s, i, 0, i-1, i);    // for case aa

        }
        return res;
    }

    void helper(const string &s, int pos, int init, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            init += 2;
        }
        if (init > maxLen) {
            maxLen = init;
            res = s.substr(left + 1, init);
        }
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("aa") << endl;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;

    return 0;
}
