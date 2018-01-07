/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            int first = s[i - 1] - '0';
            int second = (s[i - 2] - '0') * 10 + first;
            if (first >= 1 && first <= 9) {
                dp[i] += dp[i - 1];
            }
            if (second >= 10 && second <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("234") << endl;
    cout << s.numDecodings("10") << endl;

    return 0;
}
