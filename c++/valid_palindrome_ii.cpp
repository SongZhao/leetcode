/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool validPalindrome(string s) {
        int l = -1, r = s.length();
        while (++l < --r)
            if (s[l] != s[r]) {
                return isValid(s, l, r+1) || isValid(s, l-1, r);
            }
        return true;
    }

    bool isValid(string s, int l, int r) {
        while (++l < --r)
            if (s[l] != s[r]){
                return false;
            }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("abc") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abcca") << endl;
    cout << s.validPalindrome("abccd") << endl;

    return 0;
}
