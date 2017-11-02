/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes
 that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

/*
 * max len is even count + (odd count - 1) + hasOddCount
*/

#include "helper.h"

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        int odd = 0;
        map<char, int> dict;

        for (char c:s) {
            dict[c]++;
        }
        for (auto &it: dict) {
            if (it.second % 2 == 0)  {
                res += it.second;
            } else {
                odd = 1;
                res += it.second - 1;
            }
        }
        return res + odd;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    cout << s.longestPalindrome("ccc") << endl;

    return 0;
}
