/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display
 this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }

        vector<string> strs(nRows);
        string res;

        int row = 0, step = 1;
        for (char c: s) {
            strs[row].push_back(c);
            if (row == 0) {
                step = 1;
            } else if (row == nRows - 1) {
                step = -1;
            }
            row += step;
        }

        for (int j = 0; j < nRows; ++j) {
            res.append(strs[j]);
        }

        return res;
    }
};


int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;

    return 0;
}
