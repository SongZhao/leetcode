/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        while (n != 0) {
            int i = 1;
            while (f(n - 1) < k) {
                i++;
                k -= f(n - 1);
            }
            res.push_back(char(v[i - 1] + '0'));
            v.erase(v.begin() + i - 1);
            n--;
        }

        return res;
    }

    // get factorial of n
    int f(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(5, 20) << endl;

    return 0;
}
