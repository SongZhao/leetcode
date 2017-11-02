/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/*
 * Similar to Add Two Numbers
*/

#include "helper.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() > num2.length()) {
            swap(num1, num2);
        }
        string res;
        int c = 0;
        int diff = num2.length() - num1.length();

        for (int i = num1.length() - 1; i >= 0; i--) {
            c += int(num1[i] - '0') + int(num2[i + diff] - '0');
            res += char(c % 10 + '0');
            c /= 10;
        }

        for (int i = diff - 1; i >= 0; i--) {
            c += int(num2[i] - '0');
            res += char(c % 10 + '0');
            c /= 10;
        }
        if (c == 1) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addStrings("11", "999990") << endl;
    cout << s.addStrings("11", "99") << endl;
    cout << s.addStrings("11", "0") << endl;

    return 0;
}
