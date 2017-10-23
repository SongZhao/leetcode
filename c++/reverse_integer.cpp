/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

/*
 * Need to handle overflow
*/

#include "helper.h"

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            res = res * 10 + x %10;
            x = x/10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : (int)res;
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    return 0;
}
