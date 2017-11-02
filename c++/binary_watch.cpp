/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 */

/*
 * backtrack. Ugly code...
*/

#include "helper.h"

class Solution {
public:
    typedef std::bitset<10> TenBits;

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        TenBits bits;

        generateTime(res, bits, 0, num);
        return res;
    }

    void generateTime(vector<string> &res, TenBits &bits, int cur, int num) {
        if (cur > 10) {
            return;
        }
        string time;

        if (bits.count() == num) {
            time = readTime(bits);
            if (!time.empty()) {
                res.push_back(time);
            }
        }

        for (int i = cur; i< 10;i++) {
            bits.set(i, true);
            generateTime(res, bits, i + 1, num);
            bits.set(i, false);
        }

    }

    string readTime(const TenBits &bits) {
        int i_minute = bits[0] + 2 * bits[1] + 4 * bits[2] + 8 * bits[3] + 16 * bits[4] + 32 * bits[5];
        if (i_minute >= 60) {
            return "";
        }
        string s_minute = i_minute < 10 ? '0' + to_string(i_minute) : to_string(i_minute);

        int i_hour = bits[6] + 2 * bits[7] + 4 * bits[8] + 8 * bits[9];
        if (i_hour >= 12) {
            return "";
        }
        string s_hour = to_string(i_hour);
        return s_hour + ':' + s_minute;
    }
};

int main() {
    Solution s;
    cout << s.readBinaryWatch(2) << endl;
    return 0;
}
