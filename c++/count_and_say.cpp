/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        for (int i = 1; i < n; i++) {
            string cur;
            char ch = pre[0];
            int count = 0;
            for (int j = 0; j <= pre.size(); j++) {
                if (pre[j] == ch) {
                    count++;
                } else {
                    cur += to_string(count) + ch;
                    ch = pre[j];
                    count = 1;
                }
            }
            pre = cur;
            cur.clear();
        }
        return pre;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
    return 0;
}
