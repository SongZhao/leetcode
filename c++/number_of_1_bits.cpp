/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */

/*
 * Simple
*/

#include "helper.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n > 0) {
            sum += n & 1;
            n >>= 1;
        }
        return sum;
    }
};

int main() {
    Solution s;
    uint32_t n = 11;
    cout << s.hammingWeight(n) << endl;
    n = 1024;
    cout << s.hammingWeight(n) << endl;
    return 0;
}
