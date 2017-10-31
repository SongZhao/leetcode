/*
Given an integer, write a function to determine if it is a power of two.
 */

/*
 * Similar to power of two except one more check n - 1 is divisible by 3
*/

#include "helper.h"

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && (num - 1) % 3 == 0;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfFour(64) << endl;
    cout << s.isPowerOfFour(8) << endl;
    return 0;
}
