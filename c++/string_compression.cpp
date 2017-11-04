/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?

Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

 */

/*
 * Use a pair to keep previous char and count
*/

#include "helper.h"

class Solution {
public:
    int compress(vector<char> &chars) {
        int res = 0;
        if (chars.empty()) {
            return 0;
        }
        int pos = 0;
        pair<char, int> p({chars[0], 0});
        for (int i = 0; i <= chars.size(); i++) {
            if (p.first == chars[i] && i != chars.size()) {
                p.second++;
            } else {
                res++;
                chars[pos++] = p.first;
                p.first = chars[i];
                int tmp = p.second;
                p.second = 1;
                if (tmp != 1) {
                    string s = to_string(tmp);
                    while (tmp) {
                        res += 1;
                        tmp /= 10;
                    }
                    for (char c:s) {
                        chars[pos++] = c;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<char> chars;
    chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    cout << s.compress(chars) << endl;
    cout << chars << endl;
    chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << s.compress(chars) << endl;
    cout << chars << endl;
    chars = {'a'};
    cout << s.compress(chars) << endl;
    cout << chars << endl;
    chars = {'a', 'b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << s.compress(chars) << endl;
    cout << chars << endl;
    return 0;
}
