/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        bool hasContL = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                absentCount++;
            }
            if (i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') {
                hasContL = true;
            }
        }
        return absentCount <= 1 && !hasContL;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
    cout << s.checkRecord("") << endl;
    return 0;
}
