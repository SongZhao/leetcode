/*
Implement int sqrt(int x).

Compute and return the square root of x.

*/

/*
 * Binary search. Be care of overflow. Don't use start + end or mid * mid
*/

#include "helper.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int start = 1, end = x;
        while (end > start + 1) {
            int mid = (end - start) / 2 + start;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(2147395599) << endl;
    cout << s.mySqrt(1) << endl;
    cout << s.mySqrt(2) << endl;
    cout << s.mySqrt(3) << endl;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(10) << endl;
    cout << s.mySqrt(2147395599) << endl;
    return 0;
}
