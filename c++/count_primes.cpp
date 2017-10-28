/*
Count the number of prime numbers less than a non-negative number, n.

*/

/*
 * if i is a prime, then i * j (j>2) is not a prime. Use an array to save prime/non-prime lists
*/

#include "helper.h"

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimes[i]) {
                res++;
                for (int j = 2; i * j < n;j++) {
                    isPrimes[i * j] = false;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(8) << endl;
    return 0;
}
