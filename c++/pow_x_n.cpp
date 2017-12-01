/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/

/*
 * Check INT_MIN
*/

#include "helper.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            if (n == INT_MIN) {
                return 1 / (x * myPow(x, -(n+1)));
            }
            return 1 / myPow(x, -n);
        } else {
            return n % 2 ? x * myPow(x * x, n/2): myPow(x * x, n/2);
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(2, 10) << endl;
    cout << s.myPow(2, -10) << endl;
    cout << s.myPow(2.1, 3) << endl;
    cout << s.myPow(1, -2147483648) << endl;
    return 0;
}
