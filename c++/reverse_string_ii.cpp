/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            if (i + k >= s.length()) {
                reverse(s.begin() + i, s.end());
            } else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseStr("abcdefg", 2) << endl;
    cout << s.reverseStr("abcdefg", 12) << endl;
    cout << s.reverseStr("hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl", 39) << endl;
    return 0;
}
