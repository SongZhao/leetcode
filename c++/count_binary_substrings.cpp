/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's,
 and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/

/*
 * dfs
*/

#include "helper.h"

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, pre = 0, cur = 1;
        for (int i = 1;i<s.length();i++) {
            if (s[i] == s[i-1]) {
                cur++;
            } else {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(pre, cur);
    }
};


int main() {
    Solution s;
    cout << s.countBinarySubstrings("00110011") << endl;
    cout << s.countBinarySubstrings("10101") << endl;

    return 0;
}
