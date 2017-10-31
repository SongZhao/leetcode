/*
Given an integer, write a function to determine if it is a power of three.
 Follow up:
Could you do it without using any loop / recursion?
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 1) {
            while ( n != 1 && n % 3 == 0) {
                n /= 3;
            }
        }
        return n == 1;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(81) << endl;
    cout << s.isPowerOfThree(3) << endl;
    cout << s.isPowerOfThree(6) << endl;

    return 0;
}
