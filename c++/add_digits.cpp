/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
 */

/*
 * return 1 + (num - 1) % 9 if not using loop
*/

#include "helper.h"

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = 0;
            while (num) {
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};

int main() {
    Solution s;
    cout << s.addDigits(10) << endl;
    return 0;
}
