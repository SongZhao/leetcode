/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

/*
 * Pay attention to overflow
*/

#include "helper.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 1, end = num;
        while (end >= start) {
            long mid = (end - start) / 2 + start;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPerfectSquare(808201) << endl;
    cout << s.isPerfectSquare(100) << endl;
    cout << s.isPerfectSquare(99) << endl;
    cout << s.isPerfectSquare(1) << endl;
    cout << s.isPerfectSquare(2) << endl;
    cout << s.isPerfectSquare(3) << endl;
    cout << s.isPerfectSquare(4) << endl;
    cout << s.isPerfectSquare(2147483647) << endl;

    return 0;
}
