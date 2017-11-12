/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving
 whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string reverseWords(string s) {
        int last = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + last, s.begin() + i);
                last = i + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;
    cout << s.reverseWords("abc") << endl;

    return 0;
}
