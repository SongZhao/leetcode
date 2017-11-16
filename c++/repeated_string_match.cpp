/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 0;
        string s = A;
        while (s.length() < B.length()) {
            s.append(A);
            i++;
        }

        if (s.find(B) != string::npos) {
            return i + 1;
        }
        if (s.append(A).find(B) != string::npos) {
            return i + 2;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.repeatedStringMatch("a", "aa") << endl;
    cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
    return 0;
}
