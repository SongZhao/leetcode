/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c = 0, i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            res += (char)('0' + c % 2);
            c /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("111", "1") << endl;
    return 0;
}
