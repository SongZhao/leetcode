/*
Given an integer, write a function to determine if it is a power of two.
 */

/*
 * If it's power of two, n & (n-1) should be 0. for example, 1000 & 111 = 0
*/

#include "helper.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

int main() {
    Solution s;
    int n = 1024;
    cout << s.isPowerOfTwo(n) << endl;
    n = 1023;
    cout << s.isPowerOfTwo(n) << endl;
    return 0;
}
