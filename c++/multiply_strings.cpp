/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

/*
   123
    45
   ---
    15 +
   10  +
   5   +
   12  +
   8   +
  4

 */

#include "helper.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> v(num1.size() + num2.size());
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + v[p2];

                v[p1] += sum / 10;
                v[p2] = (sum) % 10;
            }
        }
        string res;
        for (int i:v) {
            if (res.empty() && i == 0) {
                continue;
            }
            res.push_back(char(i + '0'));
        }
        return res.empty() ? "0" : res;
    }
};


int main() {
    Solution s;
    cout << s.multiply("45", "123");

    return 0;
}
