/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        bool isNegtive = false;
        if (num < 0) {
            num = -num;
            isNegtive = true;
        }
        while (num > 0) {
            res += char(num % 7 + '0');
            num /= 7;
        }
        if (isNegtive) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution s;
    cout << s.convertToBase7(100) << endl;
    cout << s.convertToBase7(-7) << endl;
    cout << s.convertToBase7(0) << endl;
    return 0;
}
