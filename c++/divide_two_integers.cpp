/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};

int main() {
    Solution s;
    cout << s.divide(10, 4) << endl;

    return 0;
}
